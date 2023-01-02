#include "IsoParser.h"
#include "Iso.h"
#include "Component.h"

Component::Component(Iso* owner, int bitNumber) : mOwner(owner), mBitNumber(bitNumber)
{
    mOwner->AddComponent(this);
}

Component::~Component() { mOwner->RemoveComponent(this); }

void Component::GetBit()
{
    size_t substrLen = mBitSpec.size;
    mBitSpec = mOwner->GetBitSpecVec().at(mBitNumber);
    std::string tmpString = mOwner->GetIsoParser()->GetTxnString();

    if (mBitSpec.format != FIXED) // variable length
    {
        substrLen = std::stoul(tmpString.substr(mOwner->GetParseIndex(), mBitSpec.format));
        mOwner->GetParseIndex() += mBitSpec.format;
    }

    mBitSubstr = tmpString.substr(mOwner->GetParseIndex(), substrLen);
    mOwner->GetParseIndex() += substrLen;

    printf("mBitSubstr: %s\nindex: %d\n", mBitSubstr.c_str(), mOwner->GetParseIndex());
}
