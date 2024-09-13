#pragma once
#include<SFML/Graphics.hpp>
 
class Enemy
{
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	sf::Clock clock;

public : 
	std::vector<sf::Sprite> enemies;
	Enemy();
	sf::Sprite setSprite(sf::Vector2f);
	void create();
	void draw(sf::RenderWindow&);

};

