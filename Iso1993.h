#ifndef ISO1993_H
#define ISO1993_H

#include "Iso.h"

class Iso1993 : public Iso
{
  public:
    Iso1993(class IsoParser* isoParser) : Iso(isoParser)
    {
        mBitSpecVec = {
			{0, FIXED, "B", 0, 0}, 	/* dummy */
            {1, FIXED, "B", 8, 8}, 	/* bitmap */
			{2, LLVAR, "N", 0, 19}, /* PAN */
			{3, FIXED, "N", 6, 6, {{1, "N", 2}, {2, "N", 2}, {3, "N", 2}}},
			{4, FIXED, "N", 12, 12},
			{5, FIXED, "N", 12, 12},
			{6, FIXED, "N", 12, 12},
			{7, FIXED, "N", 10, 10},
			{8, FIXED, "N", 8, 8},
			{9, FIXED, "N", 8, 8},
			{10, FIXED, "N", 8, 8},
			{11, FIXED, "N", 6, 6},
			{12, FIXED, "N", 12, 12},
			{13, FIXED, "N", 4, 4},
			{14, FIXED, "N", 4, 4},
			{15, FIXED, "N", 6, 6},
			{16, FIXED, "N", 4, 4},
			{17, FIXED, "N", 4, 4},
			{18, FIXED, "N", 4, 4},
			{19, FIXED, "N", 3, 3},
			{20, FIXED, "N", 3, 3},
			{21, FIXED, "N", 3, 3},
			{22, FIXED, "AN", 12, 12},
			{23, FIXED, "N", 3, 3},
			{24, FIXED, "N", 3, 3},
			{25, FIXED, "N", 4, 4},
			{26, FIXED, "N", 4, 4},
			{27, FIXED, "N", 1, 1},
			{28, FIXED, "N", 6, 6},
			{29, FIXED, "N", 3, 3},
			{30, FIXED, "N", 24, 24},
			{31, LLVAR, "ANS", 0, 99},
			{32, LLVAR, "N", 0, 11},
			{33, LLVAR, "N", 0, 11},
			{34, LLVAR, "NS", 0, 28},
			{35, LLVAR, "Z", 0, 37},
			{36, LLLVAR, "Z", 0, 104},
			{37, FIXED, "ANP", 12, 12},
			{38, FIXED, "ANP", 6, 6},
			{39, FIXED, "N", 3, 3},
			{40, FIXED, "N", 3, 3},
			{41, FIXED, "ANS", 8, 8},
			{42, FIXED, "ANS", 15, 15},
			{43, LLVAR, "ANS", 0, 99},
			{44, LLVAR, "ANS", 0, 99},
			{45, LLVAR, "ANS", 0, 76},
			{46, LLLVAR, "ANS", 0, 204},
			{47, LLLVAR, "ANS", 0, 999},
			{48, LLLVAR, "ANS", 0, 999},
			{49, FIXED, "N", 3, 3},
			{50, FIXED, "N", 3, 3},
			{51, FIXED, "N", 3, 3},
			{52, FIXED, "B", 8, 8},
			{53, LLVAR, "B", 0, 48},
			{54, LLLVAR, "ANS", 0, 120},
			{55, LLLVAR, "B", 0, 255},
			{56, LLVAR, "N", 0, 35},
			{57, FIXED, "N", 3, 3},
			{58, LLVAR, "N", 0, 11},
			{59, LLLVAR, "ANS", 0, 999},
			{60, LLLVAR, "ANS", 0, 999},
			{61, LLLVAR, "ANS", 0, 999},
			{62, LLLVAR, "ANS", 0, 999},
			{63, LLLVAR, "ANS", 0, 999},
			{64, FIXED, "B", 8, 8},
			{65, FIXED, "B", 8, 8},
			{66, LLLVAR, "ANS", 0, 204},
			{67, FIXED, "N", 2, 2},
			{68, FIXED, "N", 3, 3},
			{69, FIXED, "N", 3, 3},
			{70, FIXED, "N", 3, 3},
			{71, FIXED, "N", 8, 8},
			{72, LLLVAR, "ANS", 0, 999},
			{73, FIXED, "N", 6, 6},
			{74, FIXED, "N", 10, 10},
			{75, FIXED, "N", 10, 10},
			{76, FIXED, "N", 10, 10},
			{77, FIXED, "N", 10, 10},
			{78, FIXED, "N", 10, 10},
			{79, FIXED, "N", 10, 10},
			{80, FIXED, "N", 10, 10},
			{81, FIXED, "N", 10, 10},
			{82, FIXED, "N", 10, 10},
			{83, FIXED, "N", 10, 10},
			{84, FIXED, "N", 10, 10},
			{85, FIXED, "N", 10, 10},
			{86, FIXED, "N", 16, 16},
			{87, FIXED, "N", 16, 16},
			{88, FIXED, "N", 16, 16},
			{89, FIXED, "N", 16, 16},
			{90, FIXED, "N", 10, 10},
			{91, FIXED, "N", 3, 3},
			{92, FIXED, "N", 3, 3},
			{93, LLVAR, "N", 0, 11},
			{94, LLVAR, "N", 0, 11},
			{95, LLVAR, "ANS", 0, 99},
			{96, LLLVAR, "B", 0, 999},
			{97, FIXED, "XN", 16, 16},
			{98, FIXED, "ANS", 25, 25},
			{99, LLVAR, "AN", 0, 11},
			{100, LLVAR, "N", 0, 11},
			{101, LLVAR, "ANS", 0, 17},
			{102, LLVAR, "ANS", 0, 28},
			{103, LLVAR, "ANS", 0, 28},
			{104, LLLVAR, "ANS", 0, 100},
			{105, FIXED, "N", 16, 16},
			{106, FIXED, "N", 16, 16},
			{107, FIXED, "N", 10, 10},
			{108, FIXED, "N", 10, 10},
			{109, LLVAR, "ANS", 0, 84},
			{110, LLVAR, "ANS", 0, 84},
			{111, LLLVAR, "ANS", 0, 999},
			{112, LLLVAR, "ANS", 0, 999},
			{113, LLLVAR, "ANS", 0, 999},
			{114, LLLVAR, "ANS", 0, 999},
			{115, LLLVAR, "ANS", 0, 999},
			{116, LLLVAR, "ANS", 0, 999},
			{117, LLLVAR, "ANS", 0, 999},
			{118, LLLVAR, "ANS", 0, 999},
			{119, LLLVAR, "ANS", 0, 999},
			{120, LLLVAR, "ANS", 0, 999},
			{121, LLLVAR, "ANS", 0, 999},
			{122, LLLVAR, "ANS", 0, 999},
			{123, LLLVAR, "ANS", 0, 999},
			{124, LLLVAR, "ANS", 0, 999},
			{125, LLLVAR, "ANS", 0, 999},
			{126, LLLVAR, "ANS", 0, 999},
			{127, LLLVAR, "ANS", 0, 999},
			{128, FIXED, "B", 8, 8}
        };
    }

public: // ISO message Getter/Setter methods (ISO-1993)
    void SetField022(const std::string& str) override
    {
    }

private:
};

class Iso1993_07 : public Iso1993
{
public:
    Iso1993_07(class IsoParser* isoParser) : Iso1993(isoParser)
    {
        SetIsoStandard(ISO1993_07);
    }
};

class Iso1993_08 : public Iso1993
{
public:
    Iso1993_08(class IsoParser* isoParser) : Iso1993(isoParser)
    {
        SetIsoStandard(ISO1993_08);
    }
};

#endif // ISO1993_H
