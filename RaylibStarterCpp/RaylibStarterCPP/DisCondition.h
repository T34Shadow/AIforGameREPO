#pragma once
#include "Condition.h"

class DistanceCondition : public Condition
{
private:
	float m_dis;
	bool m_lessThan;

public:
	DistanceCondition(float d, bool lessThen) : m_dis(d), m_lessThan(lessThen) {}
	virtual bool IsTrue(Agent* agent);
};