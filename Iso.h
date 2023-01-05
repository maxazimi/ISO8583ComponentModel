#ifndef ISO_H
#define ISO_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

enum
{
    ISO1987_07 = 0,
    ISO1987_08,
    ISO1993_07,
    ISO1993_08,
    ISO2003_07,
    ISO2003_08,
    ISO2003_SH,
    ISO2003_SP
};

typedef enum
{
    FIXED = 0,
    LVAR,
    LLVAR,
    LLLVAR,
    LLLLVAR
} format_t;

struct SubSpec
{
    int id;
    std::string type;
    int size;
};

struct BitSpec
{
    int id;
    format_t format;
    std::string type;
    int size;
    int max_size;
    std::vector<SubSpec> subSpec;
};

class Iso
{
public:
    Iso(class IsoParser* isoParser);
    virtual ~Iso();

    class IsoParser* GetIsoParser() { return mOwner; }
    int& GetParseIndex() { return mParseIndex; }

    void SetIsoStandard(int isoStandard) { mIsoStandard = isoStandard; }
    int GetIsoStandard() const { return mIsoStandard; }

    void SetBitmap(std::vector<uint8_t>& bitmap);
    std::vector<bool>& GetBitmap() { return mBitmap; }
    std::vector<BitSpec>& GetBitSpecVec() { return mBitSpecVec; }

    // Add/remove components
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

    virtual bool CheckFormat(const std::string& data, int bitNumber)
    {
        return true;

        std::string format = mBitSpecVec.at(bitNumber).type;
        for (auto& c : format)
        {
            size_t found = data.find(c);
            if (found != std::string::npos)
                ;
        }
    }

    void Process(); // not overridable
    void PrintData()
    {
        printf( "\n"
                "Pan: %llu\n"
                "PrCode: %u %u %u\n"
                "TransactionAmount: %llu\n\n",
                mPan,
                mPrCode[0], mPrCode[1], mPrCode[2],
                mTransactionAmount);
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
        int dummy = floatDigits;
        mTxnCurrencyCode = currencyCode;
    }
    template<typename T>
    void SetSettlementAmount(T& amount, int floatDigits, int currencyCode)
    {
        mSettlementAmount = amount;
        int dummy = floatDigits;
        mSettleCurrencyCode = currencyCode;
    }
    template<typename T>
    void SetBillingAmount(T& amount, int floatDigits, int currencyCode)
    {
        mBillingAmount = amount;
        int dummy = floatDigits;
        mBillCurrencyCode = currencyCode;
    }

protected:
    std::vector<BitSpec> mBitSpecVec;

private:
    class IsoParser* mOwner;

	std::map<int, class Component*> mComponents;
    std::vector<bool> mBitmap; // 128 items

    int mIsoStandard = 0;
    int mParseIndex = 0;

private: // ISO message fields
    uint64_t mPan;
    std::vector<uint8_t> mPrCode;

    uint64_t mTransactionAmount;
    int mTxnCurrencyCode;
    uint64_t mSettlementAmount;
    int mSettleCurrencyCode;
    uint64_t mBillingAmount;
    int mBillCurrencyCode;
};

#endif // ISO_H
