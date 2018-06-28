#include "Zombie.hpp"

Zombie::Zombie(std::string name, std::string type): zName(name), zType(type) {
  std::cout << "Zombie named: " << this->zName <<" was born..." << std::endl;
  return;
}

Zombie::~Zombie() {
  std::cout << this->zName << " has died." << std::endl;
  return;
}

void Zombie::announce() {
  std::cout << "<" + this->zName + "(" + this->zType + ")> Brainsss..." << std::endl;
  return;
}
