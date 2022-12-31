#ifndef ISO_PARSER_H
#define ISO_PARSER_H

#include <algorithm>
#include "Iso.h"

class IsoParser // Engine
{
public:
	IsoParser();
	~IsoParser();

	void AddIso(class Iso* iso);
	void RemoveIso(class Iso* iso);
	
private:
	std::vector<class Iso*> mIsos;
};

#endif // ISO_PARSER_H
