#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21){
  return;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &obj) {
    *this = obj;
    return ;
}
PlasmaRifle::~PlasmaRifle() {
//  std::cout << "PlasmaRifle destructed" << std::endl;
  return;
}

PlasmaRifle &PlasmaRifle::operator= (const PlasmaRifle &obj) {
  this->name = obj.name;
  this->damage = obj.damage;
  this->apcost = obj.apcost;
  return (*this);
}

void PlasmaRifle::attack() const {
  std::cout << "* piouuu piouuu piouuu *" << std::endl;
  return;
}
