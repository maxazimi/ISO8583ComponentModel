#ifndef BIT_COMPONENTS_H
#define BIT_COMPONENTS_H

#include "IsoParser.h"
#include "Iso.h"
#include "Component.h"
#include "Helper.h"

class Bit001Component : public Component // not being used
{
  public:
    Bit001Component(class Iso* owner, int processOrder = 1) : Component(owner, 1)
    {
        mProcessOrder = processOrder;
        mData = 0;
    }

    void GetBit() override { Component::GetBit(); }

  private:
    uint64_t mData;
};

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

        printf("mBitSubstr: %s\n", mBitSubstr.c_str());
        mPanSize = std::stoi(mBitSubstr.substr(0, 3));
        mPan = std::stoul(mBitSubstr.substr(3, mPanSize));

        mOwner->SetPan(mPan);
        printf("Pan: %llu\n", mPan);
    }

    uint64_t GetPan() { return mPan; }

  private:
    uint64_t mPan;
    uint32_t mPanSize;
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

        mPrCode[0] = std::stoi(mBitSubstr.substr(0, 2));
        mPrCode[1] = std::stoi(mBitSubstr.substr(2, 2));
        mPrCode[2] = std::stoi(mBitSubstr.substr(4, 2));

        mOwner->SetPrCode(mPrCode);
    }

    std::vector<uint8_t> GetPrCode() { return mPrCode; }

  private:
    std::vector<uint8_t> mPrCode;
};

class Bit004Component : public Component // transaction amount
{
  public:
    Bit004Component(class Iso* owner, int processOrder = 4) : Component(owner, 4)
    {
        mProcessOrder = processOrder;
        mFloatDigits = 0;
        mCurrencyCode = 0;
    }

    void GetBit() override
    {
        Component::GetBit();

        if (mOwner->GetIsoStandard() >= ISO2003_07)
        {
            mCurrencyCode = std::stoul(mBitSubstr.substr(0, 3));
            mFloatDigits = std::stoul(mBitSubstr.substr(3, 1));
            mTxnAmt = std::stoull(mBitSubstr.substr(4, 12));
        }
        else
        {
            mTxnAmt = std::stoull(mBitSubstr);
        }

        mOwner->SetTxnAmount(mTxnAmt, mFloatDigits, mCurrencyCode);
    }

    template <typename T>
    T GetTnxAmt() { return mTxnAmt; }

    template <typename T>
    T GetCurrencyCode()
    {
        if (mOwner->GetIsoStandard() < ISO2003_07)
            throw std::invalid_argument("Item not supported for this ISO version");
        return mCurrencyCode;
    }

  private:
    uint64_t mTxnAmt;

    // ISO2003
    int mCurrencyCode;
    int mFloatDigits;
};

class Bit005Component : public Component
{
  public:
    Bit005Component(class Iso* owner, int processOrder = 5) : Component(owner, 5)
    {
        mProcessOrder = processOrder;
    }

    void GetBit() override { Component::GetBit(); }
    uint64_t Get() { return mData; }

  private:
    uint64_t mData;
};

#endif // BIT_COMPONENTS_H
