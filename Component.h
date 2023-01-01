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

    virtual void GetBit();
    virtual void CheckInfo() = 0;

  protected:
    // Owning iso
    class Iso* mOwner;

    int mBitNumber;
    int mProcessOrder;

    std::string mBitSubstr;
    size_t mBitStrLen;
    size_t mBitStrlVar;
    size_t mBitStrMaxLen;
};

#endif // COMPONENT_H
