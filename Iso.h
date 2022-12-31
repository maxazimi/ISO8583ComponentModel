#ifndef ISO_H
#define ISO_H

#include <string>
#include <algorithm>
#include <vector>
#include "BitComponents.h"

class Iso
{
public:
    Iso(class IsoParser* isoParser);
    virtual ~Iso();

    class IsoParser* GetIsoParser() { return mOwner; }

    // Add/remove components
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

    virtual void ConvertToIso2003();
    virtual void ConvertFromIso2003();

protected:
    bool mBitmap[128];

private:
	std::vector<class Component*> mComponents;
	class IsoParser* mOwner;
};

#endif // ISO_H
