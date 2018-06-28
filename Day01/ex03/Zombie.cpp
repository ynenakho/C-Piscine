#include "Zombie.hpp"

Zombie::Zombie() {
  std::string NameArray[10] = {"budz" , "pain" , "konan","nagato", "itachi", "tobi", "madara", "naruto", "danzou", "kakashi"};
  this->zName = NameArray[rand() % 10];
  this->zType = "braineater";
  std::cout << "Zombie named as "<< this->zName <<" was born..." << std::endl;
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
