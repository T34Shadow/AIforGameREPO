

#include "Game.h"

#include <string>


Game::Game()
{
    std::vector<std::string> map;
    int cellSize = 32;
    //ASCII art map
    //--------------------------------------------------------------------------------------
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

    maze.Initialise(map, cellSize);
    //--------------------------------------------------------------------------------------

    start = nullptr;
    end = nullptr;

}

Game::~Game()
{
	
}

void Game::Update()
{
    
    //set the end pos
    if (IsMouseButtonPressed(1))
    {
        std::cout << "right mouse button pressed" << std::endl;
        std::cout << "Set end pos" << std::endl;

        Vector2 mousePos = GetMousePosition();
        end = maze.GetClosestNode(Vector2{ mousePos.x, mousePos.y });
        std::cout << end->pos.x << ":" << end->pos.y << std::endl;
    }

    //set the start pos
    if (IsMouseButtonPressed(0))
    {
        std::cout << "left mouse button pressed" << std::endl;
        std::cout << "Set start pos" << std::endl;

        Vector2 mousePos = GetMousePosition();
        start = maze.GetClosestNode(Vector2{ mousePos.x, mousePos.y });
        std::cout << start->pos.x << ":" << start->pos.y << std::endl;
    }
    if (start != nullptr && end != nullptr)
    {
        nodePath = DijkstrasSearch(start, end);
        pathColour = { 255,255,255,255 };

    }
}

void Game::Draw()
{
    maze.DrawMap();
    if (IsKeyPressed(KEY_SPACE))
    {
        DrawPath(nodePath, pathColour);
    }
}

void Game::DrawPath(std::vector<Node*> path, Color pathColour)
{
    for (int i = 1; i < path.size(); i++)
    {
        DrawLine(path[i]->pos.x, path[i]->pos.y, path[i]->previous->pos.x, path[i]->previous->pos.y,pathColour);
    }
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
    Node* currentNode = nullptr;
    
    //while the open list is not empty
    while (!openList.empty());
    {
        //sort openlsit by the gScore of each node;
        struct sortBygScore
        {
            bool operator()(Node* a, Node* b) const { return a->gScore < b->gScore; }
        };
        std::sort(openList.begin(), openList.end(),sortBygScore());

        currentNode = openList[0];

        //exit the loop if the current and end node are the same.
        if (currentNode == endNode)
        {
            // break or contunie while loop.

        }

        openList.erase(openList.begin()); //remove current node from the open list
        closedList.push_back(currentNode); //add current node to the closed list

        for (int i = 0; i < currentNode->connections.size(); i++)
        {
            // is the node in the closed list
            if (std::find(closedList.begin(), closedList.end(), currentNode->connections[i].target) == closedList.end()) 
            {

                int gScore = currentNode->gScore + currentNode->connections[i].cost;
                openList.push_back(currentNode->connections[i].target);

                // is the node in the openlist
                if (std::find(openList.begin(), openList.end(), currentNode->connections[i].target) == openList.end()) 
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
    std::vector<Node*> newPath;
    
    currentNode = endNode;
    while (currentNode != nullptr)
    {
        newPath.push_back(currentNode);
        currentNode = currentNode->previous;
    }

    return newPath;
}


