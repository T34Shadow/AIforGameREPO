#include "UtitlityAI.h"

UtilityAI::UtilityAI()
{
}

UtilityAI::~UtilityAI()
{
	for (Behaviour* b : m_behaviours)
	{
		delete b;
	}
}

void UtilityAI::Update(Agent* agent, float delta)
{

	float bestEvl = 0;
	Behaviour* newBehaviour = nullptr;
	for (Behaviour* b : m_behaviours)
	{
		float evl = b->Evaluate(agent);
		if (evl > bestEvl)
		{
			bestEvl = evl;
			newBehaviour = b;
		}
	}
	if (newBehaviour != nullptr && newBehaviour != currentBehaviour)
	{
		if (currentBehaviour) currentBehaviour->Exit(agent);

		currentBehaviour = newBehaviour;
		currentBehaviour->Enter(agent);
	}
	currentBehaviour->Update(agent, delta);
}
