#include<iostream>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Player {
	int col;
	int row;
	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	int speed = 100;
	Clock clock ;
	void create(int colf, int rowf) {
		if (playerTexture.loadFromFile("./Assets/Player/Textures/Skeleton-Sprite.png")) {
			playerSprite.setTexture(playerTexture);
			playerSprite.setTextureRect(sf::IntRect(colf * 64, rowf * 64, 64, 64));
			playerSprite.setPosition(30, 500);
			col = colf;
			row = rowf;
		}
		else {
			std::cout << "Error , can't load srpite";
		}
	}

public:
	Player() {
		create(0, 3);
		playerSprite.scale(1.6, 1.6);
	}

	void moveRight(float delta) {
		sf::Vector2f position = playerSprite.getPosition();
		if (clock.getElapsedTime().asMilliseconds() >= 100) {
			create((col % 8) + 1, 3);
			clock.restart();
		}
		playerSprite.setPosition(position + sf::Vector2f(speed*delta, 0));
	}

	void moveLeft(float delta) {
		sf::Vector2f position = playerSprite.getPosition();
		if (clock.getElapsedTime().asMilliseconds() >= 100) {
			create((col % 8) + 1, 1);
			clock.restart();
		}
		playerSprite.setPosition(position + sf::Vector2f(-speed * delta, 0));
	}

	void moveDown(float delta) {
		sf::Vector2f position = playerSprite.getPosition();
		if (clock.getElapsedTime().asMilliseconds() >= 100) {
			create((col % 8) + 1, 2);
			clock.restart();
		}
		playerSprite.setPosition(position + sf::Vector2f(0, speed * delta));
	}

	void moveUp(float delta) {
		sf::Vector2f position = playerSprite.getPosition();
		if (clock.getElapsedTime().asMilliseconds() >= 100) {
			create((col % 8) + 1, 0);
			clock.restart();
		}
		playerSprite.setPosition(position + sf::Vector2f(0, -speed * delta));
	}

	void stop() {
		create(0, 3);
	}
	void draw(RenderWindow& window) {
		window.draw(playerSprite);
	}

	Vector2f getPosition() {
		return playerSprite.getPosition();
	}

	
};

class Bullet {
	sf::Sprite bulletSprite;
	float speed = 200;

public:
	Bullet(Texture &texture, Vector2f position) {
		bulletSprite.setTexture(texture);
		bulletSprite.setTextureRect(sf::IntRect(0, 0, 400, 400));
		bulletSprite.scale(sf::Vector2f(0.1, 0.1));
		bulletSprite.rotate(180);
		bulletSprite.setPosition(position + sf::Vector2f(84, 50));
	}

	void draw(RenderWindow& window) {
		window.draw(bulletSprite);
	}
	void setPosition(Vector2f position) {
		bulletSprite.setPosition(position);
	}

	Vector2f getPosition() {
		return bulletSprite.getPosition();
	}

	void animate(float delta) {
		bulletSprite.setPosition(bulletSprite.getPosition() + Vector2f(speed * delta , 0));
	}
};

int main() {




	//----------------------------
	sf::Texture bulletTexture;
	if (!bulletTexture.loadFromFile("./Assets/Bullet/bullet.png")) {
		std::cout << "Can't Load bullet";
	}

	Player player;
	std::vector<Bullet> bullets;
	Clock bulletT;

	RenderWindow window(VideoMode(1000, 800), "Sprite Testing");

	Clock clock;
	while (window.isOpen()) {
		float delta = clock.restart().asSeconds();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::D)) { // Right
			//cout << "D pressed" << endl;
			player.moveRight(delta);
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) { // Left
			//cout << "A pressed" << endl;
			player.moveLeft(delta);
		}
		if (Keyboard::isKeyPressed(Keyboard::W)) { //Up
			//cout << "W pressed" << endl;
			player.moveUp(delta);
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) { //Down
			//cout << "S pressed" << endl;
			player.moveDown(delta);
		}
		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			if(bulletT.getElapsedTime().asMilliseconds() >= 100 )
			{
				bullets.push_back(Bullet(bulletTexture, player.getPosition()));
				bulletT.restart();
			}
		}

		window.clear(sf::Color::Black);
		player.draw(window);

		for (Bullet &bullet : bullets) {
			bullet.animate(delta);
			bullet.draw(window);
		}
		window.display();
	}

	return 0;
}