#include "Character.hpp"

Character::Character() {
  return;
}

Character::~Character() {
  return;
}

Character &Character::operator= (const Character &obj) {
  this->actonPoints = obj.actonPoints;
  this->weapon = obj.weapon;
  this->name = obj.name;
  return (*this);
}

Character::Character(Character const &obj) {
    *this = obj;
    return ;
}

Character::Character(const std::string &name) {
  this->weapon = NULL;
  this->name = name;
  this->actonPoints = 40;
  return;
}

void Character::equip(AWeapon *weapon) {
  this->weapon = weapon;
  return;
}

void Character::recoverAP() {
  this->actonPoints = (this->actonPoints < 31) ? this->actonPoints + 10 : 40;
}

int Character::getAP() const {
  return this->actonPoints;
}

AWeapon *Character::getWeapon() const {
  return this->weapon;
}

const std::string Character::getName() const {
  return this->name;
}

void Character::attack(Enemy *enemy) {
  if (this->actonPoints < this->weapon->getAPCost())
  {
    std::cout << "Not enougth APs" << std::endl;
    return;
  }
  if (this->weapon != NULL)
  {
    this->actonPoints -= this->weapon->getAPCost();
    std::cout << this->name << " attacks " << enemy->getType() << " with a "
              << this->weapon->getName() << std::endl;
    this->weapon->attack();
    enemy->takeDamage(this->weapon->getDamage());
  }
}

std::ostream &operator<< (std::ostream &res, const Character &obj) {
  if (obj.getWeapon() != NULL) {
    res << obj.getName() << " has " << obj.getAP() << " AP and wields a "
        << obj.getWeapon()->getName() << std::endl;
    return res;
  }
  res << obj.getName() << " has " << obj.getAP() << " AP and is unarmed"
            << std::endl;
  return res;
}
