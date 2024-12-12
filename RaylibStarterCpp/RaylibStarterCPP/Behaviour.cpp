#include "Behaviour.h"
#include "AgentFSM.h"

void WanderBehaviour::Update(Agent* agent, float delta)
{
	
}

void FollowBehaviour::Update(Agent* agent, float delta)
{
	PathAgent* target = agent->GetTarget();

	float dis = Vector2Distance(target->GetPos(), targetPos);

	if (dis > agent->GetNodeMap()->GetCellSize())
	{
		targetPos = target->GetPos();
		targetNode = target->GetNode();

		agent->GoToNode(targetNode);
	}
}
