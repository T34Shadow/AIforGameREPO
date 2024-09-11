#pragma once
#include "vector"

class Dijkstra
{
public:
	Dijkstra();
	~Dijkstra();

private:

	std::vector<Dijkstra*> queue; //smallest to largest;
	std::vector<Dijkstra*> closedList; //nodes already processed;

	Dijkstra* previousNode;
	//Dijkstra* startNode;
	//Dijkstra* endNode;

	int gScore;
	float totalDistance;
};