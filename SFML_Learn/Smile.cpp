#include <SFML/Graphics.hpp>
#include <iostream> 
using namespace sf;
using namespace std;

class shape {

	CircleShape face;
	CircleShape eye1;
	CircleShape eye2;
	CircleShape ball1;
	CircleShape ball2;
	RectangleShape mouth;
	float i = 0;
	bool good = true;

public :
	void createShape() {
		face = CircleShape(400, 400);
		face.setFillColor(Color::Yellow);

		eye1 = CircleShape(100, 100);
		eye1.setPosition(150, 200);

		eye2 = CircleShape(100, 100);
		eye2.setPosition(450, 200);

		ball1 = CircleShape(50, 50);
		ball1.setFillColor(Color::Black);

		ball2 =  CircleShape(50, 50);
		ball2.setFillColor(Color::Black);

		mouth = RectangleShape(Vector2f(200, 50));
		mouth.setFillColor(Color::Red);
		mouth.setPosition(300 , 500 );
	}

	void drawShape(RenderWindow &window) {
		window.draw(face);
		window.draw(eye1);
		window.draw(eye2);
		window.draw(ball1);
		window.draw(ball2);
		window.draw(mouth);

		animation();
	}

	void animation(){
		if (good) {
			i+=0.05;
			if (i >= 50) {
				good = false;
			}
		}
		else {
			i-=0.05;
			if (i <= 0) {
				good = true;
			}
		}
		ball1.setPosition(175+i, 250);
		ball2.setPosition(475+i, 250);
	}
};


int mainRun()
{
	sf::RenderWindow window(sf::VideoMode(810, 810), "SFML Practice : Smile");
	shape sh;
	sh.createShape();

	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::Black);
		sh.drawShape(window);
		window.display();
	}

	return 0;
}



//// Shape
//sf::CircleShape circle(50);
//circle.setFillColor(sf::Color::Green);
//circle.setPosition(50, 100);

//sf::RectangleShape rect(sf::Vector2f(150.f, 150.f));
//rect.setFillColor(sf::Color::Red);
//rect.setPosition(25, 75);
//rect.setOrigin(25, 25);
//rect.rotate(45);

//sf::CircleShape triangle(50, 3);
//triangle.setFillColor(sf::Color::Magenta);
//triangle.setPosition(350, 100);

/*   shape.setOutlineThickness(10.f);
   shape.setOutlineColor(sf::Color(250, 150, 100));*/