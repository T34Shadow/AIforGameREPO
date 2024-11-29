#include "PathAgent.h"

void PathAgent::Update(float delta)
{
    if (!path.empty())
    {
        SetNode(path[currentIndex]);
        //Calculate distance to next node. target - current pos;
        float distance = Vector2Distance({ path[currentIndex]->pos.x - pos.x }, { path[currentIndex]->pos.y - pos.y });
        direction = Vector2Normalize(Vector2{ path[currentIndex]->pos.x - pos.x , path[currentIndex]->pos.y - pos.y });

        if (distance > speed * delta)
        {
            pos = Vector2Add(pos, Vector2Scale(direction, speed * delta));
        }
        else
        {
            pos = path[currentIndex]->pos;
            currentIndex++;

            //at the end of the path;
            if (currentIndex >= path.size())
            {
                path.clear();
            }
        }
    }
}

void PathAgent::GoToNode(Node* node)
{
    currentIndex = 0;
    path = DijkstrasSearch(currentNode, node);
}

void PathAgent::Draw()
{
    DrawCircle(pos.x, pos.y, 10, Color{ 255,0,255,255 });
}

void PathAgent::SetNode(Node* node)
{
    currentNode = node;
}

void PathAgent::SetSpeed(float _speed)
{
    speed = _speed;
}

void PathAgent::SetPos(Vector2 _pos)
{
    pos = _pos;
}

std::vector<Node*> PathAgent::GetPath()
{
    return path;
}

Node* PathAgent::GetNode()
{
    return currentNode;
}

Vector2 PathAgent::GetPos()
{
    return pos;
}


std::vector<Node*> PathAgent::DijkstrasSearch(Node* startNode, Node* endNode)
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

    //sort openlsit by the gScore of each node;
    struct sortBygScore
    {
        bool operator()(Node* a, Node* b) const { return a->gScore < b->gScore; }
    };

    //while the open list is not empty
    while (!openList.empty())
    {
        std::sort(openList.begin(), openList.end(), sortBygScore());

        currentNode = openList[0];

        //exit the loop if the current and end node are the same.
        if (currentNode == endNode)
        {
            break;
        }

        openList.erase(openList.begin()); //remove current node from the open list
        closedList.push_back(currentNode); //add current node to the closed list

        for (int i = 0; i < currentNode->connections.size(); i++)
        {
            // is the node in the closed list
            if (std::find(closedList.begin(), closedList.end(), currentNode->connections[i].target) == closedList.end())
            {

                int gScore = currentNode->gScore + currentNode->connections[i].cost;
                //openList.push_back(currentNode->connections[i].target);

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
    if (!endNode)
    {
        currentNode = endNode;

    }
    if (openList.empty())
    {
        std::cout << "Path NOT found" << std::endl;
        return std::vector<Node*>();
    }
    while (currentNode != nullptr)
    {
        newPath.insert(newPath.begin(), currentNode);
        //newPath.push_back(currentNode);
        currentNode = currentNode->previous;
    }

    std::cout << "Path found" << std::endl;
    std::cout << newPath.size() << std::endl;
    return newPath;

}