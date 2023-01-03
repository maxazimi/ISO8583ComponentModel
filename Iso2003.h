#ifndef ISO2003_H
#define ISO2003_H

#include "Iso.h"
#include "Helper.h"

class Iso2003 : public Iso
{
  public:
    Iso2003(class IsoParser* isoParser) : Iso(isoParser)
    {
        mBitSpecVec = {
			{0, FIXED, "B", 0, 0},
            {1, FIXED, "B", 8, 8},
			{2, LLVAR, "N", 0, 19},
			{3, FIXED, "AN", 6, 6},
			{4, FIXED, "N", 16, 16},
			{5, FIXED, "N", 16, 16},
			{6, FIXED, "N", 16, 16},
			{7, FIXED, "N", 10, 10},
			{8, FIXED, "N", 12, 12},
			{9, FIXED, "N", 8, 8},
			{10, FIXED, "N", 8, 8},
			{11, FIXED, "N", 12, 12},
			{12, FIXED, "N", 14, 14},
			{13, FIXED, "N", 6, 6},
			{14, FIXED, "N", 4, 4},
			{15, FIXED, "N", 8, 8},
			{16, FIXED, "N", 4, 4},
			{17, FIXED, "N", 4, 4},
			{18, LLLVAR, "ANSB", 0, 140},
			{19, FIXED, "N", 3, 3},
			{20, FIXED, "N", 3, 3},
			{21, FIXED, "ANS", 22, 22},
			{22, FIXED, "B", 16, 16},
			{23, FIXED, "N", 3, 3},
			{24, FIXED, "N", 3, 3},
			{25, FIXED, "N", 4, 4},
			{26, FIXED, "N", 4, 4},
			{27, FIXED, "ANB", 27, 27},
			{28, FIXED, "N", 8, 8},
			{29, FIXED, "N", 3, 3},
			{30, FIXED, "N", 32, 32},
			{31, FIXED, "N", 23, 23},
			{32, LLVAR, "N", 0, 11},
			{33, LLVAR, "N", 0, 11},
			{34, LLLLVAR, "B", 0, 9999},
			{35, LLVAR, "Z", 0, 37},
			{36, LLLVAR, "Z", 0, 104},
			{37, FIXED, "ANP", 12, 12},
			{38, FIXED, "ANP", 6, 6},
			{39, FIXED, "N", 4, 4},
			{40, FIXED, "N", 3, 3},
			{41, FIXED, "ANS", 16, 16},
			{42, LLVAR, "ANS", 0, 35},
			{43, LLLLVAR, "ANSB", 0, 9999},
			{44, LLLLVAR, "ANSB", 0, 9999},
			{45, LLVAR, "ANS", 0, 76},
			{46, LLLVAR, "ANS", 0, 216},
			{47, LLLVAR, "ANS", 0, 999},
			{48, LLLVAR, "ANS", 0, 999},
			{49, LLLLVAR, "ANS", 0, 9999},
			{50, LLLLVAR, "ANSB", 0, 9999},
			{51, LLLLVAR, "ANSB", 0, 9999},
			{52, FIXED, "B", 8, 8},
			{53, LLVAR, "B", 0, 48},
			{54, LLLVAR, "ANS", 0, 126},
			{55, LLLLVAR, "B", 0, 9999},
			{56, LLVAR, "N", 0, 41},
			{57, FIXED, "N", 3, 3},
			{58, LLVAR, "N", 0, 11},
			{59, LLLVAR, "ANS", 0, 999},
			{60, LLLVAR, "ANS", 0, 999},
			{61, LLLVAR, "ANS", 0, 999},
			{62, LLLVAR, "ANS", 0, 999},
			{63, LLLVAR, "ANS", 0, 999},
			{64, FIXED, "B", 4, 4},
			{65, FIXED, "B", 8, 8},
			{66, LLLVAR, "ANS", 0, 216},
			{67, FIXED, "N", 2, 2},
			{68, FIXED, "AN", 9, 9},
			{69, FIXED, "ANS", 40, 40},
			{70, FIXED, "N", 18, 18},
			{71, LLLLVAR, "ANSB", 0, 9999},
			{72, LLLLVAR, "ANSB", 0, 9999},
			{73, FIXED, "N", 8, 8},
			{74, FIXED, "N", 156, 156},
			{75, FIXED, "N", 90, 90},
			{76, LLLLVAR, "ANSB", 0, 9999},
			{77, LLLLVAR, "ANSB", 0, 9999},
			{78, LLLLVAR, "ANSB", 0, 9999},
			{79, LLLLVAR, "ANSB", 0, 9999},
			{80, LLLLVAR, "ANSB", 0, 9999},
			{81, LLLLVAR, "ANSB", 0, 9999},
			{82, LLLLVAR, "ANSB", 0, 9999},
			{83, LLLLVAR, "ANSB", 0, 9999},
			{84, LLLLVAR, "ANSB", 0, 9999},
			{85, LLLLVAR, "ANSB", 0, 9999},
			{86, LLLLVAR, "ANSB", 0, 9999},
			{87, LLLLVAR, "ANSB", 0, 9999},
			{88, LLLLVAR, "ANSB", 0, 9999},
			{89, LLLLVAR, "ANSB", 0, 9999},
			{90, LLLLVAR, "ANSB", 0, 9999},
			{91, LLLLVAR, "ANSB", 0, 9999},
			{92, LLLLVAR, "ANSB", 0, 9999},
			{93, LLVAR, "N", 0, 11},
			{94, LLVAR, "N", 0, 11},
			{95, LLVAR, "ANS", 0, 99},
			{96, LLLVAR, "B", 0, 999},
			{97, FIXED, "XN", 21, 21},
			{98, FIXED, "ANS", 25, 25},
			{99, LLVAR, "AN", 0, 11},
			{100, LLVAR, "N", 0, 11},
			{101, LLVAR, "ANS", 0, 99},
			{102, LLVAR, "ANS", 0, 28},
			{103, LLVAR, "ANS", 0, 28},
			{104, LLLLVAR, "ANSB", 0, 9999},
			{105, LLLLVAR, "ANSB", 0, 9999},
			{106, LLLLVAR, "ANSB", 0, 9999},
			{107, LLLLVAR, "ANSB", 0, 9999},
			{108, LLLLVAR, "ANSB", 0, 9999},
			{109, LLLVAR, "ANS", 0, 144},
			{110, LLLVAR, "ANS", 0, 144},
			{111, LLLLVAR, "ANSB", 0, 9999},
			{112, LLLLVAR, "ANSB", 0, 9999},
			{113, LLLLVAR, "ANSB", 0, 9999},
			{114, LLLLVAR, "ANSB", 0, 9999},
			{115, LLLLVAR, "ANSB", 0, 9999},
			{116, LLLLVAR, "ANSB", 0, 9999},
			{117, LLLLVAR, "ANSB", 0, 9999},
			{118, LLLLVAR, "ANSB", 0, 9999},
			{119, LLLLVAR, "ANSB", 0, 9999},
			{120, LLLLVAR, "ANSB", 0, 9999},
			{121, LLLLVAR, "ANSB", 0, 9999},
			{122, LLLLVAR, "ANSB", 0, 9999},
			{123, LLLLVAR, "ANSB", 0, 9999},
			{124, LLLLVAR, "ANSB", 0, 9999},
			{125, LLLLVAR, "ANSB", 0, 9999},
			{126, LLLLVAR, "ANSB", 0, 9999},
			{127, LLLLVAR, "ANSB", 0, 9999},
			{128, FIXED, "B", 4, 4}
        };
    }

  private:
};

class Iso2003_07 : public Iso2003
{
public:
    Iso2003_07(class IsoParser* isoParser) : Iso2003(isoParser)
    {
        SetIsoStandard(ISO2003_07);
    }

private:
};

class Iso2003_08 : public Iso2003
{
public:
    Iso2003_08(class IsoParser* isoParser) : Iso2003(isoParser)
    {
        SetIsoStandard(ISO2003_08);
    }

private:
};

#endif // ISO2003_H
