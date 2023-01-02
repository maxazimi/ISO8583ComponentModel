#ifndef BIT_COMPONENTS_H
#define BIT_COMPONENTS_H

#include "IsoParser.h"
#include "Iso.h"
#include "Component.h"
#include "Helper.h"

class Bit002Component : public Component // PAN
{
  public:
    Bit002Component(class Iso* owner, int processOrder = 2) : Component(owner, 2)
    {
        mProcessOrder = processOrder;
    }

    void GetBit() override
    {
        Component::GetBit();
        auto pan = std::stoul(mBitSubstr);
        mOwner->SetPan(pan);
    }
};

class Bit003Component : public Component // PrCode
{
  public:
    Bit003Component(class Iso* owner, int processOrder = 3) : Component(owner, 3)
    {
        mProcessOrder = processOrder;
    }

    void GetBit() override
    {
        Component::GetBit();

	    std::vector<uint8_t> mPrCode(3, 0);
        mPrCode[0] = std::stoi(mBitSubstr.substr(0, 2));
        mPrCode[1] = std::stoi(mBitSubstr.substr(2, 2));
        mPrCode[2] = std::stoi(mBitSubstr.substr(4, 2));

        mOwner->SetPrCode(mPrCode);
    }
};

class Bit004Component : public Component // transaction amount
{
  public:
    Bit004Component(class Iso* owner, int processOrder = 4) : Component(owner, 4)
    {
        mProcessOrder = processOrder;
    }

    void GetBit() override
    {
        Component::GetBit();

	    uint64_t mTxnAmt = 0;
	    int mCurrencyCode = 0;
	    int mFloatDigits = 0;

        if (mOwner->GetIsoStandard() >= ISO2003_07)
        {
            mCurrencyCode = std::stoi(mBitSubstr.substr(0, 3));
            mFloatDigits = std::stoi(mBitSubstr.substr(3, 1));
            mTxnAmt = std::stoull(mBitSubstr.substr(4, 12));
        }
        else
        {
            mTxnAmt = std::stoull(mBitSubstr);
        }

        mOwner->SetTxnAmount(mTxnAmt, mFloatDigits, mCurrencyCode);
    }
};

class Bit005Component : public Component
{
  public:
    Bit005Component(class Iso* owner, int processOrder = 5) : Component(owner, 5)
    {
        mProcessOrder = processOrder;
    }

    void GetBit() override { Component::GetBit(); }
};

#endif // BIT_COMPONENTS_H
