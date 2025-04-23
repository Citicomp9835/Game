#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>

/*

Window 800 600   / W H
Font fonts/arial.ttf 18 255 255 255

Circle CGreen 100 100 -0.03 0.02 0 255 0 50  			/ Name , (X,Y) Speed(X,Y) Color(R,G,B) Radius
Circle CBlue 200 200 0.02 0.04 0 0 255 100
Circle CPurple 300 300 -0.02 -0.01 255 0 255 75

Rectangle RRed 200 200 0.1 0.15 255 0 0 50 25			/ Name , (X,Y) Speed(X,Y) Color(R,G,B) (W,H)
Rectangle RGrey 200 250 -0.02 0.02 100 100 100 50 100
Rectangle RTeal 25 100 -0.02 -0.02 0 255 255 100 100

*/

int 	WindowW, WindowH;

class Font
{
public:	

	std::string	fontFile;
	int			fontSize;
	int			fontR,fontG,fontB;	
	sf::Font arial;
	
	Font() {};
};

class Circle
{

	
public:

	std::string m_name;
	float	m_x , m_y , m_sx , m_sy , m_CR;
	int		m_R,m_G,m_B;
	sf::CircleShape circle;

	Circle(const std::string & name, float x, float y, float sx, float sy, int R,int G,int B, float CR)
	:m_name(name),
	 m_x(x),
	 m_y(y),
	 m_sx(sx),
	 m_sy(sy),
	 m_R(R),
	 m_G(G),
	 m_B(B),
	 m_CR(CR)
	{
		circle.setRadius(m_CR);
		circle.setFillColor(sf::Color(R,G,B));
		circle.setPosition(m_x, m_y);
	};
	
	Circle() {};
	
	void setPostion()
	{		
		//circleMoveSpeed *= -1.0;
		if (m_x < 1 || m_x > WindowW - m_CR - m_CR) 
		{
			m_sx *= -1.0;
		};

		if (m_y < 1 || m_y > WindowH - m_CR - m_CR) 
		{
			m_sy *= -1.0;
		};


		m_x = m_x - m_sx;
		m_y = m_y - m_sy;
		circle.setPosition(m_x,m_y);
	}


};

class Rectangle
{
	
public:

	std::string m_name;
	float	m_x,m_y,m_sx,m_sy,m_w,m_h;
	int		m_R,m_G,m_B;
	sf::RectangleShape rectangle;
	


	Rectangle(std::string & name, float x, float y, float sx, float sy, int R,int G,int B, float w, float h)
	:m_name(name),
	 m_x(x),
	 m_y(y),
	 m_sx(sx),
	 m_sy(sy),
	 m_R(R),
	 m_G(G),
	 m_B(B),
	 m_w(w),
	 m_h(h)
	{
		rectangle.setSize(sf::Vector2f(w, h));
		rectangle.setFillColor(sf::Color(R,G,B));
		rectangle.setPosition(x, y);
	};

	
	void setPostion()
	{
		if (m_x < 1 || m_x > WindowW - m_w) 
		{
			m_sx *= -1.0;
		};

		if (m_y < 1 || m_y > WindowH - m_h) 
		{
			m_sy *= -1.0;
		};


		m_x = m_x - m_sx;
		m_y = m_y - m_sy;
		rectangle.setPosition(m_x,m_y);
		
		// rectangle.setPosition(rectangle.getPosition().x - m_sx, rectangle.getPosition().y - m_sy);
	}

};



	
void addFromFile(
				const 	std::string & file ,
						std::vector<Circle>& circleVec , 
						std::vector<Rectangle>& rectangleVec , 
						sf::RenderWindow& window ,
						Font& font
				)
{
	
	std::string name, shape;
	float	x,y,sx,sy,w,h,cr;
	int		R,G,B;
	int 	WindowX, WindowY;


	std::ifstream fin;
	fin.open(file);

	while(fin>>shape)
	{
		if (shape=="Window")
		{
			fin>>WindowX>>WindowY;
			window.create(sf::VideoMode(WindowX, WindowY), "My window");
			WindowW = WindowX;
			WindowH = WindowY;
		};
		
		if (shape=="Font")
		{
			fin>> font.fontFile >> font.fontSize >> font.fontR >> font.fontG >> font.fontB;
			font.arial.loadFromFile(font.fontFile);
		};
		
		if (shape=="Circle")
		{
			fin>>name>>x>>y>>sx>>sy>>R>>G>>B>>cr;
			circleVec.push_back(Circle(name,x,y,sx,sy,R,G,B,cr));
		};
		
		if (shape=="Rectangle")
		{
			fin>>name>>x>>y>>sx>>sy>>R>>G>>B>>w>>h;
			rectangleVec.push_back(Rectangle(name,x,y,sx,sy,R,G,B,w,h));
		};
	};
	
	fin.close();
	
};


int main()
{
	std::vector<Circle> circleVec;
	std::vector<Rectangle> rectangleVec;
	sf::RenderWindow window;
	Font font;

	addFromFile("shape.txt" , circleVec , rectangleVec , window , font);
	window.setFramerateLimit(2000);

	while (window.isOpen())
	{

		window.clear();		
		sf::Event event;

		while (window.pollEvent(event))
		{	
			if (event.type == sf::Event::Closed)
			{
				window.close();
			};
		};	

		for (Circle & c : circleVec)
		{
			//circleMoveSpeed *= -1.0;
			c.setPostion();
			window.draw(c.circle);
		};

		for (Rectangle & r : rectangleVec)
		{
			r.setPostion();
			window.draw(r.rectangle);
		};

		window.display();
	};

	return 0;

}
