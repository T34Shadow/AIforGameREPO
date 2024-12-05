#include "State.h"

State::State()
{
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
