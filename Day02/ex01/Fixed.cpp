#include "Fixed.hpp"

Fixed::Fixed(const float fnum) {
  this->fixedValue = std::round(fnum * (1 << this->numOfBits));
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
  this->fixedValue = num * (1 << this->numOfBits);
  std::cout << "Int constructor called" << std::endl;
}

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
  return this->fixedValue;
}

void Fixed::setRawBits( int const raw ) {
  this->fixedValue = raw;
  std::cout << "setRawBits member function called" << std::endl;
  return ;
}

float Fixed::toFloat( void ) const {
  return (float)this->fixedValue / (1 << this->numOfBits);
}

 int Fixed::toInt( void ) const {
   return (int)this->fixedValue / (1 << this->numOfBits);
 }

std::ostream &operator<<(std::ostream &res, Fixed const &val) {
  res << val.toFloat();
  return res;
}
