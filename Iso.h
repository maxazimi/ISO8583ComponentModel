#ifndef ISO_H
#define ISO_H

#include <vector>

class Iso // Actor
{
public:
    Iso(class IsoParser* isoParser);
    virtual ~Iso();

    class IsoParser* GetIsoParser() { return mIsoParser; }

    // Add/remove components
	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

private:
	std::vector<class Component*> mComponents;
	class IsoParser* mIsoParser;
};

#endif // ISO_H
