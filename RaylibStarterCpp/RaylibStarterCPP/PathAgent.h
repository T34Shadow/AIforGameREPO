#pragma once
#include "NodeMap.h"
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

	void SetPos(Vector2 pos);
	void SetNode(Node* node);
	void SetSpeed(float speed);

	std::vector<Node*> GetPath();
	Node* GetNode();
	Vector2 GetPos();
	std::vector<Node*>DijkstrasSearch(Node* startNode, Node* endNode);
};