#include <iostream>
#include <memory>
#include <vector>

class Cint
{

public:

  int x,y;
  Cint() {};
  Cint(int cx, int cy) :x(cx), y(cy){};
};

int main()
{
  Cint cinta(2,3);
  Cint cintb;
  cintb.x=4;
  cintb.y=5;

  std::vector<Cint> cintVec;
  cintVec.push_back(cinta);

  // std::shared_ptr<Cint> cint;
  // std::shared_ptr<Cint> spCint(new Cint(8,9));
  std::shared_ptr<Cint> spCint(new Cint);
  std::shared_ptr<Cint> spCinta;
  spCint->x = 10 ;
  spCinta = spCint;
  spCint->x = 20 ;

  std::cout << "Cint Vaule : " << cintb.x << " " << cintb.y << "\n";
  std::cout << "Vector Vaule : " << cintVec[0].x << " " << cintVec[0].y << "\n";
  std::cout << "Shared Pointer Vaule : " << spCinta->x << "\n";
  return 0;
}