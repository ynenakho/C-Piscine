#include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon &weapon) {
  this->name = name;
  this->weapon = &weapon;
  return;
}

HumanB::HumanB(std::string name) {
  this->name = name;
  return;
}

HumanB::~HumanB() {
  return;
}

void HumanB::attack() {
  std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
  this->weapon = &weapon;
}
