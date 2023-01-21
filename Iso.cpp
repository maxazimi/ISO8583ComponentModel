#include "Iso.h"
#include "IsoParser.h"
#include "BitComponents.h"

Iso::Iso(IsoParser* isoParser) : mOwner(isoParser),
                                 mTargetStandard(ISO2003)
{
    mOwner->AddIso(this);

	Component* com = nullptr;
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

void Iso::SetBitmap(std::vector<uint8_t>& bitmap)
{
    for (auto byte : bitmap)
    {
        for (int i = 0; i < 8; byte <<= 1, i++) // ugly code!
        {
            if (byte & 0x80)
                mBitmap.emplace_back(true);
            else
                mBitmap.emplace_back(false);
        }
    }
    mBitmap[0] = false; // exclude bit001
}

void Iso::AddComponent(Component* component)
{
    if (component == nullptr) throw std::invalid_argument("Null component!");
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
    mParseIndex = mOwner->GetIndex();
    for (auto& com : mComponents)
    {
        if (mBitmap[com.first - 1])
            com.second->GetBit();
    }
}
