#include "Player.h"
#include <SFML/Graphics.hpp>
#include<iostream>
using namespace sf;

void Player::update(int col, int row)
{
	playerSprite.setTextureRect(sf::IntRect(col * 96, row * 96, 96, 96));
	playerSprite.setPosition(position);
	this->col = col;
	this->row = row;
}

Player::Player()
{
	playerSprite.scale(0.5, 0.5);

	floor = (32 * 22 ) - 14 ; // -14 is by hit and try
	jumpSpeed = 300;
	speed = 100;
	jumpEnd = false;

	position = Vector2f(32, floor);

	if (playerTexture.loadFromFile("./Assets/Player/Textures/Mario-Set.png")) {
		playerSprite.setTexture(playerTexture);
		update(0, 0);
	}
	else {
		std::cout << "Error , can't load srpite";
	}
}

void Player::moveRight(float delta)
{
	position += sf::Vector2f(speed * delta, 0);
	if (clock.getElapsedTime().asMilliseconds() >= 100) {
		update((col + 1) % 2, 0);
		clock.restart();
	}
}

void Player::moveLeft(float delta)
{
	position += sf::Vector2f(-speed * delta, 0);
	if (clock.getElapsedTime().asMilliseconds() >= 100) {
		update((col + 1) % 2, 1);
		clock.restart();
	}
}

/*
void Player::moveDown(float delta)
{
	sf::Vector2f position = playerSprite.getPosition();
	if (clock.getElapsedTime().asMilliseconds() >= 100) {
		create((col % 8) + 1, 1);
		clock.restart();
	}
	playerSprite.setPosition(position + sf::Vector2f(0, speed * delta));
}


void Player::moveUp(float delta) {
	sf::Vector2f position = playerSprite.getPosition();
	if (clock.getElapsedTime().asMilliseconds() >= 100) {
		create((col % 8) + 1, 0);
		clock.restart();
	}
	playerSprite.setPosition(position + sf::Vector2f(0, -speed * delta));
}
*/

void Player::stop() {
	if((int)position.y == floor) update(0, row);
}
void Player::gravity(float delta)
{
	if (position.y < floor)
	{
		position += Vector2f(0, jumpSpeed * delta);
		update(2,row);
	}
	else jumpEnd = false;
}
void Player::jump(float delta)
{
	if (position.y >= 32 * 15) 
	{
		position -= Vector2f(0, jumpSpeed * delta);
		update(2, row);
	}
	else jumpEnd = true;

}

void Player::draw(RenderWindow& window) {
	window.draw(playerSprite);
}

Vector2f Player::getPosition() {
	return position;
}




