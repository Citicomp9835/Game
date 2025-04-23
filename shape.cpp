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

	};
	
	std::string getname()
	{
		return m_name;
	};
	
	float getx()
	{
		return m_x;
	};
	
	float gety()
	{
		return m_y;
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
	};

	
	std::string getname()
	{
		return m_name;
	};
	
	float getx()
	{
		return m_x;
	};
	
	float gety()
	{
		return m_y;
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
	std::vector<Circle>    	m_circle;
	std::vector<Rectangle> 	m_rectangle;
	int 					WindowX, WindowY;
	
	std::string				fontFile;
	int						fontSize;
	int						fontR,fontG,fontB;
	
public:

	ShapeList()
	{};
	
	void addCircle(const Circle &circle)
	{
		m_circle.push_back(circle);
	};
	
	void addRectangle(const Rectangle &rectangle)
	{
		m_rectangle.push_back(rectangle);
	};
	
	std::vector<Rectangle> getRectangle()
	{
	  return m_rectangle;	
	};

		
	std::vector<Circle> getCircle()
	{
	  return m_circle ;	
	};

	
	void addFromFile(const std::string & file)
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
				// addCircle(Circle(name,2,2,2 ,2 ,0,0,255,10));
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

	

int main()
{

	ShapeList shapeList;
	// Circle circle("CGreen",1,1,1,1,0,255,0,5);
	// shapeList.addCircle(circle);
	// shapeList.addCircle(Circle("CBlue",2,2,2,2,0,0,255,10));
	shapeList.addFromFile("shape.txt");
	for (auto & s : shapeList.getCircle())
	{
		std::cout << s.getname() << "\n";
	};
return 0;

}