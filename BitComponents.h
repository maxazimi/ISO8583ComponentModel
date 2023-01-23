#ifndef BIT_COMPONENTS_H
#define BIT_COMPONENTS_H

#include "IsoParser.h"
#include "Iso.h"
#include "Component.h"
#include "Util.h"

/*
 * FD-002 Component Class
 * ISO-1987: PAN
 * ISO-1993: PAN
 * ISO-2003: PAN
 */
class Bit002Component : public Component
{
  public:
    Bit002Component(class Iso* owner, int processOrder = 2) : Component(owner, 2) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
        mOwner->SetField002(mBitString);
    }

    void PutBit() override
    {
        mOutFieldString = ConvertToString(mOwner->GetField002());
        mOwner->AppendFieldString(mOutFieldString);
    }
};

/*
 * FD-003 Component Class
 * ISO-1987: PrCode
 * ISO-1993: PrCode
 * ISO-2003: PrCode
 */
class Bit003Component : public Component
{
  public:
    Bit003Component(class Iso* owner, int processOrder = 3) : Component(owner, 3) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
        mOwner->SetField003(mSubBitStrVec);
    }

    void PutBit() override
    {
        mOutFieldString = ConvertToString(mOwner->GetField003());
        mOwner->AppendFieldString(mOutFieldString);
    }
};

/*
 * FD-004 Component Class
 * ISO-1987: Transaction Amount
 * ISO-1993: Transaction Amount
 * ISO-2003: Transaction Amount
 */
class Bit004Component : public Component
{
  public:
    Bit004Component(class Iso* owner, int processOrder = 4) : Component(owner, 4) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
        mOwner->SetField004(mSubBitStrVec);
    }

    void PutBit() override
    {
        mOutFieldString = mOwner->GetField004();
        mOwner->AppendFieldString(mOutFieldString);
    }
};

/*
 * FD-005 Component Class
 * ISO-1987: Settlement Amount
 * ISO-1993: Reconciliation Amount
 * ISO-2003: Reconciliation Amount
 */
class Bit005Component : public Component
{
  public:
    Bit005Component(class Iso* owner, int processOrder = 5) : Component(owner, 5) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
        mOwner->SetField005(mSubBitStrVec);
    }
};

/*
 * FD-006 Component Class
 * ISO-1987: Cardholder Billing Amount
 * ISO-1993: Cardholder Billing Amount
 * ISO-2003: Cardholder Billing Amount
 */
class Bit006Component : public Component
{
  public:
    Bit006Component(class Iso* owner, int processOrder = 6) : Component(owner, 6) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
        mOwner->SetField006(mSubBitStrVec);
    }
};

/*
 * FD-007 Component Class
 * ISO-1987: Transmission Date & Time
 * ISO-1993: Transmission Date & Time
 * ISO-2003: Transmission Date & Time
 */
class Bit007Component : public Component
{
public:
    Bit007Component(class Iso* owner, int processOrder = 7) : Component(owner, 7) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();

        /*
         * MMDDhhmmss
         */
        IsoDateTime trxDateTime;
        trxDateTime.MM = std::stoi(mBitString.substr(0, 2));
        trxDateTime.DD = std::stoi(mBitString.substr(2, 4));
        trxDateTime.hh = std::stoi(mBitString.substr(4, 6));
        trxDateTime.mm = std::stoi(mBitString.substr(6, 8));
        trxDateTime.ss = std::stoi(mBitString.substr(8, 10));

        mOwner->SetField007(trxDateTime);
    }
};

/*
 * FD-008 Component Class
 * ISO-1987: Cardholder Billing Fee Amount
 * ISO-1993: Cardholder Billing Fee Amount
 * ISO-2003: Cardholder Billing Fee Amount
 */
