

#include "Game.h"




Game::Game()
{
    std::vector<std::string> map;
    int cellSize = 32;
    //ASCII art map
    //--------------------------------------------------------------------------------------
    map.push_back("0000000000000000");
    map.push_back("0101111111111110");
    map.push_back("0101000001000010");
    map.push_back("0101011111110010");
    map.push_back("0101110000011110");
    map.push_back("0100011111000000");
    map.push_back("0111110001111110");
    map.push_back("0100011111000010");
    map.push_back("0101110001111110");
    map.push_back("0000000000000000");

    maze.Initialise(map, cellSize);
    //--------------------------------------------------------------------------------------

    start = nullptr;
    end = nullptr;

    agent.SetSpeed(300);
    agent.SetNode(maze.GetNode(3, 1));
    agent.SetPos(agent.GetNode()->pos);

    

}

Game::~Game()
{
	
}

void Game::Update(float delta)
{
    
    //set the end pos
    if (IsMouseButtonPressed(1))
    {
        //std::cout << "right mouse button pressed" << std::endl;

        Vector2 mousePos = GetMousePosition();
        end = maze.GetClosestNode(Vector2{ mousePos.x, mousePos.y });
        if (end != nullptr)
        {
            std::cout << "Set end pos" << ": ";
            std::cout << end->pos.x << ":" << end->pos.y << std::endl;
        }
    }

    //set the start pos
    if (IsMouseButtonPressed(0))
    {
        //std::cout << "left mouse button pressed" << std::endl;

        Vector2 mousePos = GetMousePosition();
        start = maze.GetClosestNode(Vector2{ mousePos.x, mousePos.y });
        if (start != nullptr)
        {
            std::cout << "Set start pos" << ": ";
            std::cout << start->pos.x << ":" << start->pos.y << std::endl;
        }
    }
    if (IsKeyPressed(KEY_SPACE))
    {
        agent.GoToNode(end);
        std::cout << "Start" << std::endl;
    }
    
    agent.Update(delta);

}

void Game::Draw()
{
    maze.DrawMap();
    agent.Draw();
    if (!agent.GetPath().empty())
    {
        DrawPath(agent.GetPath(), pathColour);
    }
}

void Game::DrawPath(std::vector<Node*> path, Color pathColour)
{
    for (int i = 1; i < path.size(); i++)
    {
        DrawLine(path[i]->pos.x, path[i]->pos.y, path[i-1]->pos.x, path[i-1]->pos.y,pathColour);
    }
}





