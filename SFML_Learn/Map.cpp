#include "Map.h"
#include<iostream>
using namespace sf;
Map::Map(std::string path)
{
	cellWidth = 32;
	cellHeight = 32;
	gridCols = 38;
	gridRows = 25;
	if (texture.loadFromFile(path)) {
		loadFloor();
	}
}

void Map::loadFloor()
{
	std::vector<GameTile> floor1;
	GameTile floor1t(texture, 0, 0, cellWidth, cellHeight);

	for (int i = 0; i < gridCols; i++)
	{
		floor1.push_back(floor1t);
		floor1.at(i).setPosition(i, 23);
	}
	map.push_back(floor1);


	std::vector<GameTile> floor2;
	GameTile floor2t(texture, 2, 6, cellWidth, cellHeight);

	for (int i = 0; i < gridCols; i++)
	{
		floor2.push_back(floor2t);
		floor2.at(i).setPosition(i, 24);
	}
	map.push_back(floor2);

}

void Map::renderMap(sf::RenderWindow& window)
{
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map.at(i).size(); j++)
		{
			window.draw(map.at(i).at(j).getSprite());
		}
	}
}
