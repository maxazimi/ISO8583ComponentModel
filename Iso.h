#ifndef ISO_H
#define ISO_H

#include <string>
#include <algorithm>
#include <vector>
#include <map>
//#include "IsoParser.h"

class Iso
{
public:
    Iso(class IsoParser* isoParser);
    virtual ~Iso();

    class IsoParser* GetIsoParser() { return mOwner; }

    // Add/remove components
	void AddComponent(int bitNumber, class Component* component);
	void RemoveComponent(class Component* component);

    virtual void ConvertToIso2003();
    virtual void ConvertFromIso2003();

private:
	std::map<int, class Component*> mComponents;
	class IsoParser* mOwner;
};

#endif // ISO_H
