#pragma once
#include "NodeMap.h"

class AI_Algorithm
{
public:

	static std::vector<Node*>DijkstrasSearch(Node* startNode, Node* endNode);
	static std::vector<Node*> AStarSearch(Node* startNode, Node* endNode);
	static float ManhattanDistance(Vector2 a, Vector2 b);
};