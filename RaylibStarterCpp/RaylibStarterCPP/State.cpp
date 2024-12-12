#include "State.h"

State::State()
{
}

State::State(Behaviour* behaviour)
{
	m_behaviours.push_back(behaviour);
}

State::~State()
{
	for (Behaviour* b : m_behaviours)
	{
		delete b;
	}
	for (Transition t : m_transitions)
	{
		delete t.m_condition;
	}
}

void State::Update(Agent* agent, float delta)
{
	for (Behaviour* b : m_behaviours)
	{
		b->Update(agent, delta);
	}
}

void State::AddTransition(Condition* _condition, State* _behaviour)
{
	for (int i = 0; i < m_transitions.size(); i++)
	{
		m_transitions[i].m_condition = _condition;
		m_transitions[i].m_targetState = _behaviour;
	}
}

void State::Enter(Agent* agent)
{
	
}

void State::Exit(Agent* agent)
{
}

std::vector<State::Transition> State::GetTransitions()
{
	return m_transitions;
}
