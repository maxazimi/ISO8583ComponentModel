#ifndef BIT_COMPONENTS_H
#define BIT_COMPONENTS_H

#include <iostream>
#include <vector>

#include "Component.h"
#include "Iso.h"
#include "Helper.h"

class Bit001Component : public Component // not being used
{
  public:
    Bit001Component(class Iso* owner, std::string txnSubStr = "", int processOrder = 1) : Component(owner)
    {
        mBitSubstr = txnSubStr;
        mProcessOrder = processOrder;
    }
    ~Bit001Component() = default;

  private:
    uint64_t mData;
};

class Bit002Component : public Component // PAN
{
  public:
    Bit002Component(class Iso* owner, std::string txnSubStr = "", int processOrder = 2) : Component(owner)
    {
        mBitSubstr = txnSubStr;
        mProcessOrder = processOrder;

        mBitStrLen = 0;
        mBitStrlVar = 2;
		mBitStrMaxLen = 19;
    }
    ~Bit002Component() = default;

	void GetBit() override
	{
		Component::GetBit();
		mPan = std::stoull(mBitSubstr);
	}

    void SetPan(std::string& bitStr)
    {
        mPanSize = std::stoi(bitStr.substr(0, 3));
        mPan = std::stoul(bitStr.substr(3, mPanSize));
    }
    uint64_t GetPan() { return mPan; }

  private:
    uint64_t mPan;
    uint32_t mPanSize;
};

class Bit003Component : public Component
{
  public:
    Bit003Component(class Iso* owner, std::string txnSubStr = "", int processOrder = 3) : Component(owner)
    {
        mBitSubstr = txnSubStr;
        mProcessOrder = processOrder;
    }
    ~Bit003Component() = default;

    void SetPrCode(std::string& bitStr)
    {
        mPrCode[0] = std::stoi(bitStr.substr(0, 2));
        mPrCode[1] = std::stoi(bitStr.substr(2, 2));
        mPrCode[2] = std::stoi(bitStr.substr(4, 2));
    }
    std::vector<int> GetPrCode() { return mPrCode; }

  private:
    std::vector<int> mPrCode;
};

class Bit004Component : public Component
{
  public:
    Bit004Component(class Iso* owner, std::string txnSubStr = "", int processOrder = 4) : Component(owner)
    {
        mBitSubstr = txnSubStr;
        mProcessOrder = processOrder;
    }
    ~Bit004Component() = default;

    void SetTnxAmt(std::string& bitStr)
    {
        if (mOwner->GetIsoParser()->GetIsoStandard() >= ISO2003_07)
        {
        }
        mTnxAmt = std::stoul(bitStr);
    }
    uint64_t GetTnxAmt() { return mTnxAmt; }

  private:
    uint64_t mTnxAmt;
};

class Bit005Component : public Component
{
  public:
    Bit005Component(class Iso* owner, std::string txnSubStr = "", int processOrder = 5) : Component(owner)
    {
        mBitSubstr = txnSubStr;
        mProcessOrder = processOrder;
    }
    ~Bit005Component() = default;

    void Set(std::string& bitStr) { mData = std::stoul(bitStr); }
    uint64_t Get() { return mData; }

  private:
    uint64_t mData;
};

#endif // BIT_COMPONENTS_H
