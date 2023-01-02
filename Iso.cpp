#include "Iso.h"
#include "IsoParser.h"
#include "BitComponents.h"

Iso::Iso(IsoParser* isoParser) : mOwner(isoParser),
    mParseIndex(40)
{
    // mBitmap.resize(128);
    // for (int i = 0; i < 128; i++)
    //     mBitSpecVec[i] = {i, FIXED, "N", 0, 0};

    mOwner->AddIso(this);

	Component* com = new Bit001Component(this);
	com = new Bit002Component(this);
	//com = new Bit003Component(this);
	//com = new Bit004Component(this);
	//com = new Bit005Component(this);
}

Iso::~Iso()
{
    mOwner->RemoveIso(this);

    for (auto itr = mComponents.begin(); itr != mComponents.end(); ++itr)
        delete itr->second;
    mComponents.clear();
}

void Iso::AddComponent(Component* component)
{
    if (component == nullptr)
        throw std::invalid_argument("Null component!");
	mComponents.insert({component->GetBitNumber(), component});
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
    for (int i = 1; i <= mComponents.size(); i++)
    {
        if (mBitmap[i])
        {
            mComponents.at(i)->GetBit();
        }
    }
}

void Iso::ConvertToIso2003() {}

void Iso::ConvertFromIso2003() {}
