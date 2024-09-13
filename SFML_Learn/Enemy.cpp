#include "Enemy.h"
#include <cstdlib>
#include<iostream>

Enemy::Enemy()
{
	if (enemyTexture.loadFromFile("Assets/Bullet/enemy.png")) {
		enemySprite.setTexture(enemyTexture);
		enemySprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
	}
	else {
		std::cout << "Can't load enemies";
	}
}

void Enemy::create()
{
	if (clock.getElapsedTime().asSeconds() >= 1) {
		float randomX = rand() % 1216;
		float randomY = 70 + rand() % 20;

		sf::Sprite& temp = enemySprite;
		temp.setPosition(sf::Vector2f(randomX, randomY));
		enemies.push_back(temp);
		clock.restart();
	}
}

void Enemy::draw(sf::RenderWindow& window)
{
	for (sf::Sprite enemy : enemies) {
		window.draw(enemy);
	}
}


