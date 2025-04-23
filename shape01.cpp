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


class Circle
{
	std::string m_name;
	float	m_x , m_y , m_sx , m_sy , m_CR;
	int		m_R,m_G,m_B;
	sf::CircleShape circle;
	
public:

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
		circle.setRadius(CR);
		circle.setFillColor(sf::Color(R,G,B));
		circle.setPosition(x, y);
	};
	
	void setPostion()
	{		
		circle.setPosition(circle.getPosition().x - m_sx, circle.getPosition().y - m_sy);
	}
	
	std::string getname()
	{
		return m_name;
	};
	
	float getx()
	{
		return circle.getPosition().x;
	};
	
	float gety()
	{
		return circle.getPosition().y;
	};
	
	float getsx()
	{
		return m_sx;
	};
	
	float getsy()
	{
		return m_sy;
	};
	
	int getR()
	{
		return m_R;
	};
		
	int getG()
	{
		return m_G;
	};
	
	int getB()
	{
		return m_B;
	};
	
	float getCR()
	{
		return m_CR;
	};

};

class Rectangle
{
	std::string m_name;
	float	m_x,m_y,m_sx,m_sy,m_w,m_h;
	int		m_R,m_G,m_B;
	sf::RectangleShape rectangle;
	
	
public:

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
		rectangle.setPosition(rectangle.getPosition().x - m_sx, rectangle.getPosition().y - m_sy);
	}


	std::string getname()
	{
		return m_name;
	};
	
	float getx()
	{
		return rectangle.getPosition().x;
	};
	
	float gety()
	{
		return rectangle.getPosition().y;
	};
	
	float getsx()
	{
		return m_sx;
	};
	
	float getsy()
	{
		return m_sy;
	};
	
	int getR()
	{
		return m_R;
	};
		
	int getG()
	{
		return m_G;
	};
	
	int getB()
	{
		return m_B;
	};
	
	float getw()
	{
		return m_w;
	};
	
	float geth()
	{
		return m_h;
	};
};

class ShapeList
{
	std::vector<sf::CircleShape> m_circles;
	std::vector<sf::RectangleShape> m_rectangles;
	
	int 					WindowX, WindowY;
	
	std::string				fontFile;
	int						fontSize;
	int						fontR,fontG,fontB;
	
public:

	ShapeList()
	{};
	
	int getWindowX()
	{
		return WindowX;
	};
	
	
	int getWindowY()
	{
		return WindowY;
	};
	
	size_t size()
	{
		return m_circles.size() ;
	};
	
	void addCircle(Circle circlec)
	{
		sf::CircleShape circle(circlec.getCR());
		circle.setFillColor(sf::Color(circlec.getR(),circlec.getG(),circlec.getB()));
		circle.setPosition(circlec.getx(), circlec.gety());
		m_circles.push_back(circle);
	};
	
	void addRectangle(Rectangle rectanglec)
	{
		sf::RectangleShape rectangle(sf::Vector2f(rectanglec.getx(),rectanglec.gety()));
		rectangle.setFillColor(sf::Color(rectanglec.getR(),rectanglec.getG(),rectanglec.getB()));
		m_rectangles.push_back(rectangle);
	};
	
	
	std::vector<sf::RectangleShape> getRectangle()
	{
	  return m_rectangles;	
	};

		
	const std::vector<sf::CircleShape> & getCircle()
	{
	  return m_circles ;	
	};

	
	void addFromFile(std::string & file)
	{
		std::string name, shape;
		float	x,y,sx,sy,w,h,cr;
		int		R,G,B;


		std::ifstream fin;
		fin.open(file);

		while(fin>>shape)
		{
			if (shape=="Window")
			{
				fin>>WindowX>>WindowY;
			};
			
			if (shape=="Font")
			{
				fin>> fontFile >> fontSize >> fontR >> fontG >> fontB;
			};
			
			if (shape=="Circle")
			{
				fin>>name>>x>>y>>sx>>sy>>R>>G>>B>>cr;
				addCircle(Circle(name,x,y,sx,sy,R,G,B,cr));
			};
			
			if (shape=="Rectangle")
			{
				fin>>name>>x>>y>>sx>>sy>>R>>G>>B>>w>>h;
				addRectangle(Rectangle(name,x,y,sx,sy,R,G,B,w,h));
			};
		};
		
		fin.close();
		
	};

};

	
void addFromFile(std::string & file , std::vector<Circle>& circleVec , std::vector<Rectangle>& rectangleVec)
{
	std::string name, shape;
	float	x,y,sx,sy,w,h,cr;
	int		R,G,B;
	
	int 					WindowX, WindowY;
	
	std::string				fontFile;
	int						fontSize;
	int						fontR,fontG,fontB;

	std::ifstream fin;
	fin.open(file);

	while(fin>>shape)
	{
		if (shape=="Window")
		{
			fin>>WindowX>>WindowY;
		};
		
		if (shape=="Font")
		{
			fin>> fontFile >> fontSize >> fontR >> fontG >> fontB;
		};
		
		if (shape=="Circle")
		{
			fin>>name>>x>>y>>sx>>sy>>R>>G>>B>>cr;
			// addCircle(Circle(name,x,y,sx,sy,R,G,B,cr));
			circleVec.push_back(Circle(name,x,y,sx,sy,R,G,B,cr));
		};
		
		if (shape=="Rectangle")
		{
			fin>>name>>x>>y>>sx>>sy>>R>>G>>B>>w>>h;
			rectangleVec.push_back(Rectangle(name,x,y,sx,sy,R,G,B,w,h));
			// addRectangle(Rectangle(name,x,y,sx,sy,R,G,B,w,h));
		};
	};
	
	fin.close();
	
};



int main()
{
	std::string filename="shape.txt";
	ShapeList shapeList;
	std::vector<Circle> circleVec;
	std::vector<Rectangle> rectangleVec;
	addFromFile(filename , circleVec , rectangleVec);
	// circleVec.push_back(Circle("CBlue",2,2,2,2,0,0,255,10));
	// Circle circle("CGreen",1,1,1,1,0,255,0,5);
	// shapeList.addCircle(circle);
	// shapeList.addCircle(Circle("CBlue",2,2,2,2,0,0,255,10));
	// shapeList.addCircle(Circle("CGreen",2,2,2,2,0,0,255,10));
	// shapeList.addFromFile("shape.txt");
	
	std::cout << "WindowX : " << shapeList.getWindowX() << "\n";


	for (Circle s : circleVec)
	{
		std::cout << "Name : " << s.getname() << ", X = " << s.getx() << "\n";
	};


	for (Rectangle r : rectangleVec)
	{
		std::cout << "Name : " << r.getname() << ", X = " << r.getx() << "\n";
	};

//	std::cout << shapeList.size();
	
//	for (int i=0;shapeList.size() > i ; i++)
	//for (Circle s : shapeList.getCircle())
//	{
//		std::cout << shapeList.getCircle[i].getname();
//	};
	return 0;

}




