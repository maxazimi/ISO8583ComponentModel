#include "IsoParser.h"

int main(int argc, char *argv[])
{
    std::string someTxn = "01002300000000000000000";
    IsoParser isoParser(someTxn);
    return 0;
}
