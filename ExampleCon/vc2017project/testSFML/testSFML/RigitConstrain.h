#pragma once
#include "IConstraint.h"

class RigitConstrain : public IConstraint
{
	float length;

	void Handle() {
		length = (balls[0]->position - balls[1]->position).len();
	}
};
