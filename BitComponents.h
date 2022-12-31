#ifndef BIT_COMPONENTS_H
#define BIT_COMPONENTS_H

#include "Component.h"
#include <vector>
#include <string>

class Bit001Component : public Component
{
public:
	Bit001Component(class Iso* owner, std::string txnSubStr = "", int processOrder = 1) : Component(owner)
	{
		mBitString = txnSubStr;
		mProcessOrder = processOrder;
	}
	~Bit001Component() = default;

private:
};

class Bit002Component : public Component
{
public:
	Bit002Component(class Iso* owner, std::string txnSubStr = "", int processOrder = 2) : Component(owner)
	{
		mBitString = txnSubStr;
		mProcessOrder = processOrder;
	}
	~Bit002Component() = default;

private:
};

class Bit003Component : public Component
{
public:
	Bit003Component(class Iso* owner, std::string txnSubStr = "", int processOrder = 3) : Component(owner)
	{
		mBitString = txnSubStr;
		mProcessOrder = processOrder;
	}
	~Bit003Component() = default;

private:
};

class Bit004Component : public Component
{
public:
	Bit004Component(class Iso* owner, std::string txnSubStr = "", int processOrder = 4) : Component(owner)
	{
		mBitString = txnSubStr;
		mProcessOrder = processOrder;
	}
	~Bit004Component() = default;

private:
};

#endif // BIT_COMPONENTS_H