class Bit008Component : public Component
{
public:
    Bit008Component(class Iso* owner, int processOrder = 8) : Component(owner, 8) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-009 Component Class
 * ISO-1987: Settlement Conversion Rate
 * ISO-1993: Reconciliation Conversion Rate
 * ISO-2003: Reconciliation Conversion Rate
 */
class Bit009Component : public Component
{
public:
    Bit009Component(class Iso* owner, int processOrder = 9) : Component(owner, 9) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-010 Component Class
 * ISO-1987: Cardholder Billing Conversion Rate
 * ISO-1993: Cardholder Billing Conversion Rate
 * ISO-2003: Cardholder Billing Conversion Rate
 */
class Bit010Component : public Component
{
public:
    Bit010Component(class Iso* owner, int processOrder = 10) : Component(owner, 10) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-011 Component Class
 * ISO-1987: System Trace Audit Number
 * ISO-1993: System Trace Audit Number
 * ISO-2003: System Trace Audit Number
 */
class Bit011Component : public Component
{
public:
    Bit011Component(class Iso* owner, int processOrder = 11) : Component(owner, 11) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-012 Component Class
 * ISO-1987: Transaction Local Time
 * ISO-1993: Transaction Local Date & Time
 * ISO-2003: Transaction Local Date & Time
 */
class Bit012Component : public Component
{
public:
    Bit012Component(class Iso* owner, int processOrder = 12) : Component(owner, 12) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-013 Component Class
 * ISO-1987: Local Transaction Date
 * ISO-1993: Effective Date
 * ISO-2003: Effective Date
 */
class Bit013Component : public Component
{
public:
    Bit013Component(class Iso* owner, int processOrder = 13) : Component(owner, 13) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-014 Component Class
 * ISO-1987: Expiration Date
 * ISO-1993: Expiration Date
 * ISO-2003: Expiration Date
 */
class Bit014Component : public Component
{
public:
    Bit014Component(class Iso* owner, int processOrder = 14) : Component(owner, 14) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-015 Component Class
 * ISO-1987: Settlement Date
 * ISO-1993: Settlement Date
 * ISO-2003: Settlement Date
 */
class Bit015Component : public Component
{
public:
    Bit015Component(class Iso* owner, int processOrder = 15) : Component(owner, 15) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-016 Component Class
 * ISO-1987: Conversion Date
 * ISO-1993: Conversion Date
 * ISO-2003: Conversion Date
 */
class Bit016Component : public Component
{
public:
    Bit016Component(class Iso* owner, int processOrder = 16) : Component(owner, 16) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-017 Component Class
 * ISO-1987: Capture Date
 * ISO-1993: Capture Date
 * ISO-2003: Capture Date
 */
class Bit017Component : public Component
{
public:
    Bit017Component(class Iso* owner, int processOrder = 17) : Component(owner, 17) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-018 Component Class
 * ISO-1987: Merchant Type
 * ISO-1993: Merchant Type
 * ISO-2003: Message Error Indicator
 */
class Bit018Component : public Component
{
public:
    Bit018Component(class Iso* owner, int processOrder = 18) : Component(owner, 18) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-019 Component Class
 * ISO-1987: Acquiring Institution Country Code
 * ISO-1993: Acquiring Institution Country Code
 * ISO-2003: Acquiring Institution Country Code
 */
class Bit019Component : public Component
{
public:
    Bit019Component(class Iso* owner, int processOrder = 19) : Component(owner, 19) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-020 Component Class
 * ISO-1987: PAN Country Code
 * ISO-1993: PAN Country Code
 * ISO-2003: PAN Country Code
 */
class Bit020Component : public Component
{
public:
    Bit020Component(class Iso* owner, int processOrder = 20) : Component(owner, 20) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-021 Component Class
 * ISO-1987: Forwarding Institution Country Code
 * ISO-1993: Forwarding Institution Country Code
 * ISO-2003: Transaction Life Cycle Identification Data
 */
class Bit021Component : public Component
{
public:
    Bit021Component(class Iso* owner, int processOrder = 21) : Component(owner, 21) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-022 Component Class
 * ISO-1987: POS Entry Mode
 * ISO-1993: POS Data Code
 * ISO-2003: POS Data Code
 */
class Bit022Component : public Component
{
public:
    Bit022Component(class Iso* owner, int processOrder = 22) : Component(owner, 22) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
        mOwner->SetField022(mBitString);
    }

