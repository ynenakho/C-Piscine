#include "Peon.hpp"
#include "Victim.hpp"

Peon::Peon(std::string name): Victim(name) {
  this->name = name;
  std::cout << "“Zog zog." << std::endl;
  return;
}

Peon::~Peon() {
  std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(Peon const &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

Peon &Peon::operator= (const Peon &obj) {
  this->name = obj.name;
  return (*this);
}

std::string Peon::getName() const {
  return this->name;
}

void Peon::getPolymorphed() const {
  std::cout << this->name << " has been turned into a pink pony !"
                            << std::endl;
}
