#pragma once
#include <raymath.h>


class Agent;
class Node;
class Behaviour
{
public:
	virtual void Update(Agent* agent, float delta) = 0;
	virtual ~Behaviour() = default;

	

	virtual void Enter(Agent* agent) {}
	virtual void Exit(Agent* agent) {}
};

class WanderBehaviour : public Behaviour
{
public:
	virtual void Update(Agent* agent, float delta);
};

class FollowBehaviour : public Behaviour
{
private:
	Vector2 targetPos;
	Node* targetNode;

public:
	virtual void Update(Agent* agent, float delta);
};