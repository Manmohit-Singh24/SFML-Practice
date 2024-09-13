#include "Player.h"
#include <SFML/Graphics.hpp>
#include<iostream>
#include<cmath>

using namespace sf;

void Player::update(int col, int row)
{
	playerSprite.setTextureRect(sf::IntRect(col * 96, row * 96, 96, 96));
	playerSprite.setPosition(position);
	this->col = col;
	this->row = row;
}

Player::Player() :
	floor((32 * 22) - 14), // -14 is by hit and try
	jumpSpeed(300),
	speed(100),
	jumpEnd(false),
	col(0),
	row(0),
	canFire(true)
{
	playerSprite.scale(0.5, 0.5);
	position = Vector2f(600, floor);


	if (playerTexture.loadFromFile("./Assets/Player/Textures/Mario-Set.png")) {

		if (!bulletTexture.loadFromFile("./Assets/Bullet/bullet.png")) {
			std::cout << "Failed to load Bullet's texture";
		}

		playerSprite.setTexture(playerTexture);
		update(col, row);
	}
	else {
		std::cout << "Filed to load Player's texture";
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

void Player::draw(RenderWindow &window ,  float &delta) {

	for (Bullet& bullet : bullets) {
		window.draw(bullet.bltSprite);

		Vector2f position = bullet.bltSprite.getPosition() + 
							Vector2f(
								bullet.direction.x * bullet.bltSpeed *delta , 
								bullet.direction.y * bullet.bltSpeed * delta
							);

		bullet.bltSprite.setPosition(position);
	}

	window.draw(playerSprite);
}

Vector2f Player::getPosition() {
	return position;
}

// ========================== Bullet =======================

Player::Bullet::Bullet(sf::Vector2i &posiiton , sf::Texture &bulletTexture , sf::Vector2f &playerPos):
	bltSpeed(500)
{
	bltSprite.setTexture(bulletTexture);
	bltSprite.setTextureRect(sf::IntRect(3*32, 0, 32, 32));
	bltSprite.setPosition(playerPos + Vector2f(16,16));
	target = posiiton;

}
void Player::fire(sf::Vector2i &targetPos)
{
	if(bulletTimer.getElapsedTime().asMilliseconds() >= 100)
	{
		Bullet bullet(targetPos , bulletTexture , position);
		float x = targetPos.x - position.x;
		float y = targetPos.y - position.y;
		float magnitude = std::powf( powf(x,2) + powf(y,2) , 0.5) ; // underroot( x^2 + y^2) ;
		bullet.direction = Vector2f(x / magnitude, y / magnitude);

		bullet.bltSprite.setOrigin(16, 16);

		float angle = (std::atan(y / x) * 180 / 3.14); // atan give intput in radian , convert it to degree

		angle = x > 0 ? angle : 180 + angle ;
		bullet.bltSprite.rotate(angle); // rotation take input in degrees 

		bullets.push_back(bullet);
		bulletTimer.restart();
	}
}

bool Player::checkCollide(sf::Sprite &enemy)
{
	for (Bullet &bullet : bullets) {
		
		if (bullet.bltSprite.getGlobalBounds().intersects(enemy.getGlobalBounds()))
		{
			return true ;
		}
	}
	return false;
}

