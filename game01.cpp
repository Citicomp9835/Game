#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <fstream>
#include "Vec2.h"

class CTransform
{
	
public:

CTransform() {};

};




int main()
{

Vec2 p1(10,10);
Vec2 p2(20,20);
Vec2 p3 = p1 + p2;



std::cout << "Distance = " << p1.dist(p3) ;

return 0;

}
