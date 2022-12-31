#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>

class Component
{
public:
	Component(class Iso* owner, int bitNumber = 0);
	virtual ~Component();

    virtual void UpdateInfo();
	virtual void CheckInfo();
	
	class Iso* GetOwner() { return mOwner; }
    int GetProcessOrder() const { return mProcessOrder; }

	void SetBitString(std::string& bitString) { mBitString = bitString; }
	std::string GetBitString() { return mBitString; }

protected:
	// Owning iso
	class Iso* mOwner;
	int mBitNumber;
    int mProcessOrder;
	std::string mBitString;
};

#endif // COMPONENT_H
