#pragma once
#include "PathAgent.h"
#include "AgentFSM.h"
#include "Behaviour.h"
class FiniteStateMechine;
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
	Color pathColour{ 255,0,0,255 };
	std::vector<Node*> nodePath;

	PathAgent playerAgent;
	Agent* aiAgent01;
};