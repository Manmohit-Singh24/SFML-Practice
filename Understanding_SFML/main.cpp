#include<iostream>
#include<SFML/Graphics.hpp>

using namespace std;

int mainf() {

	int col = 0; // start from 0 
	int row = 3; // start from 0

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	sf::Texture bulletTexture;
	sf::Sprite bulletSprite;

	if (playerTexture.loadFromFile("./Assets/Player/Textures/Skeleton-Sprite.png")) {
		playerSprite.setTexture(playerTexture);
		playerSprite.setTextureRect(sf::IntRect(col * 64, row * 64, 64, 64));
		playerSprite.setPosition(30, 500);
	}
	else {
		cout << "Error , can't load srpite";
	}

	if (bulletTexture.loadFromFile("./Assets/Bullet/bullet.png")) {
		bulletSprite.setTexture(bulletTexture);
		bulletSprite.setTextureRect(sf::IntRect(0,0, 400, 400));
		bulletSprite.scale(sf::Vector2f(0.1, 0.1));
		bulletSprite.rotate(180);
		bulletSprite.setPosition(playerSprite.getPosition() + sf::Vector2f(84 , 50));
	}
	else {
		cout << "Can't Load bullet";
	}

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Sprite Testing");


	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Vector2f position = playerSprite.getPosition();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { // Right
			playerSprite.setPosition(position + sf::Vector2f(1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { // Left
			playerSprite.setPosition(position + sf::Vector2f(-1, 0));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //Up
			playerSprite.setPosition(position + sf::Vector2f(0, -1));
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { //Down
			playerSprite.setPosition(position + sf::Vector2f(0, 1));
		}

		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.draw(bulletSprite);
		window.display();

	}

	return 0;
}