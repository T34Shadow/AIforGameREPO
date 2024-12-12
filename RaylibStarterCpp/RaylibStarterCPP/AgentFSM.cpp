#include "AgentFSM.h"

Agent::Agent()
{
}

Agent::~Agent()
{
}

void Agent::Update(float delta)
{
	if (m_current != nullptr)
	{
		m_current->Update(this, delta);
	}
	m_pathAgent->Update(delta);
}

void Agent::Draw()
{
	m_pathAgent->Draw();
}

NodeMap* Agent::GetNodeMap()
{
	return m_nodeMap;
}

bool Agent::PathComplete()
{
	return m_pathAgent->GetPath().empty();
}

