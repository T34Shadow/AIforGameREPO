#include "PathAgent.h"
#include "AI_Algorithm.h"

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
    path = AI_Algorithm::DijkstrasSearch(currentNode, node);
}

void PathAgent::Draw()
{
    DrawCircle(pos.x, pos.y, 10, colour);
}

PathAgent* PathAgent::GetTarget()
{
    return this;
}

void PathAgent::SetNode(Node* node)
{
    currentNode = node;
}

void PathAgent::SetSpeed(float _speed)
{
    speed = _speed;
}

void PathAgent::SetColour(Color _color)
{
    colour = _color;
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
