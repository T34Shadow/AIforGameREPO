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
	

void FollowBehaviour::Update(Agent* agent, float delta)
{
	PathAgent* target = agent->GetPathAgent()->GetTarget();

	float dis = Vector2Distance(target->GetPos(), targetPos);

	if (dis > agent->GetNodeMap()->GetCellSize())
	{
		targetPos = target->GetPos();
		targetNode = target->GetNode();

		agent->GetPathAgent()->GoToNode(targetNode);
		std::cout << "Following" << std::endl;
	}
}
