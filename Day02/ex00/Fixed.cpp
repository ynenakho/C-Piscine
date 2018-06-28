#include "Fixed.hpp"

Fixed::Fixed() {
  this->fixedValue = 0;
  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::Fixed(Fixed const &src) {

  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}
Fixed::~Fixed() {
  std::cout << "Destractor called" << std::endl;
  return;
}

Fixed &Fixed::operator=(Fixed const &obj) {
  std::cout << "Assignation operator called" << std::endl;
  this->fixedValue = obj.getRawBits();
  return *this;
}

int Fixed::getRawBits( void ) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->fixedValue;
}

void Fixed::setRawBits( int const raw ) {
  this->fixedValue = raw;
  std::cout << "setRawBits member function called" << std::endl;
  return ;
}
