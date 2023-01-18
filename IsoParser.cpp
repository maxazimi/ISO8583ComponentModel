#include "Iso1987.h"
#include "Iso1993.h"
#include "Iso2003.h"
#include "IsoParser.h"

IsoParser::IsoParser(std::string txnString)
{
    mIndex = 0;
    mTxnString = txnString;
    mIsoInStandard = 0;
}

void IsoParser::AddIso(Iso* iso)
{
	mIsos.insert({mIsoInStandard, iso});
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
    mIndex = 0;
    
    mTxnSize = std::stoul(mTxnString.substr(0, 4));
    mIsoInStandard = std::stoi(mTxnString.substr(4, 1));
    mMti = std::stoi(mTxnString.substr(5, 3));

    std::string bitmapStr = mTxnString.substr(8, 32);
    std::vector<uint8_t> bitmap = Util::HexStringToVectorValue<uint8_t>(bitmapStr);

    mIndex += 40;

    if (mIsos.find(mIsoInStandard) == mIsos.end()) // if ISO version object not found
        IsoInstantiate();

	// from now on each bit-component will parse its own part of message
	mIsos.at(mIsoInStandard)->SetBitmap(bitmap);
	mIsos.at(mIsoInStandard)->Process();
    mIsos.at(mIsoInStandard)->PrintData();
}

void IsoParser::IsoInstantiate()
{
    Iso* iso = nullptr;
    switch (mIsoInStandard)
    {
    default:
    case ISO1987_07:
        iso = new Iso1987_07(this);
        break;
    case ISO1987_08:
        iso = new Iso1987_08(this);
        break;

    case ISO1993_07:
        //AddIso(new Iso1993_07(this));
        break;
    case ISO1993_08:
        //AddIso(new Iso1993_08(this));
        break;

    case ISO2003_07:
        //AddIso(new Iso2003(this));
        break;
    case ISO2003_08:
        //AddIso(new Iso2003(this));
        break;
    case ISO2003_SH:
        //AddIso(new Iso2003(this));
        break;
    case ISO2003_SP:
        //AddIso(new Iso2003(this));
        break;
    }
}
