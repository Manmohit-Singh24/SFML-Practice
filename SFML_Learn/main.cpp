#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Bullet.h"
#include "Map.h"

using namespace sf;
using namespace std;

bool noKeyPressed() {
	for (int key = sf::Keyboard::Key::A; key < sf::Keyboard::Key::KeyCount; ++key) {
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(key))) {
			return false; // A key is pressed
		}
	}
	return true; // No keys are pressed
}

int main() {
	Map map("Assets/Map/Tilessheet-mario.png");

	Player player;

	// Bullets are just for learnig , not very well created here 
	Texture bulletTexture;
	if (!bulletTexture.loadFromFile("./Assets/Bullet/bullet.png")) {
		cout << "Can't Load bullet";
	}
	vector<Bullet> bullets;
	Clock bulletT;

	RenderWindow window(VideoMode(1216, 800), "Sprite Testing");

	Clock clock;

	// ============= Event Loop : =================================

	while (window.isOpen()) {
		float delta = clock.restart().asSeconds();
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::D)) player.moveRight(delta); // Right


		if (Keyboard::isKeyPressed(Keyboard::A)) player.moveLeft(delta); // Left
		

		if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Space)) && !player.jumpEnd) player.jump(delta); // Jump 
		else player.gravity(delta);
		
		if (noKeyPressed()) {
			player.stop();
			player.gravity(delta);
		}

		if (Keyboard::isKeyPressed(Keyboard::LShift) || Keyboard::isKeyPressed(Keyboard::RShift)) {
			if (bulletT.getElapsedTime().asMilliseconds() >= 100)
			{
				bullets.push_back(Bullet(bulletTexture, player.getPosition()));
				bulletT.restart();
			}
		}

		window.clear(sf::Color(213, 255, 255));
		map.renderMap(window);

		player.draw(window);

		for (Bullet& bullet : bullets) {
			bullet.animate(delta);
			bullet.draw(window);
		}

		window.display();
	}

	return 0;
}