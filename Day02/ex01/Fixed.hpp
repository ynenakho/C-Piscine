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

  Fixed &operator=(Fixed const &obj);

  int getRawBits( void ) const;
  void setRawBits( int const raw );
  float toFloat( void ) const;
  int toInt( void ) const;
private:
  int fixedValue;
  static const int numOfBits = 8;
};

std::ostream &operator<<(std::ostream &res, Fixed const &val);

#endif
