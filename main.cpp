#include <iostream>
#include "IsoParser.h"

int main(int argc, char *argv[])
{
    std::string someTxn = "06160100F238E4C128E1982600000000100000011650293825000000290000000000002900000102134232730685134232010201015655364021100409581672131375029343a553b3c9648b6e2394da921f27946634811135029837000103000000000100019aaaaaaaaaaaaaaaaaaaaaabbbbbbbbbbbbbTHRIR040700022010201020440510316ABCDEF098765432136491ac759c1a1a68e802020103020000000449990000500010000000011234567890123000001000010914000000010022130000000000000000000000000000000190970.1.4.620512345123123456012345678905123450000202301020040108E0000000C000000000000C0000000000000591IR070170000000107895618005        00000029000000000000000020230102000209581672000B7322F7B00000000";
    IsoParser isoParser(someTxn);
    isoParser.Parse();
    return 0;
}
