#ifndef MESSAGE_H
#define MESSAGE_H

#include "IsoTypes.h"
#include "Util.h"

class Message
{
public:
    void Print()
    {
        printf( "\n"
                "Pan: %llu\n"
                "PrCode: %d\n"
                "TransactionAmount: %lf\n\n",
                mPan,
                mPrCode,
                mTransaction.amount);
    }

public:
    uint64_t mPan;                      /* FD-002 */
    std::vector<uint8_t> mPrCode;       /* FD-003 */
    Amount mTransaction;                /* FD-004 */
    Amount mSettlement;                 /* FD-005 */
    Amount mCardholderBilling;          /* FD-006 */
    IsoDateTime mTrxDateTime;           /* FD-007 */

    int32_t mCardholderConvRate;        /* FD-010 */

    //PosDataCode mPosDataCode;           /* FD-022 */
    std::vector<uint32_t> mPosDataCode; /* FD-022 */

    int mNetInternationalId;            /* FD-024 */
    int mFunctionCode;                  /* FD-024 */
};

#endif // MESSAGE_H
