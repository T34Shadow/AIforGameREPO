#pragma once
#include "PathAgent.h"

class Game
{
public:

	Game();
	~Game();

	void Update(float delta);
	void Draw();

	void DrawPath(std::vector<Node*> path, Color pathColour);

private:
	NodeMap maze;
	Node* start;
	Node* end;
	std::vector<Node*> nodePath;
	Color pathColour{ 255,0,0,255 };
	PathAgent agent;
};