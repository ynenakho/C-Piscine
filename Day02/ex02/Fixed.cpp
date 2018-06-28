#include "Fixed.hpp"

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  return (a > b ? a : b);
}

const Fixed &Fixed::min(Fixed const  &a, Fixed const &b) {
  return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed  &a, const Fixed  &b) {
  return (a > b ? a : b);
}

Fixed &Fixed::operator++() {
   this->fixedValue++;
   return *this;
}

Fixed &Fixed::operator--() {
   this->fixedValue--;
   return *this;
}

Fixed Fixed::operator++(int) {
   Fixed temp = *this;
   ++(*this);
   return temp;
}

Fixed Fixed::operator--(int) {
   Fixed temp = *this;
   --(*this);
   return temp;
}

bool Fixed::operator<(Fixed const &obj) const {
  return this->fixedValue < obj.getRawBits();
}

bool Fixed::operator>(Fixed const &obj) const  {
  return this->fixedValue > obj.getRawBits();
}

bool Fixed::operator<=(Fixed const &obj)  const {
  return this->fixedValue <= obj.getRawBits();
}

bool Fixed::operator>=(Fixed const &obj)  const {
  return this->fixedValue >= obj.getRawBits();
}

bool Fixed::operator==(Fixed const &obj) const  {
  return this->fixedValue == obj.getRawBits();
}

bool Fixed::operator!=(Fixed const &obj) const  {
  return this->fixedValue != obj.getRawBits();
}

Fixed Fixed::operator+(Fixed const &obj) {
  return Fixed(this->toFloat() + obj.toFloat());
}
Fixed Fixed::operator-(Fixed const &obj) {
  return Fixed(this->toFloat() - obj.toFloat());
}
Fixed Fixed::operator/(Fixed const &obj) {
  return Fixed(this->toFloat() / obj.toFloat());
}
Fixed Fixed::operator*(Fixed const &obj) {
  return Fixed(this->toFloat() * obj.toFloat());
}

Fixed::Fixed(const float fnum) {
  this->fixedValue = std::round(fnum * std::pow(2, this->numOfBits));
//  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const int num) {
  this->fixedValue = num * std::pow(2, this->numOfBits);
//  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed() {
  this->fixedValue = 0;
//  std::cout << "Default constructor called" << std::endl;
  return;
}

Fixed::Fixed(Fixed const &src) {
//  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}
Fixed::~Fixed() {
//  std::cout << "Destractor called" << std::endl;
  return;
}

Fixed &Fixed::operator=(Fixed const &obj) {
//  std::cout << "Assignation operator called" << std::endl;
  this->fixedValue = obj.getRawBits();
  return *this;
}

int Fixed::getRawBits( void ) const {
  return this->fixedValue;
}

void Fixed::setRawBits( int const raw ) {
  this->fixedValue = raw;
//  std::cout << "setRawBits member function called" << std::endl;
  return ;
}

float Fixed::toFloat( void ) const {
  return (float)this->fixedValue / std::pow(2, this->numOfBits);
}

 int Fixed::toInt( void ) const {
   return (int)this->fixedValue / std::pow(2, this->numOfBits);
 }

std::ostream &operator<<(std::ostream &res, Fixed const &val) {
  res << val.toFloat();
  return res;
}
