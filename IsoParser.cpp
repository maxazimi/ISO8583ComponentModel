#include "Iso1987.h"
#include "Iso1993.h"
#include "Iso2003.h"
#include "IsoParser.h"

IsoParser::IsoParser(std::string txnString, int isoInStandard)
{
	mTxnString = txnString;
	mIsoInStandard = isoInStandard;

	switch (isoInStandard)
	{
		default:
		case ISO1987_07:
			AddIso(new Iso1987_07(this));
			break;
		case ISO1987_08:
			AddIso(new Iso1987_08(this));
			break;

		case ISO1993_07:
			AddIso(new Iso1993(this));
			break;
		case ISO1993_08:
			AddIso(new Iso1993(this));
			break;

		case ISO2003_07:
			AddIso(new Iso2003(this));
			break;
		case ISO2003_08:
			AddIso(new Iso2003(this));
			break;
		case ISO2003_SH:
			AddIso(new Iso2003(this));
			break;
		case ISO2003_SP:
			AddIso(new Iso2003(this));
			break;
	}
}

void IsoParser::AddIso(Iso* iso)
{
	mIsos.emplace_back(iso);
}

void IsoParser::RemoveIso(Iso* iso)
{
	auto iter = std::find(mIsos.begin(), mIsos.end(), iso);
	if (iter != mIsos.end())
	{
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, mIsos.end() - 1);
		mIsos.pop_back();
	}
}
