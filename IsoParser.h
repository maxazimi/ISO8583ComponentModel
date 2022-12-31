#ifndef ISO_PARSER_H
#define ISO_PARSER_H

#include "Iso.h"

class IsoParser // Engine
{
public:
	IsoParser(std::string txnString = "", int isoInStandard = 0);
	~IsoParser();

	void SetTxnString(std::string& txnString) { mTxnString = txnString; }
	std::string GetTxnString() { return mTxnString; }

	void AddIso(class Iso* iso);
	void RemoveIso(class Iso* iso);
	
private:
	std::vector<class Iso*> mIsos;

	std::string mTxnString;
	int mIsoInStandard;
};

#endif // ISO_PARSER_H
