#include <iostream>
#include <memory>
#include <vector>

class Cint
{
public:

  int x ,y = 0 ;
  Cint() {};
  Cint(int cx, int cy) :x(cx), y(cy){};
};

class Location
{
public:
	int x = 0;
	int y = 0;
	std::shared_ptr<Cint> spCint;
	Location() {};
	Location(int cx, int cy) :x(cx), y(cy) 
	{
		spCint = std::make_shared<Cint>(x-1,y-1);
	};
};	

int main()
{
	//Simple class with int x and int y
	Cint cinta(2,3);
	Cint cintb;
	cintb.x=4;
	cintb.y=5;
	
  // Create Class Location
	Location location;
	std::vector<std::shared_ptr<Location>> locationVec;  						//Create Location shared pointer Vector
	locationVec.push_back(std::shared_ptr<Location>(new Location(33,44)));		//Try to add new pointer object to Vector

	// locationVec[0]->spCint = std::make_shared<Cint>(11,22);
	// auto h = locationVec[0]->spCint ;
	// locationVec[0]->spCint = std::make_shared<Cint>(55,66);	
	
	std::cout << "Vector Shared Pointer of Location Value : "     << locationVec[0]->x <<"\n";
	std::cout << "Vector Shared Pointer of Location Cint Value : "<< locationVec[0]->spCint->x <<"\n";
	// std::cout << "Vector Shared Pointer of Location H Cint Value : "<< h->x <<"\n";
  
  
	location.spCint = std::make_shared<Cint>(90,100);
	//  
    // 	auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++,tag));
	 std::cout << "location.spCint->x = " << location.spCint->x << "\n";
	// auto tempa = make_shared<Cint>(90,100);
	
  // Create Vector for Class Cint
  std::vector<Cint> cintVec;
  
  // Insert class to Vector
  cintVec.push_back(cinta);
  cintVec.push_back(Cint(110,120));

  // std::shared_ptr<Cint> cint;
  // std::shared_ptr<Cint> spCint(new Cint(8,9));

  // Create Shared Pointer for Class Cint
  
  std::shared_ptr<Cint> e = std::shared_ptr<Cint>(new Cint(8,9));
  auto f = std::shared_ptr<Cint>(new Cint(40,30));

  std::shared_ptr<Cint> spCinta;
  std::shared_ptr<Cint> spCint(new Cint);

  spCint->x = 10 ;
  spCinta = spCint;
  spCint->x = 20 ;

  // Create Vector for Shared Pointer
  std::vector<std::shared_ptr<Cint>> spVec;
  
  // Insert Shared Pointer to Vector
  spVec.push_back(spCint);
  spVec.push_back(spCinta);
  spVec.push_back(e);
  spVec.push_back(f);
  spVec.push_back(std::shared_ptr<Cint>(new Cint(60,70)));

  f->x=50;  

  std::cout << "Class Cint Vaule : " << cintb.x << " " << cintb.y << "\n";
  std::cout << "Vector Vaule : " << cintVec[0].x << " " << cintVec[0].y << "\n";
  std::cout << "Shared Pointer Vaule : " << spCinta->x << "\n";
  std::cout << "Vector Shared Pointer Value : " << spVec[3]->x << "\n";
  std::cout << "Vector Shared Pointer Value : " << spVec[4]->x << "\n";
  return 0;
}
