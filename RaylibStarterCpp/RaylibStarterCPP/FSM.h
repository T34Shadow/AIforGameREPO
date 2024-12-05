#pragma once
#include "Behaviour.h"
#include "State.h"
class FiniteStateMechine : public Behaviour
{
private:
	std::vector<State*> m_state;

	State* m_currentState;
	State* m_newState;

public:
	FiniteStateMechine(State* _state) : m_currentState(_state), m_newState(nullptr) {}
	virtual ~FiniteStateMechine();

	void Update(Agent* agent, float delta);
	
};