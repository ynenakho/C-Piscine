#include "Weapon.hpp"

Weapon::Weapon(std::string wType) {
  this->type = wType;
  return;
}

Weapon::~Weapon() {
  return;
}

void Weapon::setType(std::string wType) {
  this->type = wType;
  return;
}

  const std::string &Weapon::getType() {
    return (this->type);
  }
