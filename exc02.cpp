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

  std::shared_ptr<Cint> e = std::shared_ptr<Cint>(new Cint(8,9));
  std::shared_ptr<Cint> f = std::shared_ptr<Cint>(new Cint(40,30));

  std::shared_ptr<Cint> spCinta;
  std::shared_ptr<Cint> spCint(new Cint);

  spCint->x = 10 ;
  spCinta = spCint;
  spCint->x = 20 ;

  std::vector<std::shared_ptr<Cint>> spVec;
  spVec.push_back(spCint);
  spVec.push_back(spCinta);
  spVec.push_back(e);
  spVec.push_back(f);


  std::cout << "Cint Vaule : " << cintb.x << " " << cintb.y << "\n";
  std::cout << "Vector Vaule : " << cintVec[0].x << " " << cintVec[0].y << "\n";
  std::cout << "Shared Pointer Vaule : " << spCinta->x << "\n";
  std::cout << "Vector Shared Pointer Value : " << spVec[3]->x << "\n";
  return 0;
}