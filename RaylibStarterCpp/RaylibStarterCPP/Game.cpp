

#include "Game.h"

Game::Game()
{
    std::vector<std::string> map;
    int cellSize = 32;
    //ASCII art map
    //--------------------------------------------------------------------------------------
    map.push_back("0000000000000000");
    map.push_back("0111111111011110");
    map.push_back("0111011111011110");
    map.push_back("0111011111111110");
    map.push_back("0111010000001110");
    map.push_back("0111011111111110");
    map.push_back("0111011111011110");
    map.push_back("0111111111011110");
    map.push_back("0111111111011110");
    map.push_back("0000000000000000");

    maze.Initialise(map, cellSize);
    //--------------------------------------------------------------------------------------

    start = nullptr;
    end = nullptr;
        
    playerAgent.SetSpeed(300);
    playerAgent.SetNode(maze.GetNode(1, 1));
    playerAgent.SetPos(playerAgent.GetNode()->pos);
    playerAgent.SetColour(Color{ 255,0,255,255 });

    PathAgent* AIpathAgent01 = new PathAgent;
    AIpathAgent01->SetSpeed(100);
    AIpathAgent01->SetNode(maze.GetNode(14, 8));
    AIpathAgent01->SetPos(AIpathAgent01->GetNode()->pos);
    AIpathAgent01->SetColour(Color{ 255,255,0,255 });

    PathAgent* AIpathAgent02 = new PathAgent;
    AIpathAgent02->SetSpeed(100);
    AIpathAgent02->SetNode(maze.GetNode(5, 5));
    AIpathAgent02->SetPos(AIpathAgent02->GetNode()->pos);
    AIpathAgent02->SetColour(Color{ 0,255,255,255 });

    wander01 = new WanderBehaviour;
    wander02 = new WanderBehaviour;

    aiAgent01 = new Agent{ &maze,wander01,AIpathAgent01};
    aiAgent02 = new Agent{ &maze,wander02,AIpathAgent02};
    
}

Game::~Game()
{
	
}

void Game::Update(float delta)
{
    
    //set the end pos
    if (IsMouseButtonPressed(0))
    {
        //std::cout << "right mouse button pressed" << std::endl;

        Vector2 mousePos = GetMousePosition();
        end = maze.GetClosestNode(Vector2{ mousePos.x, mousePos.y });
        if (end != nullptr)
        {
            std::cout << "Set end pos" << ": ";
            std::cout << end->pos.x << ":" << end->pos.y << std::endl;
            playerAgent.GoToNode(end);
            std::cout << "Start" << std::endl;
        }
    }

    playerAgent.Update(delta);  
    aiAgent01->Update(delta);
    aiAgent02->Update(delta);

}

void Game::Draw()
{
    maze.DrawMap();
    DrawPath(playerAgent.GetPath(), pathColour);
    playerAgent.Draw();
    aiAgent01->Draw();
    aiAgent02->Draw();
}

void Game::DrawPath(std::vector<Node*> path, Color pathColour)
{
    for (int i = 1; i < path.size(); i++)
    {
        DrawLine(path[i]->pos.x, path[i]->pos.y, path[i-1]->pos.x, path[i-1]->pos.y,pathColour);
    }
}





