#ifndef ISO1987_H
#define ISO1987_H

#include "Iso.h"
#include "IsoParser.h"

class Iso1987 : public Iso
{
public:
	Iso1987(class IsoParser* isoParser) : Iso(isoParser)
	{
		int i = 1;
		if (mBitmap[i++]) AddComponent(new Bit001Component(this, isoParser->GetTxnString()));
		if (mBitmap[i++]) AddComponent(new Bit002Component(this, isoParser->GetTxnString()));
		if (mBitmap[i++]) AddComponent(new Bit003Component(this, isoParser->GetTxnString()));
		if (mBitmap[i++]) AddComponent(new Bit004Component(this, isoParser->GetTxnString()));
	}

private:
};

#endif // ISO1987_H
