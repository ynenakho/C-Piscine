#include "Victim.hpp"

Victim::Victim(std::string name) {
  this->name = name;
  std::cout << "Some random victim called " << this->name << " just popped !"
                                                          << std::endl;
  return;
}

Victim::~Victim() {
  std::cout << "Victim " << this->name << " just died for no apparent reason !"
                                       << std::endl;
}

Victim::Victim(Victim const &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

Victim &Victim::operator= (const Victim &obj) {
  this->name = obj.name;
  return (*this);
}

void Victim::introduce() {
  std::cout << "I am " << this->name << ", and I like otters !" << std::endl;
}

std::string Victim::getName() const {
  return this->name;
}


std::ostream &operator<<(std::ostream &res, Victim const &obj) {
  res << "I am " << obj.getName() << ", and I like otters !" << std::endl;
  return res;
}

  void Victim::getPolymorphed() const {
    std::cout << this->name << " has been turned into a cute little sheep !"
                            << std::endl;
  }
