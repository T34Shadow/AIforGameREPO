#pragma once
#include <vector>
#include <raymath.h>
#include <string>
#include <iostream>
#include <algorithm>

class Node
{
public:
	Node();
	Node(float x, float y);
	~Node();

	struct Edge
	{
		Node* target;
		float cost;

		Edge() { target = nullptr; cost = 0; }
		Edge(Node* _target, float _cost) : target(_target), cost(_cost) {}
	};

	int gScore;
	int fScore;
	int hScore;
	Node* previous;
	Vector2 pos;
	std::vector<Edge> connections;

	void ConnectTo(Node* other, float cost);
	
};