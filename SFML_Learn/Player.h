#pragma once
#include <SFML/Graphics.hpp>

class Player
{
	// ===================== Bullets ========================
	sf::Texture bulletTexture; 
	sf::Clock bulletTimer;

	class Bullet {

	public :
		Bullet(sf::Vector2i& , sf::Texture& , sf::Vector2f&);
		sf::Sprite bltSprite;
		sf::Vector2f direction; // direction vector to target 

		float bltSpeed;
		float displaceX;
		float displaceY;
		sf::Vector2i target;
	};

	bool canFire;
	std::vector<Bullet> bullets;

	// ====================== Player ===========================

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	sf::Vector2f position;
	sf::Clock clock;

	int col;
	int row;

	const int floor;
	const int speed ;
	const float jumpSpeed;

	void update(int colf, int rowf);

public:
	bool jumpEnd;
	bool stoped;

	Player();

	void moveRight(float);
	void moveLeft(float);

	void stop();

	void gravity(float);
	void jump(float);

	void draw(sf::RenderWindow& , float&);
	sf::Vector2f getPosition();

	// ============= Bullets ==================== 

	void fire(sf::Vector2i&);

	bool checkCollide(sf::Sprite&);

};
