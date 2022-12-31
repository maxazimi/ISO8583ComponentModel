#ifndef ISO1987_H
#define ISO1987_H

#include "Iso.h"

class Iso1987 : public Iso
{
public:
	Iso1987(class IsoParser* isoParser);

private:
	class Bit002Component* mBit002Comp;
	class Bit003Component* mBit003Comp;
	class Bit004Component* mBit004Comp;
};

#endif // ISO1987_H
