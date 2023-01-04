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
	std::string tmpString = mOwner->GetIsoParser()->GetTxnString();

    mBitSpec = mOwner->GetBitSpecVec().at(mBitNumber);
	size_t substrLen = mBitSpec.size;

	if (!Helper::CheckFormat(mBitSpec.type, tmpString))
		throw std::logic_error("Field type error");

    if (mBitSpec.format != FIXED) // variable length
    {
        substrLen = std::stoul(tmpString.substr(mOwner->GetParseIndex(), mBitSpec.format));
        mOwner->GetParseIndex() += mBitSpec.format;
    }

    mBitSubstr = tmpString.substr(mOwner->GetParseIndex(), substrLen);
    mOwner->GetParseIndex() += substrLen;
}
