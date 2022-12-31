#ifndef COMPONENT_H
#define COMPONENT_H

#include <cstdint>

class Component
{
public:
	Component(class Iso* owner);
	virtual ~Component();

    virtual void Update();
	class Iso* GetOwner() { return mOwner; }
    int GetProcessOrder() const { return mProcessOrder; }

protected:
	// Owning iso
	class Iso* mOwner;
    int mProcessOrder;
};

#endif // COMPONENT_H
