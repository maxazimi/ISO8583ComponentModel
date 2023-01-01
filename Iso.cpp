#include "Iso.h"
#include "IsoParser.h"
#include "Component.h"

Iso::Iso(IsoParser* isoParser) : mOwner(isoParser), mParseIndex(0)
{
    mOwner->AddIso(isoParser->GetIsoStandard(), this);
}

Iso::~Iso()
{
    mOwner->RemoveIso(this);

    for (auto itr = mComponents.begin(); itr != mComponents.end(); ++itr)
    {
        delete itr->second;
    }
    mComponents.clear();
}

void Iso::AddComponent(int bitNumber, Component* component) { mComponents.insert({bitNumber, component}); }

void Iso::RemoveComponent(Component* component)
{
    auto iter = std::find(mComponents.begin(), mComponents.end(), component);
    if (iter != mComponents.end())
    {
        mComponents.erase(iter);
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
