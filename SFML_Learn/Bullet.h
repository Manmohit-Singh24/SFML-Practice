#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet
{
	sf::Sprite bulletSprite;
	float speed = 500;

public:
	Bullet(Texture& texture, Vector2f position);
	void draw(RenderWindow& window);
	void setPosition(Vector2f position);
	Vector2f getPosition();
	void animate(float delta);
};

