#include "Iso.h"
#include "IsoParser.h"
#include "Component.h"

Iso::Iso(IsoParser* isoParser)
	:mIsoParser(isoParser)
{
	mIsoParser->AddIso(this);
}

Iso::~Iso()
{
	mIsoParser->RemoveIso(this);

	// Need to delete components
	// Because ~Component calls RemoveComponent, need a different style loop
	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}

void Iso::AddComponent(Component* component)
{
	// Find the insertion point in the sorted vector
	// (The first element with a order higher than me)
	int myOrder = component->GetProcessOrder();
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); ++iter)
	{
		if (myOrder < (*iter)->GetProcessOrder())
		{
			break;
		}
	}

	// Inserts element before position of iterator
	mComponents.insert(iter, component);
}

void Iso::RemoveComponent(Component* component)
{
	auto iter = std::find(mComponents.begin(), mComponents.end(), component);
	if (iter != mComponents.end())
	{
		mComponents.erase(iter);
	}
}
