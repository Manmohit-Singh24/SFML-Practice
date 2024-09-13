#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Enemy.h"

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
	Enemy enemy;

	RenderWindow window(VideoMode(1216, 800), "Sprite Testing");

	Clock clock;

	// ============= Event Loop : =================================

	while (window.isOpen()) {

		float delta = clock.restart().asSeconds();
		Event event;
		enemy.create();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)) 
			player.moveRight(delta); // Right

		if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
			player.moveLeft(delta); // Left
		
		if ((Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Space)) && !player.jumpEnd) 
			player.jump(delta); // Jump 
		else 
			player.gravity(delta);
		
		if (noKeyPressed()) {
			player.stop();
			player.gravity(delta);
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			player.fire(mousePos);
		}

		for (int i = 0; i<enemy.enemies.size() ; i++ ){
			Sprite& enm = enemy.enemies.at(i);
			if (player.checkCollide(enm)) {
				enemy.enemies.erase(enemy.enemies.begin()+i);
			}
		}

		window.clear(sf::Color(213, 255, 255));
		map.renderMap(window);
		enemy.draw(window);
		player.draw(window , delta);
		window.display();
	}

	return 0;
}