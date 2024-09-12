#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

Bullet::Bullet(Texture& texture, Vector2f position) {
	bulletSprite.setTexture(texture);
	bulletSprite.setTextureRect(sf::IntRect(0, 0, 400, 400));
	bulletSprite.scale(sf::Vector2f(0.1, 0.1));
	bulletSprite.rotate(180);
	bulletSprite.setPosition(position + sf::Vector2f(84, 50));
}

void Bullet::draw(RenderWindow& window) {
	window.draw(bulletSprite);
}
void Bullet::setPosition(Vector2f position) {
	bulletSprite.setPosition(position);
}

Vector2f Bullet::getPosition() {
	return bulletSprite.getPosition();
}

void Bullet::animate(float delta) {
	bulletSprite.setPosition( bulletSprite.getPosition() + Vector2f(speed * delta, 0));
}
