#ifndef ISO_H
#define ISO_H

#include "IsoTypes.h"
#include "Util.h"

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

        // std::string format = mBitSpecVec.at(bitNumber).type;
        // for (auto& c : format)
        // {
        //     size_t found = data.find(c);
        //     if (found != std::string::npos)
        //         ;
        // }
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

public:
    virtual void ConvertField022() {}
	virtual void ConvertField025() {}
	virtual void ConvertField026() {}
	virtual void ConvertField039() {}
	virtual void ConvertField048() {}
	virtual void ConvertField062() {}
	virtual void ConvertField070() {}
	virtual void ConvertField090() {}

public: // ISO message Getter/Setter methods
    void SetField002(const std::string& str) { mPan = std::stoul(str); }

    void SetField003(const std::vector<std::string>& vec)
    {
        for (auto& subStr : vec)
            mPrCode.emplace_back(std::stoi(subStr));
    }

    virtual void SetField004(const std::vector<std::string>& vec)
    {
        mTransactionAmount = Util::CalcAmount(vec[0], 0);
    }

    virtual void SetField005(const std::vector<std::string>& vec)
    {
        mSettlementAmount = Util::CalcAmount(vec[0], 0);
    }

    virtual void SetField006(const std::vector<std::string>& vec)
    {
        mCardholderBillingAmount = Util::CalcAmount(vec[0], 0);
    }

    virtual void SetField007(const IsoDateTime& trxDateTime) { mTrxDateTime = trxDateTime; }

    virtual void SetField022(const std::string& str) = 0; // different implementations (convert required)

    virtual void SetField024(const std::string& str) { mFunctionCode = std::stoi(str); }

private:
    class IsoParser* mOwner;

	std::map<int, class Component*> mComponents;
    std::vector<bool> mBitmap; // 128 items

    int mIsoStandard = 0;
    int mParseIndex = 0;

protected:
    std::vector<BitSpec> mBitSpecVec;

protected: // ISO message fields
    uint64_t mPan;                      /* FD-002 */
    std::vector<uint8_t> mPrCode;       /* FD-003 */

    int mFloatDigits = 0;
    double mTransactionAmount;          /* FD-004 */
    int mTxnCurrencyCode;
    double mSettlementAmount;           /* FD-005 */
    int mSettleCurrencyCode;
    double mCardholderBillingAmount;    /* FD-006 */
    int mBillCurrencyCode;

    //PosDataCode mPosDataCode;           /* FD-022 */
    std::vector<uint32_t> mPosDataCode; /* FD-022 */

    int mNetInternationalId;            /* FD-024 */
    int mFunctionCode;                  /* FD-024 */

    IsoDateTime mTrxDateTime;           /* FD-007 */
};

#endif // ISO_H
