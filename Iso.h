#ifndef ISO_H
#define ISO_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

typedef enum
{
    FIXED = 0,
    LVAR,
    LLVAR,
    LLLVAR,
    LLLLVAR
} format_t;

struct BitSpec
{
    int id;
    format_t format;
    std::string type;
    int size;
    int max_size;
};

class Iso
{
public:
    Iso(class IsoParser* isoParser);
    virtual ~Iso();

    class IsoParser* GetIsoParser() { return mOwner; }
    int& GetParseIndex() { return mParseIndex; }

    void SetBitmap(std::vector<uint8_t>& bitmap)
    {
        for (auto byte : bitmap)
        {
            for (int i = 0; i < 8; byte <<= 1, i++)
            {
                if (byte & 0x80)
                    mBitmap.emplace_back(true);
                else
                    mBitmap.emplace_back(false);
            }
        }
        mBitmap[0] = false; // exclude bit001
    }

    void SetIsoStandard(int isoStandard) { mIsoStandard = isoStandard; }
    int GetIsoStandard() { return mIsoStandard; }

    std::vector<bool>& GetBitmap() { return mBitmap; }
    std::vector<BitSpec>& GetBitSpecVec() { return mBitSpecVec; }

    // Add/remove components
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

    void Process(); // not overridable
    virtual void ConvertToIso2003();
    virtual void ConvertFromIso2003();

    void PrintData()
    {
        printf("%llu %u %u %u\n", mPan, mPrCode[0], mPrCode[1], mPrCode[2]);
    }

public: // ISO message Getter/Setter methods
    template<typename T>
    void SetPan(T data) { mPan = data; }

    template<typename T>
    void SetPrCode(std::vector<T>& data) { mPrCode = data; }

    template<typename T>
    void SetTxnAmount(T& amount, int floatDigits, int currencyCode)
    {
        mTransactionAmount = amount;
        mFloatDigits = floatDigits;
        mCurrencyCode = currencyCode;
    }

protected:
    std::vector<BitSpec> mBitSpecVec;

private:
    class IsoParser* mOwner;

	std::map<int, class Component*> mComponents;
    std::vector<bool> mBitmap; // 128 items

    int mIsoStandard = 0;
    int mParseIndex;

private: // ISO message fields
    uint64_t mPan;
    std::vector<uint8_t> mPrCode;

    uint64_t mTransactionAmount;
    int mFloatDigits;
    int mCurrencyCode;
};

#endif // ISO_H
