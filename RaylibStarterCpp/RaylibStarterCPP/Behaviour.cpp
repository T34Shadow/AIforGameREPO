#include "Behaviour.h"
#include "AgentFSM.h"

void WanderBehaviour::Update(Agent* agent, float delta)
{
	if (agent->GetPathAgent()->GetPath().empty())
	{
		Node* RandomNode = agent->GetNodeMap()->GetRandomNode();
		agent->GetPathAgent()->GoToNode(RandomNode);
		std::cout << "wounding" << std::endl;
	}
}

float WanderBehaviour::Evaluate(Agent* _agent)
{
	PathAgent* target = _agent->GetPathAgent()->GetTarget();
	float dis = Vector2Distance(target->GetPos(), _agent->GetPathAgent()->GetPos());

	float evl = dis;
	if (evl < 0) evl = 0;
	return evl;
}


void FollowBehaviour::Update(Agent* agent, float delta)
{
	PathAgent* target = agent->GetPathAgent()->GetTarget();

	float dis = Vector2Distance(target->GetPos(), targetPos);

	if (dis > agent->GetNodeMap()->GetCellSize())
	{
		targetPos = target->GetPos();
		targetNode = target->GetNode();

		if (agent->GetPathAgent()->GetPath().empty())
		{
			agent->GetPathAgent()->GoToNode(targetNode);
			std::cout << "Following" << std::endl;
		}
	}
}

float FollowBehaviour::Evaluate(Agent* _agent)
{
	PathAgent* target = _agent->GetPathAgent()->GetTarget();
	float dis = Vector2Distance(target->GetPos(), _agent->GetPathAgent()->GetPos());

	float evl = 10 * _agent->GetNodeMap()->GetCellSize() - dis;

	if (evl < 0) evl = 0;
	return evl;
}
