#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
public:

  Fixed();
  Fixed(Fixed const &src);
  Fixed(const float fnum);
  Fixed(const int num);
  ~Fixed();

  int toInt( void ) const;
  int getRawBits( void ) const;
  void setRawBits( int const raw );
  float toFloat( void ) const;
  bool operator<(Fixed const &obj) const;
  bool operator>(Fixed const &obj) const ;
  bool operator>=(Fixed const &obj) const ;
  bool operator<=(Fixed const &obj) const ;
  bool operator==(Fixed const &obj) const ;
  bool operator!=(Fixed const &obj) const ;
  Fixed &operator=(Fixed const &obj);
  Fixed operator+(Fixed const &obj);
  Fixed operator-(Fixed const &obj);
  Fixed operator/(Fixed const &obj);
  Fixed operator*(Fixed const &obj);
  Fixed &operator++();
  Fixed &operator--();
  Fixed operator++(int);
  Fixed operator--(int);
  static Fixed &min(Fixed &a, Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);

private:
  
  int fixedValue;
  static const int numOfBits = 8;
};

std::ostream &operator<<(std::ostream &res, Fixed const &val);
#endif
