#include "AWeapon.hpp"

AWeapon::AWeapon() {
  return;
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) {
  this->name = name;
  this->apcost = apcost;
  this->damage = damage;
  return;
}

AWeapon::~AWeapon() {
  return;
}

std::string const AWeapon::getName() const {
  return this->name;
}

int AWeapon::getAPCost() const {
  return this->apcost;
}

int AWeapon::getDamage() const {
  return this->damage;
}

AWeapon &AWeapon::operator= (const AWeapon &obj) {
  this->name = obj.name;
  this->damage = obj.damage;
  this->apcost = obj.apcost;
  return (*this);
}
