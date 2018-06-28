#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain activated" << std::endl;
  return;
}

Brain::~Brain() {
  std::cout << "Brain deactivated" << std::endl;
}

std::string Brain::identify() const {
  std::ostringstream address;
  address << (void const *)this;
  std::string name = address.str();
  return name;
}
