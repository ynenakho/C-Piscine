
#include "Enemy.hpp"

void Enemy::takeDamage(int i) {
  if (i < 0)
    return;
  if (this->hitPoints <= i)
  {
    this->hitPoints = 0;
    delete this;
  }
  this->hitPoints -= i;

}

std::string const Enemy::getType() const {
  return this->type;
}

Enemy::Enemy(int hp, std::string const & type) {
  this->type = type;
  this->hitPoints = hp;
  return;
}

Enemy::~Enemy() {
  return;
}

int Enemy::getHP() const {
  return this->hitPoints;
}

Enemy::Enemy() {
  return;
}

Enemy &Enemy::operator= (const Enemy &obj) {
  this->type = obj.type;
  this->hitPoints = obj.hitPoints;
  return (*this);
}
