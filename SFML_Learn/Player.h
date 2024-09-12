#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
	int col;
	int row;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	sf::Vector2f position;
	int speed ;
	Clock clock;
	void update(int colf, int rowf);
	float jumpSpeed;
public:
	int floor;
	bool jumpEnd;
	Player();
	void moveRight(float);
	void moveLeft(float);
	//void moveDown(float);
	//void moveUp(float);
	void stop();
	void gravity(float);
	void jump( float);
	void draw(RenderWindow& window);
	Vector2f getPosition();
};
