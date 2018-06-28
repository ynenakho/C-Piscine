#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) {
  this->name = name;
  this->weapon = &weapon;
  return;
}

HumanA::HumanA(std::string name) {
  this->name = name;
  return;
}

HumanA::~HumanA() {
  return;
}

void HumanA::attack() {
  std::cout << this->name << " attacks with his " << this->weapon->getType() << std::endl;
}
