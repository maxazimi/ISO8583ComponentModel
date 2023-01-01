#ifndef ISO1987_H
#define ISO1987_H

#include "Iso.h"

class Iso1987_07 : public Iso
{
  public:
    Iso1987_07(class IsoParser* isoParser)
	{
	}

  private:
};

class Iso1987_08 : public Iso
{
  public:
    Iso1987_08(class IsoParser* isoParser) : Iso(isoParser)
    {
        Component* com;
        com = new Bit001Component(this);
        com = new Bit002Component(this);
        com = new Bit003Component(this);
        com = new Bit004Component(this);
        com = new Bit005Component(this);
    }

  private:
};

#endif // ISO1987_H
