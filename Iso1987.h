#ifndef ISO1987_H
#define ISO1987_H

#include "Iso.h"
#include "Helper.h"

class Iso1987 : public Iso
{
  public:
    Iso1987(class IsoParser* isoParser) : Iso(isoParser)
    {
        mBitSpecVec = {
            {1, FIXED, "B", 0, 0},
            //{1, FIXED, "B", 8, 8},
            {2, LLVAR, "N", 0, 19},
            {3, FIXED, "N", 6, 6},
            {4, FIXED, "N", 12, 12},
            {5, FIXED, "N", 12, 12},
            {6, FIXED, "N", 12, 12},
            {7, FIXED, "N", 10, 10},
            {8, FIXED, "N", 8, 8},
            {9, FIXED, "N", 8, 8},
            {10, FIXED, "N", 8, 8},
            {11, FIXED, "N", 6, 6},
            {12, FIXED, "N", 6, 6},
            {13, FIXED, "N", 4, 4},
            {14, FIXED, "N", 4, 4},
            {15, FIXED, "N", 4, 4},
            {16, FIXED, "N", 4, 4},
            {17, FIXED, "N", 4, 4},
            {18, FIXED, "N", 4, 4},
            {19, FIXED, "N", 3, 3},
            {20, FIXED, "N", 3, 3},
            {21, FIXED, "N", 3, 3},
            {22, FIXED, "N", 3, 3},
            {23, FIXED, "N", 3, 3},
            {24, FIXED, "N", 3, 3},
            {25, FIXED, "N", 2, 2},
            {26, FIXED, "N", 2, 2},
            {27, FIXED, "N", 1, 1},
            {28, FIXED, "XN", 8, 8},
            {29, FIXED, "XN", 8, 8},
            {30, FIXED, "XN", 8, 8},
            {31, FIXED, "XN", 8, 8},
            {32, LLVAR, "N", 0, 11},
            {33, LLVAR, "N", 0, 11},
            {34, LLVAR, "NS", 0, 28},
            {35, LLVAR, "Z", 0, 37},
            {36, LLVAR, "Z", 0, 104},
            {37, FIXED, "AN", 12, 12},
            {38, FIXED, "AN", 6, 6},
            {39, FIXED, "AN", 2, 2},
            {40, FIXED, "AN", 3, 3},
            {41, FIXED, "ANS", 8, 8},
            {42, FIXED, "ANS", 15, 15},
            {43, FIXED, "ANS", 40, 40},
            {44, LLVAR, "ANS", 0, 25},
            {45, LLVAR, "ANS", 0, 76},
            {46, LLLVAR, "ANS", 0, 999},
            {47, LLLVAR, "ANS", 0, 999},
            {48, LLLVAR, "ANS", 0, 999},
            {49, FIXED, "AN", 3, 3},
            {50, FIXED, "AN", 3, 3},
            {51, FIXED, "AN", 3, 3},
            {52, FIXED, "B", 64, 64},
            {53, FIXED, "N", 16, 16},
            {54, LLLVAR, "AN", 0, 120},
            {55, LLLVAR, "ANS", 0, 999},
            {56, LLLVAR, "ANS", 0, 999},
            {57, LLLVAR, "ANS", 0, 999},
            {58, LLLVAR, "ANS", 0, 999},
            {59, LLLVAR, "ANS", 0, 999},
            {60, LLLVAR, "ANS", 0, 999},
            {61, LLLVAR, "ANS", 0, 999},
            {62, LLLVAR, "ANS", 0, 999},
            {63, LLLVAR, "ANS", 0, 999},
            {64, FIXED, "B", 64, 64},
            {65, FIXED, "B", 1, 1},
            {66, FIXED, "N", 1, 1},
            {67, FIXED, "N", 2, 2},
            {68, FIXED, "N", 3, 3},
            {69, FIXED, "N", 3, 3},
            {70, FIXED, "N", 3, 3},
            {71, FIXED, "N", 4, 4},
            {72, FIXED, "N", 4, 4},
            {73, FIXED, "N", 6, 6},
            {74, FIXED, "N", 10, 10},
            {75, FIXED, "N", 10, 10},
            {76, FIXED, "N", 10, 10},
            {77, FIXED, "N", 10, 10},
            {78, FIXED, "N", 10, 10},
            {79, FIXED, "N", 10, 10},
            {80, FIXED, "N", 10, 10},
            {81, FIXED, "N", 10, 10},
            {82, FIXED, "N", 12, 12},
            {83, FIXED, "N", 12, 12},
            {84, FIXED, "N", 12, 12},
            {85, FIXED, "N", 12, 12},
            {86, FIXED, "N", 16, 16},
            {87, FIXED, "N", 16, 16},
            {88, FIXED, "N", 16, 16},
            {89, FIXED, "N", 16, 16},
            {90, FIXED, "N", 42, 42},
            {91, FIXED, "AN", 1, 1},
            {92, FIXED, "AN", 2, 2},
            {93, FIXED, "AN", 5, 5},
            {94, FIXED, "AN", 7, 7},
            {95, FIXED, "AN", 42, 42},
            {96, FIXED, "B", 64, 64},
            {97, FIXED, "XN", 16, 16},
            {98, FIXED, "ANS", 25, 25},
            {99, LLVAR, "N", 0, 11},
            {100, LLVAR, "N", 0, 11},
            {101, LLVAR, "ANS", 0, 17},
            {102, LLVAR, "ANS", 0, 28},
            {103, LLVAR, "ANS", 0, 28},
            {104, LLLVAR, "ANS", 0, 100},
            {105, LLLVAR, "ANS", 0, 999},
            {106, LLLVAR, "ANS", 0, 999},
            {107, LLLVAR, "ANS", 0, 999},
            {108, LLLVAR, "ANS", 0, 999},
            {109, LLLVAR, "ANS", 0, 999},
            {110, LLLVAR, "ANS", 0, 999},
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
            {128, FIXED, "B", 64, 64}
        };
    }

  private:
};

class Iso1987_07 : public Iso1987
{
public:
    Iso1987_07(class IsoParser* isoParser) : Iso1987(isoParser)
    {
        SetIsoStandard(ISO1987_07);
    }

private:
};

class Iso1987_08 : public Iso1987
{
public:
    Iso1987_08(class IsoParser* isoParser) : Iso1987(isoParser)
    {
        SetIsoStandard(ISO1987_08);
    }

private:
};

#endif // ISO1987_H
