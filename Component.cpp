#include "IsoParser.h"
#include "Iso.h"
#include "Component.h"

Component::Component(Iso* owner, int bitNumber) : mOwner(owner), mBitNumber(bitNumber) { mOwner->AddComponent(this); }

Component::~Component() { mOwner->RemoveComponent(this); }

int Component::CalcTotalSubfieldSize()
{
    if (mBitSpec.format != FIXED && mBitSpec.subSpec.size())
    {
        int totalSize = 0;
        for (auto& subSpec : mBitSpec.subSpec)
        {
            totalSize += subSpec.size;
        }
        return totalSize;
    }
    return mBitSpec.max_size;
}

void Component::GetBit()
{
    /*
     * Get transaction string
     */
    std::string tmpString = mOwner->GetIsoParser()->GetTxnString();

    mBitSpec = mOwner->GetBitSpecVec().at(mBitNumber);
    auto biStrLen = mBitSpec.size;

    if (mBitSpec.format != FIXED) // variable length
    {
        biStrLen = std::stoul(tmpString.substr(mOwner->GetParseIndex(), mBitSpec.format));
        mOwner->GetParseIndex() += mBitSpec.format;
    }

    /*
     * Get bit string
     */
    mBitString = tmpString.substr(mOwner->GetParseIndex(), biStrLen);
    mOwner->GetParseIndex() += biStrLen;

    /*
     * Get sub-bit string
     */
    mSubBitStrVec.clear();
    /*
     * Field either contains no sub-fields
     * or the max size of field is not dividable
     * by the total size of sub-fields.
     */
    if (mBitSpec.subSpec.size() != 0 && CalcTotalSubfieldSize() % biStrLen == 0)
    {
        /*
         * for each repetition of sub-fields
         */
        for (int subIndex = 0; subIndex < mBitSpec.max_size;)
        {
            for (auto& subSpec : mBitSpec.subSpec)
            {
                mSubBitStrVec.emplace_back(mBitString.substr(subIndex, subSpec.size));
                subIndex += subSpec.size;
            }
        }
    }
    else
    {
        /*
         * We consider field string as sub-field-01
         */
        mSubBitStrVec.emplace_back(mBitString);
    }
}
