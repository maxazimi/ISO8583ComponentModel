#ifndef COMPONENT_H
#define COMPONENT_H

#include <cstdint>

class Component
{
public:
	Component(class Iso* owner)
		:mOwner(owner)
	{
		// Add to iso's vector of components
		mOwner->AddComponent(this);
	}

	virtual ~Component()
	{
		mOwner->RemoveComponent(this);
	}

    virtual void UpdateInfo();
	virtual void CheckInfo();
	
	class Iso* GetOwner() { return mOwner; }
    int GetProcessOrder() const { return mProcessOrder; }

	void SetBitString(std::string& bitString) { mBitString = bitString; }
	std::string GetBitString() { return mBitString; }

protected:
	// Owning iso
	class Iso* mOwner;
    int mProcessOrder;
	std::string mBitString;
};

#endif // COMPONENT_H
