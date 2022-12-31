#ifndef BIT_COMPONENTS_H
#define BIT_COMPONENTS_H

#include "Component.h"
#include <vector>
#include <string>

class Bit002Component : public Component
{
public:
	Bit002Component(class Iso* owner, int processOrder = 2);
	~Bit002Component() = default;

private:
};

class Bit003Component : public Component
{
public:
	Bit003Component(class Iso* owner, int processOrder = 3);
	~Bit003Component() = default;

private:
};

class Bit004Component : public Component
{
public:
	Bit004Component(class Iso* owner, int processOrder = 4);
	~Bit004Component() = default;

private:
};

#endif // BIT_COMPONENTS_H
