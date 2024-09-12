#include "GameTile.h"
using namespace sf;
#include<iostream>

GameTile::GameTile(sf::Texture &texture, int x, int y, int width, int height)
{
	spriteWidth = width;
	spriteHeight = height;
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(x*spriteWidth, y*spriteHeight, width, height));
}

void GameTile::draw(sf::RenderWindow &window)
{
		window.draw(sprite);
}

sf::Sprite GameTile::getSprite()
{
	return sprite;
}
	

void GameTile::setPosition(float x, float y)
{
	sprite.setPosition(Vector2f(x*spriteWidth, y*spriteHeight));
}

