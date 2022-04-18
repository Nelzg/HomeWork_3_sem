#pragma once
#include "../../../src/Ball.h"
class IConstraint
{
public:
	Ball* balls[2];
	virtual void Handle() = 0;
};


