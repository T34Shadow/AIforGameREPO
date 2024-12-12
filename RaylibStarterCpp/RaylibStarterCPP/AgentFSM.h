#pragma once
#include "PathAgent.h"
#include "AI_Algorithm.h"
#include "Behaviour.h"
class Agent 
{
public:
	Agent();
	Agent(NodeMap* _nodemap, Behaviour* _behaviour, Color _color) : m_current(_behaviour), m_nodeMap(_nodemap), m_color(_color) {}
	Agent(NodeMap* _nodemap, Behaviour* _behaviour, PathAgent* _agent) : m_current(_behaviour), m_nodeMap(_nodemap), m_pathAgent(_agent) 
	{
		m_current->Enter(this);
	}
	~Agent();

	void Update(float delta);
	void Draw();

	NodeMap* GetNodeMap();
	PathAgent* GetPathAgent();
	bool PathComplete();

private:
	PathAgent* m_pathAgent;
	Behaviour* m_current;
	NodeMap* m_nodeMap;
	Color m_color;
};



