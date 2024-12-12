#pragma once
#include "NodeMap.h"
class Agent;
class PathAgent
{
private:
	Vector2 pos;
	int currentIndex;
	Node* currentNode;
	float speed;	
	Vector2 direction;
	std::vector<Node*> path;

public:

	void Update(float delta);
	void GoToNode(Node* node);
	void Draw();

	PathAgent* GetTarget();

	void SetPos(Vector2 pos);
	void SetNode(Node* node);
	void SetSpeed(float speed);
	void SetColour(Color _color);

	std::vector<Node*> GetPath();
	Node* GetNode();
	Vector2 GetPos();
	Color colour;
};