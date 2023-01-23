#ifndef ISO_H
#define ISO_H

#include "message.h"

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

    void AppendFieldString(std::string& bitString) { mOutputTxnString += bitString; }
    std::string GetOutputTxnString() const { return mOutputTxnString; }

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

    void Parse(); // not overridable
    void Build(); // not overridable

    void Print() { mMsg.Print(); }

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
    void SetField002(const std::string& str) { mMsg.mPan = std::stoul(str); }
    uint64_t GetField002() { return mMsg.mPan; }

    void SetField003(const std::vector<std::string>& vec)
    {
        mMsg.mPrCode = std::stoi(vec[0] + vec[1] + vec[2]);
    }
    int32_t GetField003() { return mMsg.mPrCode; }

    virtual void SetField004(const std::vector<std::string>& vec)
    {
        mMsg.mTransactionAmount.amount = std::stoll(vec[0]);
    }
    std::string GetField004()
    {
        return  Util::ConvertToPaddedString(mMsg.mTransactionAmount.currencyCode, 3) +
                Util::ConvertToPaddedString(mMsg.mTransactionAmount.floatDigits, 1) +
                Util::ConvertToPaddedString(mMsg.mTransactionAmount.amount, 12);
    }

    virtual void SetField005(const std::vector<std::string>& vec)
    {
        mMsg.mSettlementAmount.amount = std::stoll(vec[0]);
    }

    virtual void SetField006(const std::vector<std::string>& vec)
    {
        mMsg.mCardholderBillingAmount.amount = std::stoll(vec[0]);
    }

    virtual void SetField007(const IsoDateTime& trxDateTime) { mMsg.mTrxDateTime = trxDateTime; }

    void SetField010(const int32_t convRate) { mMsg.mCardholderConvRate = convRate; }

    virtual void SetField022(const std::string& str) = 0; // different implementations (convert required)

    virtual void SetField024(const std::string& str) { mMsg.mFunctionCode = std::stoi(str); }

private:
    class IsoParser* mOwner;

	std::map<int, class Component*> mComponents;
    std::vector<bool> mBitmap; // 128 items

    int mIsoStandard = 0;
    int mParseIndex = 0;

protected:
    std::vector<BitSpec> mBitSpecVec;
    std::string mOutputTxnString;
    int mTargetStandard;

    Message mMsg;
};

#endif // ISO_H
