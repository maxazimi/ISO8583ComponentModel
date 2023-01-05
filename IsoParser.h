#ifndef ISO_PARSER_H
#define ISO_PARSER_H

#include <string>
#include <map>
#include "Util.h"

class IsoParser // Engine
{
public:
    IsoParser(std::string txnString = "");
    ~IsoParser() = default;

    void SetTxnString(std::string& txnString) { mTxnString = txnString; }
    std::string& GetTxnString() { return mTxnString; }

    int GetIndex() { return mIndex; }

    void AddIso(class Iso* iso);
    void RemoveIso(class Iso* iso);

	void IsoInstantiate();
    void Parse();

private:
    std::map<int, class Iso*> mIsos;
    int mIsoInStandard;
    int mIndex;

    std::string mTxnString;
    size_t mTxnSize;
    int mMti;
};

#endif // ISO_PARSER_H
