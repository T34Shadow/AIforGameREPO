#pragma once
#include "NodeMap.h"
#include "vector"

class Game
{
public:

	Game();
	~Game();

	void Update();
	void Draw();

	std::vector<Node*>DijkstrasSearch(Node* startNode, Node* endNode);


private:
	NodeMap maze;
};