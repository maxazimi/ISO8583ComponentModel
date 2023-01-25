#ifndef ISO_H
#define ISO_H

#include "message.h"

class Iso // Abstract class
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
    void SetBit002(const uint64_t val) { mMsg.mPan = val; }
    uint64_t GetBit002() { return mMsg.mPan; }

    void SetBit003(const std::vector<uint8_t>& vec) { mMsg.mPrCode = vec; }
    std::vector<uint8_t> GetBit003() { return mMsg.mPrCode; }

    virtual void SetBit004(const Amount& ref) { mMsg.mTransaction = ref; }
    Amount GetBit004() { return mMsg.mTransaction; }

    virtual void SetBit005(const Amount& ref) { mMsg.mSettlement = ref; }

    virtual void SetBit006(const Amount& ref) { mMsg.mCardholderBilling = ref; }

    virtual void SetBit007(const IsoDateTime& ref) { mMsg.mTrxDateTime = ref; }

    void SetBit010(const int32_t val) { mMsg.mCardholderConvRate = val; }

    virtual void SetBit022(const std::string& str) = 0; // different implementations (convert required)

    virtual void SetBit024(const std::string& str) { mMsg.mFunctionCode = std::stoi(str); }

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
