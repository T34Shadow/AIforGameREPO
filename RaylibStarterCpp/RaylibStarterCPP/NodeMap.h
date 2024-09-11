#pragma once

#include "Node.h"
#include <vector>
#include <raymath.h>
#include <iostream>

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

};