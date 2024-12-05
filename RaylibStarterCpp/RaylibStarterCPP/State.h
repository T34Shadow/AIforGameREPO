#pragma once
#include "Condition.h"

class State
{
public:
	struct Transition
	{
		Condition* m_condition;
		State* m_targetState;
	};

private:
	std::vector<Behaviour*> m_behaviours;
	std::vector<Transition> m_transitions;

public:
	State();
	~State();

	virtual void Update(Agent* agent, float delta);

	virtual void Enter(Agent* agent);
	virtual void Exit(Agent* agent);

	std::vector<State::Transition> GetTransitions();
};