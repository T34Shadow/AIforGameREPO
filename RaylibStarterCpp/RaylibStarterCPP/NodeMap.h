#pragma once

#include "Node.h"

class NodeMap
{
public:

	NodeMap();
	~NodeMap();

	int width, height;
	float cellSize;
	Node** nodes;

	void Initialise(std::vector<std::string> _map, int _cellSize);
	Node* GetNode(int x, int y);
	void DrawMap();

	Node* GetClosestNode(Vector2 worldPos);
private:
};