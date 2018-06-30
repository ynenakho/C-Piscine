#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(150, "Super Mutant"){
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
  return;
}

SuperMutant::SuperMutant(SuperMutant const &obj) {
    *this = obj;
    return ;
}
SuperMutant::~SuperMutant() {
  std::cout << "Aaargh ..." << std::endl;
  return;
}

SuperMutant &SuperMutant::operator= (const SuperMutant &obj) {
  this->type = obj.type;
  this->hitPoints = obj.hitPoints;
  return (*this);
}



void SuperMutant::takeDamage(int i) {
  i -= 3;
  if (i < 0)
    return;
  if (this->hitPoints <= i)
    this->hitPoints = 0;
  this->hitPoints -= i;
}
