#pragma once
#include<SFML/Graphics.hpp>

class GameTile
{
	int spriteWidth;
	int spriteHeight;

public : 
	sf::Sprite sprite;
	GameTile(sf::Texture & , int , int , int , int);

	void draw(sf::RenderWindow&);
	
	sf::Sprite getSprite(); 

	void setPosition(float , float);
};

