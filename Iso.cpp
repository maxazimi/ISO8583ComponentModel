#include "Iso.h"
#include "IsoParser.h"
#include "Component.h"

Iso::Iso(IsoParser* isoParser)
	:mOwner(isoParser)
{
	mOwner->AddIso(this);
}

Iso::~Iso()
{
	mOwner->RemoveIso(this);

	// Need to delete components
	// Because ~Component calls RemoveComponent, need a different style loop
	for (auto itr = mComponents.begin(); itr != mComponents.end(); ++itr)
	{
        delete itr->second;
	}
	mComponents.clear();
}

void Iso::AddComponent(int bitNumber, Component* component)
{
	mComponents.insert({bitNumber, component});
}

void Iso::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}

void Iso::ConvertToIso2003()
{

}

void Iso::ConvertFromIso2003()
{

}
