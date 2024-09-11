#include "Node.h"

Node::Node()
{

}

Node::Node(float x, float y)
{
	pos.x = x;
	pos.y = y;
}

Node::~Node()
{
}

void Node::ConnectTo(Node* other, float cost)
{
	connections.push_back(Edge(other, cost)); 
}
