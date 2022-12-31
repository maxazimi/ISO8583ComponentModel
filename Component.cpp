#include "Component.h"
#include "Iso.h"

Component::Component(Iso* owner)
	:mOwner(owner)
{
	// Add to iso's vector of components
	mOwner->AddComponent(this);
}

Component::~Component()
{
	mOwner->RemoveComponent(this);
}
