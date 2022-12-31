#include "IsoParser.h"

IsoParser::IsoParser()
{
}

void IsoParser::AddIso(Iso* iso)
{
	mIsos.emplace_back(iso);
}

void IsoParser::RemoveIso(Iso* iso)
{
	auto iter = std::find(mIsos.begin(), mIsos.end(), iso);
	if (iter != mIsos.end())
	{
		// Swap to end of vector and pop off (avoid erase copies)
		std::iter_swap(iter, mIsos.end() - 1);
		mIsos.pop_back();
	}
}
