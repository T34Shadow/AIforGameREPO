

#include "Game.h"

#include <string>


Game::Game()
{
    std::vector<std::string> map;
    map.push_back("0000000000000000");
    map.push_back("0101111111111110");
    map.push_back("0101000001000010");
    map.push_back("0111011111110010");
    map.push_back("0101110000011110");
    map.push_back("0100011111010000");
    map.push_back("0101110001111110");
    map.push_back("0100011111000010");
    map.push_back("0111110001111110");
    map.push_back("0000000000000000");

   
    int cellSize = 32;
    maze.Initialise(map, cellSize);
}

Game::~Game()
{
	
}

void Game::Update()
{
	
}

void Game::Draw()
{
    maze.DrawMap();
}

std::vector<Node*> Game::DijkstrasSearch(Node* startNode, Node* endNode)
{
    //Validate the input
    if (startNode == nullptr || endNode == nullptr)
    {
        std::cout << "Invaild Input" << std::endl;
        return std::vector<Node*>();
    }
    if (startNode == endNode)
    {
        std::cout << "Emtpy path, start and end node are the same" << std::endl;
        std::vector<Node*>path;
        path.push_back(startNode);
        return path;
    }

    //Initialise the starting node
    startNode->gScore = 0;
    startNode->previous = nullptr;

    //Create temp list for storing nodes we have visited 
    std::vector<Node*> openList;
    std::vector<Node*>closedList;

    openList.push_back(startNode);


    //while the open list is not empty
    while (!openList.empty());
    {
        //sort openlsit by the gScore of each node;
        struct sortBygScore
        {
            bool operator()(Node* a, Node* b) const { return a->gScore < b->gScore; }
        };
        std::sort(openList.begin(), openList.end(),sortBygScore());

        Node* currentNode = openList[0];

        //exit the loop if the current and end node are the same.
        if (currentNode == endNode)
        {
            // breal or contunie while loop.
        }

        openList.erase(openList.begin()); //remove current node from the open list
        closedList.push_back(currentNode); //add current node to the closed list

        for (int i = 0; i < currentNode->connections.size(); i++)
        {
            if (std::find(closedList.begin(), closedList.end(), currentNode->connections[i].target) == closedList.end()) // is the node in the closed list
            {

                int gScore = currentNode->gScore + currentNode->connections[i].cost;
                openList.push_back(currentNode->connections[i].target);

                if (std::find(openList.begin(), openList.end(), currentNode->connections[i].target) == openList.end()) // is the node in the openlist
                {
                    currentNode->connections[i].target->gScore = gScore;
                    currentNode->connections[i].target->previous = currentNode;
                    openList.push_back(currentNode->connections[i].target);
                }
                else if (gScore < currentNode->connections[i].target->gScore)
                {
                    currentNode->connections[i].target->gScore = gScore;
                    currentNode->connections[i].target->previous = currentNode;
                }
            }            
            
        }




    }


    std::vector<Node*> path;
    return path;
}


