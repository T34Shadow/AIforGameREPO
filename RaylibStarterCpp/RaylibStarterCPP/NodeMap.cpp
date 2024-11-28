#include "NodeMap.h"

NodeMap::NodeMap()
{
}

NodeMap::~NodeMap()
{
}

void NodeMap::Initialise(std::vector<std::string> _map, int _cellSize)
{
	cellSize = _cellSize;
	const char wall = '0';

	height = _map.size();
	width = _map[0].size();

	nodes = new Node * [width * height];

	//Place out the nodes of the map

	for (int y = 0; y < height; y++)
	{
		std::string& line = _map[y];
		if (line.size() != width)
		{
			std::cout << "mismatched line#" << y << "in map (" << line.size() << "instead of " << width << ")" << std::endl;
		}

		for (int x = 0; x < width; x++)
		{
			char tile = x < line.size() ? line[x] : wall;

			nodes[x + width * y] = tile == wall ? nullptr : new Node(((float)x + 0.5f) * cellSize, ((float)y + 0.5f) * cellSize);

		}
	}

	//Add Edge connections to each of nodes

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			Node* node = GetNode(x, y);
			if (node)
			{
				Node* nodeWest = x == 0 ? nullptr : GetNode(x - 1, y);
				if (nodeWest)
				{
					node->ConnectTo(nodeWest, 1);
					nodeWest->ConnectTo(node, 1);
				}
				
				Node* nodeSouth = y == 0 ? nullptr : GetNode(x, y - 1);
				if (nodeSouth)
				{
					node->ConnectTo(nodeSouth, 1);
					nodeSouth->ConnectTo(node, 1);
				}
			}
		}
	}

}

Node* NodeMap::GetNode(int x, int y)
{

	return nodes[x + width * y];

}

Node* NodeMap::GetClosestNode(Vector2 worldPos)
{
	int i = (int)(worldPos.x / cellSize);
	if (i < 0 || i >= width)
	{
		std::cout << "Invalid pos" << std::endl;
		return nullptr;
	}

	int j = (int)(worldPos.y / cellSize);
	if (j < 0 || j >= height)
	{
		std::cout << "Invalid pos" << std::endl;
		return nullptr;
	}

	return GetNode(i, j);
}

void NodeMap::DrawMap()
{
	Color cellColor;
	cellColor.a = 255;
	cellColor.r = 255;
	cellColor.g = 0;
	cellColor.b = 0;
	Color lineColor;
	lineColor.a = 100;
	lineColor.r = 0;
	lineColor.g = 0;
	lineColor.b = 0;

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			Node* node = GetNode(x, y);
			if (node == nullptr)
			{
				DrawRectangle((int)(x * cellSize), (int)(y * cellSize), (int)cellSize - 1, (int)cellSize - 1, cellColor);
			}
			else
			{
				for (int i = 0; i < node->connections.size(); i++)
				{
					Node* other = node->connections[i].target;
					DrawLine((x + 0.5f) * cellSize, (y + 0.5) * cellSize, (int)other->pos.x, (int)other->pos.y, lineColor);
				}
			}
		}
	}
}

