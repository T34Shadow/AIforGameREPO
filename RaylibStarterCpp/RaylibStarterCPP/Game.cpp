

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

    //Initialise the starting node

    //Create temp list for storing nodes we have visited 

    //while the open list is not empty



    std::vector<Node*> path;
    return path;
}




