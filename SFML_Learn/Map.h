#pragma once
#include<SFML/Graphics.hpp>
#include "GameTile.h" 
#include<vector>

using namespace sf;
class Map
{
	Texture texture;

	int cellHeight;
	int cellWidth;
	int gridCols;
	int gridRows;

	std::vector< std::vector < GameTile >> map;

public:
	Map(std::string);
	
	void loadFloor();
	void renderMap(sf::RenderWindow&);
};

