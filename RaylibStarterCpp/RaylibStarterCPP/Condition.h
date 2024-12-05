#pragma once

#include "AgentFSM.h"

class Condition
{
public:
	virtual ~Condition() = default;
	virtual bool IsTrue(Agent* agent) = 0;
};