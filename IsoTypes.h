#ifndef ISO_TYPES_H
#define ISO_TYPES_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

typedef enum
{
	ISO1987 = 0,
	ISO1993 = 2,
	ISO2003 = 4
} iso_std_t;

typedef enum
{
	ISO1987_07 = ISO1987,
    ISO1987_08,
    ISO1993_07 = ISO1993,
    ISO1993_08,
    ISO2003_07 = ISO2003,
    ISO2003_08,
    ISO2003_SH,
    ISO2003_SP
} iso_version_t;

typedef enum
{
    FIXED = 0,
    LVAR,
    LLVAR,
    LLLVAR,
    LLLLVAR
} format_t;

/*
 * MMDDhhmmss
 */
struct IsoDateTime
{
    int CC;
    int YY;
    int MM;
    int DD;
    int hh;
    int mm;
    int ss;
};

/*
 * FD-022 ISO-2003
 */
struct PosDataCode
{
    uint8_t cardReadingMethod;
    uint8_t cardholderVerificationMethod;
    uint8_t posEnvironment;
    uint8_t securityCharacteristics;
};

struct SubSpec
{
    int id;
    std::string type;
    int size;
};

struct BitSpec
{
    int id;
    format_t format;
    std::string type;
    int size;
    int max_size;
    std::vector<SubSpec> subSpec;
};

#endif // ISO_TYPES_H
