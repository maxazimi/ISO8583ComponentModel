#include "IsoParser.h"
#include "Iso1987.h"
#include "Iso1993.h"
#include "Iso2003.h"

IsoParser::IsoParser(std::string txnString, int isoInStandard)
{
	mTxnString = txnString;
	mIsoInStandard = isoInStandard;

	switch (isoInStandard)
	{
		default:
		case 0:
			AddIso(new Iso1987(this));
			break;
		case 1:
			AddIso(new Iso1993(this));
			break;
		case 2:
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
