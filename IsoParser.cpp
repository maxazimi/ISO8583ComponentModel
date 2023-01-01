#include "Iso1987.h"
#include "Iso1993.h"
#include "Iso2003.h"
#include "IsoParser.h"

IsoParser::IsoParser(std::string txnString)
{
    mTxnString = txnString;
    mIsoInStandard = 0;
}

void IsoParser::AddIso(int standard, Iso* iso)
{
	mIsos.insert({standard, iso});
}

void IsoParser::RemoveIso(Iso* iso)
{
	for (auto& item : mIsos)
	{
		if (item.second == iso)
		{
			delete item.second;
			mIsos.erase(item.first);
		}
	}
}

void IsoParser::Parse()
{
    mTxnSize = std::stoul(mTxnString.substr(0, 4));
    mIsoInStandard = std::stod(mTxnString.substr(4, 1));
    mMti = std::stod(mTxnString.substr(5, 3));

    std::string bitmapStr = mTxnString.substr(8, 32);
    std::vector<uint8_t> bitmap = Helper::HexToBytes(bitmapStr);

    if (mIsos.find(mIsoInStandard) == mIsos.end()) // if not found
        IsoInstantiate();

	// from now on each bit-component parses its own part of message string
	mIsos.at(mIsoInStandard)->SetBitmap(bitmap);
	mIsos.at(mIsoInStandard)->Process();
}

void IsoParser::IsoInstantiate()
{
    switch (mIsoInStandard)
    {
    default:
    case ISO1987_07:
        AddIso(mIsoInStandard, new Iso1987_07(this));
        break;
    case ISO1987_08:
        AddIso(mIsoInStandard, new Iso1987_08(this));
        break;

    case ISO1993_07:
        //AddIso(mIsoInStandard, new Iso1993_07(this));
        break;
    case ISO1993_08:
        //AddIso(mIsoInStandard, new Iso1993_08(this));
        break;

    case ISO2003_07:
        //AddIso(mIsoInStandard, new Iso2003(this));
        break;
    case ISO2003_08:
        //AddIso(mIsoInStandard, new Iso2003(this));
        break;
    case ISO2003_SH:
        //AddIso(mIsoInStandard, new Iso2003(this));
        break;
    case ISO2003_SP:
        //AddIso(mIsoInStandard, new Iso2003(this));
        break;
    }
}
