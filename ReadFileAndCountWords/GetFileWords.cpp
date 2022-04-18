#include "GetFileWords.h"

bool compare_(const Statistics& lhs, const Statistics& rhs)
{
	return lhs.count == rhs.count ? lhs.name < rhs.name : lhs.count < rhs.count;
}
