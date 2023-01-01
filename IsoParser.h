#ifndef ISO_PARSER_H
#define ISO_PARSER_H

#include <string>
#include <map>
#include "Helper.h"

class IsoParser // Engine
{
public:
    IsoParser(std::string txnString = "");
    ~IsoParser();

    void SetTxnString(std::string& txnString) { mTxnString = txnString; }
    std::string GetTxnString() { return mTxnString; }

    int GetIsoStandard() { return mIsoInStandard; }

    void AddIso(int standard, class Iso* iso);
    void RemoveIso(class Iso* iso);

	  void IsoInstantiate();
    void Parse();

private:
    std::map<int, class Iso*> mIsos;
	  int mIsoInStandard;

    std::string mTxnString;
	  size_t mTxnSize;
};

#endif // ISO_PARSER_H
