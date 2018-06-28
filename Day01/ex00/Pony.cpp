#include "Pony.hpp"

Pony::Pony(std::string name)
{
  this->ponyName = name;
  std::cout << "Pony named " << this->ponyName << " was born" << std::endl;
  return;
}

Pony::~Pony()
{
  std::cout << "Pony named " << this->ponyName << " has died" << std::endl;
  return;
}

void Pony::makeSound()
{
  std::cout << this->ponyName << " made a sound )))" << std::endl;
  return;
}
