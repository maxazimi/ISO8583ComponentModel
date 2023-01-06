#ifndef ISO_H
#define ISO_H

#include "IsoTypes.h"

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

    virtual bool CheckFormat(const std::string& data, int bitNumber) // incomplete
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
                "TransactionAmount: %lf\n\n",
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
    void SetTxnAmount(T& amount, int currencyCode)
    {
        mTransactionAmount = amount;
        mTxnCurrencyCode = currencyCode;
    }
    template<typename T>
    void SetSettlementAmount(T& amount, int currencyCode)
    {
        mSettlementAmount = amount;
        mSettleCurrencyCode = currencyCode;
    }
    template<typename T>
    void SetCardholderBillingAmount(T& amount, int currencyCode)
    {
        mCardholderBillingAmount = amount;
        mBillCurrencyCode = currencyCode;
    }

    template<typename T>
    void SetTransmissionDateTime(T& trxDateTime) { mTrxDateTime = trxDateTime; }

protected:
    std::vector<BitSpec> mBitSpecVec;

private:
    class IsoParser* mOwner;

	std::map<int, class Component*> mComponents;
    std::vector<bool> mBitmap; // 128 items

    int mIsoStandard = 0;
    int mParseIndex = 0;

private: // ISO message fields
    uint64_t mPan;                      /* FD-002 */
    std::vector<uint8_t> mPrCode;       /* FD-003 */

    double mTransactionAmount;          /* FD-004 */
    int mTxnCurrencyCode;
    double mSettlementAmount;           /* FD-005 */
    int mSettleCurrencyCode;
    double mCardholderBillingAmount;    /* FD-006 */
    int mBillCurrencyCode;

    IsoDateTime mTrxDateTime;           /* FD-007 */
};

#endif // ISO_H
