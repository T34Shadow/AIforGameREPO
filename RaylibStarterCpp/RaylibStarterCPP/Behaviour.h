#pragma once
#include <raymath.h>
#include <vector>


class Agent;
class Node;
class Behaviour
{
public:
	virtual void Update(Agent* agent, float delta) = 0;
	virtual ~Behaviour() = default;

	virtual void Enter(Agent* agent) {}
	virtual void Exit(Agent* agent) {}

	virtual float Evaluate(Agent* agent) { return 0.0f; }
};

class WanderBehaviour : public Behaviour
{
public:
	virtual void Update(Agent* agent, float delta);
	virtual float Evaluate(Agent* _agent);
};

class FollowBehaviour : public Behaviour
{
private:
	Vector2 targetPos;
	Node* targetNode;

public:
	virtual void Update(Agent* agent, float delta);
	virtual float Evaluate(Agent* _agent);
};