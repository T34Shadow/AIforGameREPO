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
	m_transitions.emplace_back(_condition, _behaviour);
}

void State::Enter(Agent* agent)
{
	for (Behaviour* b : m_behaviours)
	{
		b->Enter(agent);
	}
}

void State::Exit(Agent* agent)
{
	for (Behaviour* b : m_behaviours)
	{
		b->Exit(agent);
	}
}

std::vector<State::Transition> State::GetTransitions()
{
	return m_transitions;
}

State::Transition::Transition(Condition* _condition, State* _State) : m_condition(_condition), m_targetState(_State) {}
