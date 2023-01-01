#include "Iso.h"
#include "IsoParser.h"
#include "BitComponents.h"

Iso::Iso(IsoParser* isoParser) : mOwner(isoParser), mParseIndex(0)
{
    mOwner->AddIso(isoParser->GetIsoStandard(), this);

	Component* com;
	com = new Bit001Component(this);
	com = new Bit002Component(this);
	com = new Bit003Component(this);
	com = new Bit004Component(this);
	com = new Bit005Component(this);
}

Iso::~Iso()
{
    mOwner->RemoveIso(this);

    for (auto itr = mComponents.begin(); itr != mComponents.end(); ++itr)
        delete itr->second;
    mComponents.clear();
}

void Iso::AddComponent(int bitNumber, Component* component)
{
	mComponents.insert({bitNumber, component});
}

void Iso::RemoveComponent(Component* component)
{
    for (auto& item : mComponents)
    {
    	if (item.second == component)
		    mComponents.erase(item.first);
    }
}

void Iso::Process()
{
    for (int i = 0; i < mBitmap.size(); i++)
    {
        if (mBitmap[i])
            mComponents.at(i)->GetBit();
    }
}

void Iso::ConvertToIso2003() {}

void Iso::ConvertFromIso2003() {}
