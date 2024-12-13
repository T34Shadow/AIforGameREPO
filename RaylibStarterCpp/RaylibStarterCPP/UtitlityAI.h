#pragma once
#include "Behaviour.h"

class UtilityAI : public Behaviour
{
public:
	UtilityAI();
	virtual ~UtilityAI();

	virtual void Update(Agent* agent, float delta);
	void AddBehaviour(Behaviour* _behaviour) { m_behaviours.push_back(_behaviour); }

private:
	std::vector<Behaviour*> m_behaviours;
	Behaviour* currentBehaviour;


};