    void PutBit() override
    {

    }
};

/*
 * FD-023 Component Class
 * ISO-1987: Card Sequence Number
 * ISO-1993: Card Sequence Number
 * ISO-2003: Card Sequence Number
 */
class Bit023Component : public Component
{
public:
    Bit023Component(class Iso* owner, int processOrder = 23) : Component(owner, 23) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-024 Component Class
 * ISO-1987: Network International Identifier
 * ISO-1993: Function Code
 * ISO-2003: Function Code
 */
class Bit024Component : public Component
{
public:
    Bit024Component(class Iso* owner, int processOrder = 24) : Component(owner, 24) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
        mOwner->SetField024(mBitString);
    }
};

/*
 * FD-025 Component Class
 * ISO-1987: POS Condition Code
 * ISO-1993: Message Reason Code
 * ISO-2003: Message Reason Code
 */
class Bit025Component : public Component
{
public:
    Bit025Component(class Iso* owner, int processOrder = 25) : Component(owner, 25) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-026 Component Class
 * ISO-1987: POS Pin Capture Code
 * ISO-1993: Card Acceptor Business Code
 * ISO-2003: Merchant Category Code
 */
class Bit026Component : public Component
{
public:
    Bit026Component(class Iso* owner, int processOrder = 26) : Component(owner, 26) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-027 Component Class
 * ISO-1987: Authorization Identification Response Length
 * ISO-1993: Approval Code Length
 * ISO-2003: POS Capability
 */
class Bit027Component : public Component
{
public:
    Bit027Component(class Iso* owner, int processOrder = 27) : Component(owner, 27) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-028 Component Class
 * ISO-1987: Transaction Fee Amount
 * ISO-1993: Reconciliation Date
 * ISO-2003: Reconciliation Date
 */
class Bit028Component : public Component
{
public:
    Bit028Component(class Iso* owner, int processOrder = 28) : Component(owner, 28) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-029 Component Class
 * ISO-1987: Settlement Fee Amount
 * ISO-1993: Reconciliation Indicator
 * ISO-2003: Reconciliation Indicator
 */
class Bit029Component : public Component
{
public:
    Bit029Component(class Iso* owner, int processOrder = 29) : Component(owner, 29) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-030 Component Class
 * ISO-1987: Transaction Processing Fee Amount
 * ISO-1993: Original Amounts
 * ISO-2003: Original Amounts
 */
class Bit030Component : public Component
{
public:
    Bit030Component(class Iso* owner, int processOrder = 30) : Component(owner, 30) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-031 Component Class
 * ISO-1987: Settlement Processing Fee Amount
 * ISO-1993: Acquirer Reference Data
 * ISO-2003: Acquirer Reference Number
 */
class Bit031Component : public Component
{
public:
    Bit031Component(class Iso* owner, int processOrder = 31) : Component(owner, 31) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-032 Component Class
 * ISO-1987: Acquiring Institution Identification Code
 * ISO-1993: Acquiring Institution Identification Code
 * ISO-2003: Acquiring Institution Identification Code
 */
class Bit032Component : public Component
{
public:
    Bit032Component(class Iso* owner, int processOrder = 32) : Component(owner, 32) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-033 Component Class
 * ISO-1987: Forwarding Institution Identification Code
 * ISO-1993: Forwarding Institution Identification Code
 * ISO-2003: Forwarding Institution Identification Code
 */
class Bit033Component : public Component
{
public:
    Bit033Component(class Iso* owner, int processOrder = 33) : Component(owner, 33) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-034 Component Class
 * ISO-1987: PAN Extended
 * ISO-1993: PAN Extended
 * ISO-2003: Electronic Commerce Data
 */
class Bit034Component : public Component
{
public:
    Bit034Component(class Iso* owner, int processOrder = 34) : Component(owner, 34) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-035 Component Class
 * ISO-1987: Track 2 Data
 * ISO-1993: Track 2 Data
 * ISO-2003: Track 2 Data
 */
class Bit035Component : public Component
{
public:
    Bit035Component(class Iso* owner, int processOrder = 35) : Component(owner, 35) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-036 Component Class
 * ISO-1987: Track 3 Data
 * ISO-1993: Track 3 Data
 * ISO-2003: Track 3 Data
 */
class Bit036Component : public Component
{
public:
    Bit036Component(class Iso* owner, int processOrder = 36) : Component(owner, 36) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-037 Component Class
 * ISO-1987: Retrieval Reference Number
 * ISO-1993: Retrieval Reference Number
 * ISO-2003: Retrieval Reference Number
 */
class Bit037Component : public Component
{
public:
    Bit037Component(class Iso* owner, int processOrder = 37) : Component(owner, 37) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-038 Component Class
 * ISO-1987: Authorization Identification Response
 * ISO-1993: Approval Code
 * ISO-2003: Approval Code
 */
class Bit038Component : public Component
{
public:
    Bit038Component(class Iso* owner, int processOrder = 38) : Component(owner, 38) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-039 Component Class
 * ISO-1987: Response Code
 * ISO-1993: Action Code
 * ISO-2003: Action Code
 */
class Bit039Component : public Component
{
public:
    Bit039Component(class Iso* owner, int processOrder = 39) : Component(owner, 39) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-040 Component Class
 * ISO-1987: Service Restriction Code
 * ISO-1993: Service Code
 * ISO-2003: Service Code
 */
class Bit040Component : public Component
{
public:
    Bit040Component(class Iso* owner, int processOrder = 40) : Component(owner, 40) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-041 Component Class
 * ISO-1987: Card Acceptor Terminal Identification
 * ISO-1993: Card Acceptor Terminal Identification
 * ISO-2003: Card Acceptor Terminal Identification
 */
class Bit041Component : public Component
{
public:
    Bit041Component(class Iso* owner, int processOrder = 41) : Component(owner, 41) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-042 Component Class
 * ISO-1987: Card Acceptor Identification Code
 * ISO-1993: Card Acceptor Identification Code
 * ISO-2003: Card Acceptor Identification Code
 */
class Bit042Component : public Component
{
public:
    Bit042Component(class Iso* owner, int processOrder = 42) : Component(owner, 42) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-043 Component Class
 * ISO-1987: Card Acceptor Name/Location
 * ISO-1993: Card Acceptor Name/Location
 * ISO-2003: Card Acceptor Name/Location
 */
class Bit043Component : public Component
{
public:
    Bit043Component(class Iso* owner, int processOrder = 43) : Component(owner, 43) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-044 Component Class
 * ISO-1987: Additional Response Data
 * ISO-1993: Additional Response Data
 * ISO-2003: Additional Response Data
 */
class Bit044Component : public Component
{
public:
    Bit044Component(class Iso* owner, int processOrder = 44) : Component(owner, 44) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-045 Component Class
 * ISO-1987: Track 1 Data
 * ISO-1993: Track 1 Data
 * ISO-2003: Track 1 Data
 */
class Bit045Component : public Component
{
public:
    Bit045Component(class Iso* owner, int processOrder = 45) : Component(owner, 45) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-046 Component Class
 * ISO-1987: Additional Data - ISO
 * ISO-1993: Fees Amounts
 * ISO-2003: Fees Amounts
 */
class Bit046Component : public Component
{
public:
    Bit046Component(class Iso* owner, int processOrder = 46) : Component(owner, 46) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-047 Component Class
 * ISO-1987: Additional Data - National
 * ISO-1993: Additional Data - National
 * ISO-2003: Additional Data - National
 */
class Bit047Component : public Component
{
public:
    Bit047Component(class Iso* owner, int processOrder = 47) : Component(owner, 47) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-048 Component Class
 * ISO-1987: Additional Data - Private
 * ISO-1993: Additional Data - Private
 * ISO-2003: Additional Data - Private
 */
class Bit048Component : public Component
{
public:
    Bit048Component(class Iso* owner, int processOrder = 48) : Component(owner, 48) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-049 Component Class
 * ISO-1987: Transaction Currency Code
 * ISO-1993: Transaction Currency Code
 * ISO-2003: Verification Data
 */
class Bit049Component : public Component
{
public:
    Bit049Component(class Iso* owner, int processOrder = 49) : Component(owner, 49) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-050 Component Class
 * ISO-1987: Settlement Currency Code
 * ISO-1993: Reconciliation Currency Code
 * ISO-2003: Reserved for ISO use
 */
class Bit050Component : public Component
{
public:
    Bit050Component(class Iso* owner, int processOrder = 50) : Component(owner, 50) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-051 Component Class
 * ISO-1987: Cardholder Billing Currency Code
 * ISO-1993: Cardholder Billing Currency Code
 * ISO-2003: Reserved for ISO use
 */
class Bit051Component : public Component
{
public:
    Bit051Component(class Iso* owner, int processOrder = 51) : Component(owner, 51) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-052 Component Class
 * ISO-1987: PIN Data
 * ISO-1993: PIN Data
 * ISO-2003: PIN Data
 */
class Bit052Component : public Component
{
public:
    Bit052Component(class Iso* owner, int processOrder = 52) : Component(owner, 52) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-053 Component Class
 * ISO-1987: Security Related Control Information
 * ISO-1993: Security Related Control Information
 * ISO-2003: Security Related Control Information
 */
class Bit053Component : public Component
{
public:
    Bit053Component(class Iso* owner, int processOrder = 53) : Component(owner, 53) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-054 Component Class
 * ISO-1987: Additional Amounts
 * ISO-1993: Additional Amounts
 * ISO-2003: Additional Amounts
 */
class Bit054Component : public Component
{
public:
    Bit054Component(class Iso* owner, int processOrder = 54) : Component(owner, 54) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-055 Component Class
 * ISO-1987: Reserved for ISO use
 * ISO-1993: ICC System Related Data
 * ISO-2003: ICC System Related Data
 */
class Bit055Component : public Component
{
public:
    Bit055Component(class Iso* owner, int processOrder = 55) : Component(owner, 55) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-056 Component Class
 * ISO-1987: Reserved for ISO use
 * ISO-1993: Original Data Elements
 * ISO-2003: Original Data Elements
 */
class Bit056Component : public Component
{
public:
    Bit056Component(class Iso* owner, int processOrder = 56) : Component(owner, 56) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-057 Component Class
 * ISO-1987: Reserved for National use
 * ISO-1993: Authorization Life Cycle Code
 * ISO-2003: Authorization Life Cycle Code
 */
class Bit057Component : public Component
{
public:
    Bit057Component(class Iso* owner, int processOrder = 57) : Component(owner, 57) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-058 Component Class
 * ISO-1987: Reserved for National use
 * ISO-1993: Authorizing Agent Institution Identification Code
 * ISO-2003: Authorizing Agent Institution Identification Code
 */
class Bit058Component : public Component
{
public:
    Bit058Component(class Iso* owner, int processOrder = 58) : Component(owner, 58) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-059 Component Class
 * ISO-1987: Reserved for National use
 * ISO-1993: Transport Data
 * ISO-2003: Transport Data
 */
class Bit059Component : public Component
{
public:
    Bit059Component(class Iso* owner, int processOrder = 59) : Component(owner, 59) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-060 Component Class
 * ISO-1987: Reserved for Private use
 * ISO-1993: Reserved for National use
 * ISO-2003: Reserved for National use
 */
class Bit060Component : public Component
{
public:
    Bit060Component(class Iso* owner, int processOrder = 60) : Component(owner, 60) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-061 Component Class
 * ISO-1987: Reserved for Private use
 * ISO-1993: Reserved for National use
 * ISO-2003: Reserved for National use
 */
class Bit061Component : public Component
{
public:
    Bit061Component(class Iso* owner, int processOrder = 61) : Component(owner, 61) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-062 Component Class
 * ISO-1987: Reserved for Private use
 * ISO-1993: Reserved for Private use
 * ISO-2003: Reserved for Private use
 */
class Bit062Component : public Component
{
public:
    Bit062Component(class Iso* owner, int processOrder = 62) : Component(owner, 62) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-063 Component Class
 * ISO-1987: Reserved for Private use
 * ISO-1993: Reserved for Private use
 * ISO-2003: Reserved for Private use
 */
class Bit063Component : public Component
{
public:
    Bit063Component(class Iso* owner, int processOrder = 63) : Component(owner, 63) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-064 Component Class
 * ISO-1987: MAC Field
 * ISO-1993: MAC Field
 * ISO-2003: MAC Field
 */
class Bit064Component : public Component
{
public:
    Bit064Component(class Iso* owner, int processOrder = 64) : Component(owner, 64) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-065 Component Class
 * ISO-1987: Extended Bitmap
 * ISO-1993: Reserved for ISO use
 * ISO-2003: Reserved for ISO use
 */
class Bit065Component : public Component
{
public:
    Bit065Component(class Iso* owner, int processOrder = 65) : Component(owner, 65) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-066 Component Class
 * ISO-1987: Settlement Code
 * ISO-1993: Original Fees Amounts
 * ISO-2003: Original Fees Amounts
 */
class Bit066Component : public Component
{
public:
    Bit066Component(class Iso* owner, int processOrder = 66) : Component(owner, 66) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-067 Component Class
 * ISO-1987: Extended Payment Code
 * ISO-1993: Extended Payment Data
 * ISO-2003: Extended Payment Data
 */
class Bit067Component : public Component
{
public:
    Bit067Component(class Iso* owner, int processOrder = 67) : Component(owner, 67) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-068 Component Class
 * ISO-1987: Receiving Institution Country Code
 * ISO-1993: Receiving Institution Country Code
 * ISO-2003: Batch/File Transfer Message Control
 */
class Bit068Component : public Component
{
public:
    Bit068Component(class Iso* owner, int processOrder = 68) : Component(owner, 68) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-069 Component Class
 * ISO-1987: Settlement Institution Country Code
 * ISO-1993: Settlement Institution Country Code
 * ISO-2003: Batch/File Transfer Control Data
 */
class Bit069Component : public Component
{
public:
    Bit069Component(class Iso* owner, int processOrder = 69) : Component(owner, 69) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-070 Component Class
 * ISO-1987: Network Management Information Code
 * ISO-1993: Authorizing Agent Institution Country Code
 * ISO-2003: File Transfer Description Data
 */
class Bit070Component : public Component
{
public:
    Bit070Component(class Iso* owner, int processOrder = 70) : Component(owner, 70) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-071 Component Class
 * ISO-1987: Message Number
 * ISO-1993: Message Number
 * ISO-2003: Reserved for ISO use
 */
class Bit071Component : public Component
{
public:
    Bit071Component(class Iso* owner, int processOrder = 71) : Component(owner, 71) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-072 Component Class
 * ISO-1987: Message Number Last
 * ISO-1993: Data Record
 * ISO-2003: Data Record
 */
class Bit072Component : public Component
{
public:
    Bit072Component(class Iso* owner, int processOrder = 72) : Component(owner, 72) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-073 Component Class
 * ISO-1987: Action Date
 * ISO-1993: Action Date
 * ISO-2003: Action Date
 */
class Bit073Component : public Component
{
public:
    Bit073Component(class Iso* owner, int processOrder = 73) : Component(owner, 73) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-074 Component Class
 * ISO-1987: Credits Number
 * ISO-1993: Credits Number
 * ISO-2003: Data Primary Reconciliation
 */
class Bit074Component : public Component
{
public:
    Bit074Component(class Iso* owner, int processOrder = 74) : Component(owner, 74) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-075 Component Class
 * ISO-1987: Reversal Number Credits
 * ISO-1993: Reversal Number Credits
 * ISO-2003: Data Secondary Reconciliation
 */
class Bit075Component : public Component
{
public:
    Bit075Component(class Iso* owner, int processOrder = 75) : Component(owner, 75) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-076 Component Class
 * ISO-1987: 
 * ISO-1993: 
 * ISO-2003: Reserved for ISO use
 */
class Bit076Component : public Component
{
public:
    Bit076Component(class Iso* owner, int processOrder = 76) : Component(owner, 76) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-077 Component Class
 * ISO-1987: 
 * ISO-1993: 
 * ISO-2003: Reserved for ISO use
 */
class Bit077Component : public Component
{
public:
    Bit077Component(class Iso* owner, int processOrder = 77) : Component(owner, 77) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-078 Component Class
 * ISO-1987: 
 * ISO-1993: 
 * ISO-2003: Reserved for ISO use
 */
class Bit078Component : public Component
{
public:
    Bit078Component(class Iso* owner, int processOrder = 78) : Component(owner, 78) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-079 Component Class
 * ISO-1987: 
 * ISO-1993: 
 * ISO-2003: Reserved for ISO use
 */
class Bit079Component : public Component
{
public:
    Bit079Component(class Iso* owner, int processOrder = 79) : Component(owner, 79) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

/*
 * FD-080 Component Class
 * ISO-1987: 
 * ISO-1993: 
 * ISO-2003: Reserved for ISO use
 */
class Bit080Component : public Component
{
public:
    Bit080Component(class Iso* owner, int processOrder = 80) : Component(owner, 80) { mProcessOrder = processOrder; }

    void GetBit() override
    {
        Component::GetBit();
    }
};

#endif // BIT_COMPONENTS_H
