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
	ISO1987_01 = ISO1987,
    ISO1987_02,
    ISO1993_01 = ISO1993,
    ISO1993_02,
    ISO2003_01 = ISO2003,
    ISO2003_02
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

struct Amount
{
    int16_t floatDigits;
    int64_t amount;
    int16_t currencyCode;
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
