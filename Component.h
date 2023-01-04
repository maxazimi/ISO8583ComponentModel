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
    std::string GetBitString() { return mBitString; }
    
    int GetBitNumber() { return mBitNumber; }

    virtual void GetBit();
    virtual void CheckInfo() {}

    virtual void ConvertToIso2003() {}
    virtual void ConvertFromIso2003() {}

  protected:
    // Owning iso
    class Iso* mOwner;

    int mBitNumber = 0;
    int mProcessOrder;

    BitSpec mBitSpec;
    std::string mBitString;
    std::vector<std::string> mSubBitStrVec;
};

#endif // COMPONENT_H
