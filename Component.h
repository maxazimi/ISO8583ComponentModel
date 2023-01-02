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

    void SetBitString(std::string& bitString) { mBitSubstr = bitString; }
    std::string GetBitString() { return mBitSubstr; }
    int GetBitNumber() { return mBitNumber; }

    virtual void GetBit();
    virtual void CheckInfo() {}

  protected:
    // Owning iso
    class Iso* mOwner;

    int mBitNumber = 0;
    int mProcessOrder;

    std::string mBitSubstr;
    BitSpec mBitSpec;
};

#endif // COMPONENT_H
