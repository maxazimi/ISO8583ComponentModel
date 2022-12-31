#ifndef ISO1987_H
#define ISO1987_H

#include "Iso.h"

class Iso1987_07 : public Iso
{
public:
	Iso1987_07(class IsoParser* isoParser);

private:
};

class Iso1987_08 : public Iso
{
public:
	Iso1987_08(class IsoParser* isoParser) : Iso(isoParser)
	{
		int i = 1;
		if (mBitmap[i++]) new Bit001Component(this, isoParser->GetTxnString());
		if (mBitmap[i++]) new Bit002Component(this, isoParser->GetTxnString());
		if (mBitmap[i++]) new Bit003Component(this, isoParser->GetTxnString());
		if (mBitmap[i++]) new Bit004Component(this, isoParser->GetTxnString());
	}

private:
};

#endif // ISO1987_H
