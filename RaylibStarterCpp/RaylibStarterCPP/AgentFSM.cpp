#include "AgentFSM.h"

Agent::Agent()
{
}

Agent::~Agent()
{
	delete m_pathAgent;
	delete m_current;
	//delete m_nodeMap;
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

PathAgent* Agent::GetPathAgent()
{
	return m_pathAgent;
}

bool Agent::PathComplete()
{
	return m_pathAgent->GetPath().empty();
}

