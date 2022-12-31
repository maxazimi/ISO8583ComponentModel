#ifndef ISO_PARSER_H
#define ISO_PARSER_H

enum
{
	ISO1987_07 = 0,
	ISO1987_08,
	ISO1993_07,
	ISO1993_08,
	ISO2003_07,
	ISO2003_08,
	ISO2003_SH,
	ISO2003_SP
};

class IsoParser // Engine
{
public:
	IsoParser(std::string txnString = "", int isoInStandard = 0);
	~IsoParser();

	void SetTxnString(std::string& txnString) { mTxnString = txnString; }
	std::string GetTxnString() { return mTxnString; }
	int GetIsoStandard() { return mIsoInStandard; }

	void AddIso(class Iso* iso);
	void RemoveIso(class Iso* iso);
	
private:
	std::vector<class Iso*> mIsos;

	std::string mTxnString;
	int mIsoInStandard;
};

#endif // ISO_PARSER_H
