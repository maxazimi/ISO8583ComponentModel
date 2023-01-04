#include "IsoParser.h"
#include "Iso.h"
#include "Component.h"

Component::Component(Iso* owner, int bitNumber) : mOwner(owner), mBitNumber(bitNumber) { mOwner->AddComponent(this); }

Component::~Component() { mOwner->RemoveComponent(this); }

void Component::GetBit()
{
    /*
     * Get transaction string
     */
    std::string tmpString = mOwner->GetIsoParser()->GetTxnString();

    mBitSpec = mOwner->GetBitSpecVec().at(mBitNumber);
    auto substrLen = mBitSpec.size;

    if (mBitSpec.format != FIXED) // variable length
    {
        substrLen = std::stoul(tmpString.substr(mOwner->GetParseIndex(), mBitSpec.format));
        mOwner->GetParseIndex() += mBitSpec.format;
    }

    /*
     * Get bit string
     */
    mBitString = tmpString.substr(mOwner->GetParseIndex(), substrLen);
    mOwner->GetParseIndex() += substrLen;

    /*
     * Get sub-bit string
     */
    mSubBitStrVec.clear();
    if (mBitSpec.subSpec.size() != 0)
    {
        int subIndex = 0;
        for (auto& subSpec : mBitSpec.subSpec)
        {
            mSubBitStrVec.emplace_back(mBitString.substr(subIndex, subSpec.size));
            subIndex += subSpec.size;
        }
    }
    else
    {
        /*
         * We consider field string as sub-field 01
         */
        mSubBitStrVec.emplace_back(mBitString);
    }
}
