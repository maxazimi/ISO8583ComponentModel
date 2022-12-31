#include "Iso.h"
#include "Component.h"

Component::Component(class Iso* owner, int bitNumber = 0)
		:mOwner(owner)
{
    mBitNumber = bitNumber;
    // Add to iso's vector of components
    mOwner->AddComponent(bitNumber, this);
}

Component::~Component()
{
    mOwner->RemoveComponent(this);
}
