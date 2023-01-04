#ifndef BIT_COMPONENTS_H
#define BIT_COMPONENTS_H

#include "IsoParser.h"
#include "Iso.h"
#include "Component.h"
#include "Helper.h"

class Bit002Component : public Component // PAN
{
  public:
    Bit002Component(class Iso* owner, int processOrder = 2) : Component(owner, 2) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();

        auto pan = std::stoul(mBitString);
        mOwner->SetPan(pan);
    }
};

class Bit003Component : public Component // PrCode
{
  public:
    Bit003Component(class Iso* owner, int processOrder = 3) : Component(owner, 3) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();

        std::vector<uint8_t> prCode;
        for (auto& subStr : mSubBitStrVec)
            prCode.emplace_back(std::stoi(subStr));

        mOwner->SetPrCode(prCode);
    }
};

class Bit004Component : public Component // Transaction Amount
{
  public:
    Bit004Component(class Iso* owner, int processOrder = 4) : Component(owner, 4) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();

        auto mTxnAmt = 9999999999999999;
        auto mCurrencyCode = 0;
        auto mFloatDigits = 0;

        if (mSubBitStrVec.size() == 1)
        {
            mTxnAmt = std::stoull(mBitString); // ISO1987
        }
        else if (mSubBitStrVec.size() == 3) //ISO2003
        {
            mCurrencyCode = std::stoi(mSubBitStrVec[0]);
            mFloatDigits = std::stoi(mSubBitStrVec[1]);
            mTxnAmt = std::stoull(mSubBitStrVec[2]);
        }

        mOwner->SetTxnAmount(mTxnAmt, mFloatDigits, mCurrencyCode);
    }
};

class Bit005Component : public Component // Settlement Amount
{
  public:
    Bit005Component(class Iso* owner, int processOrder = 5) : Component(owner, 5) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();

        auto mSettleAmt = 9999999999999999;
        int mCurrencyCode = 0;
        int mFloatDigits = 0;

        if (mSubBitStrVec.size() == 1)
        {
            mSettleAmt = std::stoull(mBitString); // ISO1987
        }
        else if (mSubBitStrVec.size() == 3) //ISO2003
        {
            mCurrencyCode = std::stoi(mSubBitStrVec[0]);
            mFloatDigits = std::stoi(mSubBitStrVec[1]);
            mSettleAmt = std::stoull(mSubBitStrVec[2]);
        }

        mOwner->SetSettlementAmount(mSettleAmt, mFloatDigits, mCurrencyCode);
    }
};

class Bit006Component : public Component // Cardholder Billing Amount
{
  public:
    Bit006Component(class Iso* owner, int processOrder = 6) : Component(owner, 6) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();

        auto mBillAmt = 9999999999999999;
        int mCurrencyCode = 0;
        int mFloatDigits = 0;

        if (mSubBitStrVec.size() == 1)
        {
            mBillAmt = std::stoull(mBitString); // ISO1987
        }
        else if (mSubBitStrVec.size() == 3) //ISO2003
        {
            mCurrencyCode = std::stoi(mSubBitStrVec[0]);
            mFloatDigits = std::stoi(mSubBitStrVec[1]);
            mBillAmt = std::stoull(mSubBitStrVec[2]);
        }

        mOwner->SetBillingAmount(mBillAmt, mFloatDigits, mCurrencyCode);
    }
};

class Bit007Component : public Component // Transmission Date & Time
{
  public:
    Bit007Component(class Iso* owner, int processOrder = 7) : Component(owner, 7) { mProcessOrder = processOrder; }

    void GetBit() override { Component::GetBit(); }
};

class Bit008Component : public Component
{
  public:
    Bit008Component(class Iso* owner, int processOrder = 8) : Component(owner, 8) { mProcessOrder = processOrder; }

    void GetBit() override { Component::GetBit(); }
};

class Bit009Component : public Component // Settlement Conversion Rate
{
  public:
    Bit009Component(class Iso* owner, int processOrder = 9) : Component(owner, 9) { mProcessOrder = processOrder; }

    void GetBit() override { Component::GetBit(); }
};

class Bit010Component : public Component // Cardholder Billing Conversion Rate
{
  public:
    Bit010Component(class Iso* owner, int processOrder = 10) : Component(owner, 10) { mProcessOrder = processOrder; }

    void GetBit() override { Component::GetBit(); }
};

class Bit011Component : public Component // System Trace Audit Number
{
  public:
    Bit011Component(class Iso* owner, int processOrder = 11) : Component(owner, 11) { mProcessOrder = processOrder; }

    void GetBit() override { Component::GetBit(); }
};

class Bit012Component : public Component // Transaction Local Date & Time
{
  public:
    Bit012Component(class Iso* owner, int processOrder = 12) : Component(owner, 12) { mProcessOrder = processOrder; }

    void GetBit() override { Component::GetBit(); }
};

class Bit013Component : public Component
{
  public:
    Bit013Component(class Iso* owner, int processOrder = 13) : Component(owner, 13) { mProcessOrder = processOrder; }

    void GetBit() override { Component::GetBit(); }
};

class Bit014Component : public Component
{
  public:
    Bit014Component(class Iso* owner, int processOrder = 14) : Component(owner, 14) { mProcessOrder = processOrder; }

    void GetBit() override { Component::GetBit(); }
};

class Bit015Component : public Component
{
  public:
    Bit015Component(class Iso* owner, int processOrder = 15) : Component(owner, 15) { mProcessOrder = processOrder; }

    void GetBit() override { Component::GetBit(); }
};

class Bit016Component : public Component
{
  public:
    Bit016Component(class Iso* owner, int processOrder = 16) : Component(owner, 16) { mProcessOrder = processOrder; }

    void GetBit() override { Component::GetBit(); }
};

#endif // BIT_COMPONENTS_H
