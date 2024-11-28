#pragma once
#include "Node.h"
class PathAgent
{
private:
	Vector2 pos;
	std::vector<Node*> path;
	int currentIndex;
	Node* currentNode;
	float speed;	

public:

	void Update();
	void GoToNode(Node* node);
	void Draw();
};