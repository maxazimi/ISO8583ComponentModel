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
                mTransactionAmount);
    }

public:
    uint64_t mPan;                      /* FD-002 */
    int32_t mPrCode;                    /* FD-003 */
    Amount mTransactionAmount;          /* FD-004 */
    Amount mSettlementAmount;           /* FD-005 */
    Amount mCardholderBillingAmount;    /* FD-006 */
    IsoDateTime mTrxDateTime;           /* FD-007 */

    int32_t mCardholderConvRate;        /* FD-010 */

    //PosDataCode mPosDataCode;           /* FD-022 */
    std::vector<uint32_t> mPosDataCode; /* FD-022 */

    int mNetInternationalId;            /* FD-024 */
    int mFunctionCode;                  /* FD-024 */
};

#endif // MESSAGE_H
