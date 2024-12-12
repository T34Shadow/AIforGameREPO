#include "FSM.h"

FiniteStateMechine::~FiniteStateMechine()
{
	for (State* s : m_state)
	{
		delete s;
	}
}

void FiniteStateMechine::AddState(State* _state)
{
	m_state.push_back(_state);
}

void FiniteStateMechine::Update(Agent* agent, float delta)
{
	State* newState = nullptr;

	//check the current state's transition
	for (State::Transition t : m_currentState->GetTransitions())
	{
		if (t.m_condition->IsTrue(agent))
		{
			newState = t.m_targetState;
		}
	}

	//if we have not chnaged state clean up the old one and initialise the new one
	if (newState != nullptr && newState != m_currentState)
	{
		m_currentState->Exit(agent);
		m_currentState = newState;
		m_currentState->Enter(agent);
	}

	//update the current state
	m_currentState->Update(agent, delta);
}

void FiniteStateMechine::Enter(Agent* agent)
{
	m_currentState->Enter(agent);
}
