#pragma once
#include "NodeMap.h"
#include "vector"
#include <algorithm>

class Game
{
public:

	Game();
	~Game();

	void Update();
	void Draw();

	void DrawPath(std::vector<Node*> path, Color pathColour);
	std::vector<Node*>DijkstrasSearch(Node* startNode, Node* endNode);

private:
	NodeMap maze;
	Node* start;
	Node* end;
	std::vector<Node*> nodePath;
	Color pathColour;
};