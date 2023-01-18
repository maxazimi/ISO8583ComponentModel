#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component
{
public:
    Component(class Iso* owner, int bitNumber = 0);
    virtual ~Component();

    class Iso* GetOwner() { return mOwner; }
    int GetProcessOrder() const { return mProcessOrder; }

    void SetBitString(std::string& bitString) { mBitString = bitString; }
    std::string& GetBitString() { return mBitString; }
    
    int GetBitNumber() { return mBitNumber; }

    virtual void GetBit();
    virtual void CheckInfo() {}
    virtual void PutBit() {}

private:
    void SetError(const std::string& errStr)
    {
        mErrors.emplace_back(errStr);
        printf("Error[from Bit%00d]: %s\n", mBitNumber, errStr.c_str());
    }

    int CalcTotalSubfieldSize();

protected:
    // Owning iso
    class Iso* mOwner;

    int mBitNumber = 0;
    int mProcessOrder;

    BitSpec mBitSpec;
    std::string mBitString;
    std::vector<std::string> mSubBitStrVec;
    std::vector<std::string> mErrors;
};

#endif // COMPONENT_H
