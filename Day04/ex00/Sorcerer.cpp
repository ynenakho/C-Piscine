#include "Sorcerer.hpp"


Sorcerer::Sorcerer(std::string name, std::string title) {
  this->name = name;
  this->title = title;
  std::cout << this->name << ", " << this->title << ", is born !" << std::endl;
  return;
}

Sorcerer::~Sorcerer() {
  std::cout << this->name << ", " << this->title
            << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

Sorcerer &Sorcerer::operator= (const Sorcerer &obj) {
  this->name = obj.name;
  this->title = obj.title;
  return (*this);
}

void Sorcerer::introduce() {
  std::cout << "I am " << this->name << ", " << this->title
                       << ", and I like ponies !" << std::endl;
}

std::string Sorcerer::getName() const {
  return this->name;
}
std::string Sorcerer::getTitle() const {
  return this->title;
}

std::ostream &operator<<(std::ostream &res, Sorcerer const &obj) {
  res << "I am " << obj.getName() << ", " << obj.getTitle()
                       << ", and I like ponies !" << std::endl;
  return res;
}

void Sorcerer::polymorph(const Victim &obj) const {
  obj.getPolymorphed();
  return;
}
