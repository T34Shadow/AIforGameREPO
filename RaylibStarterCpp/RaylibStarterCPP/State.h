#pragma once
#include "Condition.h"

class DistanceCondition;
class State
{
public:
	struct Transition
	{
		Transition(Condition* _condition, State* _State);
		Condition* m_condition;
		State* m_targetState;
	};

private:
	std::vector<Behaviour*> m_behaviours;
	std::vector<Transition> m_transitions;

public:
	State();
	State(Behaviour* behaviour);
	~State();

	virtual void Update(Agent* agent, float delta);

	void AddTransition(Condition* condition, State* _behaviour);

	virtual void Enter(Agent* agent);
	virtual void Exit(Agent* agent);

	std::vector<State::Transition> GetTransitions();
};