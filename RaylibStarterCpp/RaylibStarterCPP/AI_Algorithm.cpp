#include "AI_Algorithm.h"

std::vector<Node*> AI_Algorithm::DijkstrasSearch(Node* startNode, Node* endNode)
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

std::vector<Node*> AI_Algorithm::AStarSearch(Node* startNode, Node* endNode)
{
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

    startNode->gScore = 0;
    startNode->hScore = AI_Algorithm::ManhattanDistance(startNode->pos, endNode->pos);
    startNode->fScore = 0;
    startNode->previous = nullptr;
    endNode->previous = nullptr;

    std::vector<Node*> openList;
    std::vector<Node*> closedList;

    openList.push_back(startNode);

    struct sortByfScore
    {
        bool operator()(Node* a, Node* b) const { return a->fScore > b->fScore; }
    };

    while (openList.size() > 0)
    {
        std::sort(openList.begin(), openList.end(), sortByfScore());

        Node* currentNode = openList.front();

        if (currentNode == endNode)
        {
            break;
        }

        openList.erase(openList.begin());
        closedList.push_back(currentNode);

        for (int i = 0; i < currentNode->connections.size(); i++)
        {
            if (std::find(closedList.begin(), closedList.end(), currentNode->connections[i].target) == closedList.end())
            {
                float gScore = currentNode->gScore + currentNode->connections[i].cost;
                float hScore = AI_Algorithm::ManhattanDistance(currentNode->connections[i].target->pos, endNode->pos);
                float fScore = gScore + hScore;

                if (std::find(openList.begin(), openList.end(), currentNode->connections[i].target) == openList.end())
                {
                    currentNode->connections[i].target->gScore = gScore;
                    currentNode->connections[i].target->fScore = fScore;
                    currentNode->connections[i].target->previous = currentNode;
                    openList.push_back(currentNode->connections[i].target);
                }
                else if (fScore < currentNode->connections[i].target->fScore)
                {
                    currentNode->connections[i].target->gScore = gScore;
                    currentNode->connections[i].target->fScore = fScore;
                    currentNode->connections[i].target->previous = currentNode;
                }
            }
        }
    }

    std::vector<Node*> path;

    Node* currentNode = endNode;

    while (currentNode != nullptr)
    {
        path.insert(path.begin(), currentNode);
        currentNode = currentNode->previous;
    }

    if (openList.empty())
    {
        std::cout << "Path NOT found" << std::endl;
        return std::vector<Node*>();
    }

    return path;
}

float AI_Algorithm::ManhattanDistance(Vector2 a, Vector2 b)
{
    float dx = std::abs(a.x - b.x);
    float dy = std::abs(a.y - b.y);

    return dx + dy;
}
