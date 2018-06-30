
#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50){
  return;
}

PowerFist::PowerFist(PowerFist const &obj) {
    *this = obj;
    return ;
}
PowerFist::~PowerFist() {
//  std::cout << "PowerFist destructed" << std::endl;
  return;
}

PowerFist &PowerFist::operator= (const PowerFist &obj) {
  this->name = obj.name;
  this->damage = obj.damage;
  this->apcost = obj.apcost;
  return (*this);
}

void PowerFist::attack() const {
  std::cout << "* pschhh... SBAM! *" << std::endl;
  return;
}
