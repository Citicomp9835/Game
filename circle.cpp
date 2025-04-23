#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char * argv[])
{
	const int wWidth = 640;
	const int wHeight = 480;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML Works!");
	window.setFramerateLimit(60);

	sf::CircleShape circle(100);
	circle.setFillColor(sf::Color(0,255,0));
	//circle.setFillColor(sf::Color::Green);
	circle.setPosition(300.0f, 300.0f);
	float circleMoveSpeed = 1.0f;

	sf::Font arial;

	if (!arial.loadFromFile("fonts/arial.ttf"))
	{
		std::cerr << "Could not load font!\n";
		exit(-1);
	};

	sf::Text text("Sample Text", arial, 24);

	text.setPosition(0, wHeight - (float)text.getCharacterSize());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{	
			if (event.type == sf::Event::Closed)
			{
				window.close();
			};
			
			if (event.type == sf::Event::KeyPressed)
			{
				std::cout << "Key pressed with code = " << event.key.code << "\n";
				
				if (event.key.code == sf::Keyboard::X)
				{
					circleMoveSpeed *= -1.0;
				};
			};
		};	
		circle.setPosition(circle.getPosition().x - circleMoveSpeed, circle.getPosition().y - circleMoveSpeed);
		
		window.clear();
		window.draw(circle);
		window.draw(text);
		window.display();
	};
	
return 0;
	
}