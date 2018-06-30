#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion"){
  std::cout << "* click click click *" << std::endl;
  return;
}

RadScorpion::RadScorpion(RadScorpion const &obj) {
  *this = obj;
  return ;
}

RadScorpion::~RadScorpion() {
  std::cout << "* SPROTCH *" << std::endl;
  return;
}

RadScorpion &RadScorpion::operator= (const RadScorpion &obj) {
  this->type = obj.type;
  this->hitPoints = obj.hitPoints;
  return (*this);
}
