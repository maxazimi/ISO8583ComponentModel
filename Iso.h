#ifndef ISO_H
#define ISO_H

#include <string>
#include <algorithm>
#include <vector>
#include <map>

class Iso
{
public:
    Iso(class IsoParser* isoParser);
    virtual ~Iso();

    class IsoParser* GetIsoParser() { return mOwner; }
    int& GetParseIndex() { return mParseIndex; }

    void SetBitmap(std::vector<uint8_t>& bitmap)
    {
        for (auto byte : bitmap)
        {
            for (int i = 0; i < 8; byte <<= 1, i++)
            {
                if (byte & 0x80)
                    mBitmap.emplace_back(true);
                else
                    mBitmap.emplace_back(false);
            }
        }
        mBitmap[0] = false; // !!
    }
    std::vector<bool>& GetBitmap() { return mBitmap; }

    // Add/remove components
	void AddComponent(int bitNumber, class Component* component);
	void RemoveComponent(class Component* component);

    void Process(); // not overridable
    virtual void ConvertToIso2003();
    virtual void ConvertFromIso2003();

private:
	std::map<int, class Component*> mComponents;
	class IsoParser* mOwner;

    std::vector<bool> mBitmap; // 128 items
    int mParseIndex;
};

#endif // ISO_H
