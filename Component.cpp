#include "Component.h"
#include "Iso.h"

Component::Component(Iso* owner, int bitNumber) : mOwner(owner)
{
    mBitStrLen = 1;  // as a minimum default value
    mBitStrlVar = 0; // fixed-length by default
    mBitStrMaxLen = mBitStrLen;

    mBitNumber = bitNumber;
    mOwner->AddComponent(bitNumber, this);
}

Component::~Component() { mOwner->RemoveComponent(this); }

void Component::GetBit()
{
    // sub-string size must have been specified by the child component
    std::string tmpString = mOwner->GetIsoParser()->GetTxnString();
    size_t substrLen = mBitStrLen;

    if (mBitStrlVar > 0) // variable length
    {
        substrLen = std::stoul(tmpString.substr(mOwner->GetParseIndex(), mBitStrlVar));
        mOwner->GetParseIndex() += mBitStrlVar;
    }

    mBitSubstr = tmpString.substr(mOwner->GetParseIndex(), substrLen);
    mOwner->GetParseIndex() += substrLen;
}
