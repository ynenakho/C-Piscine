#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
public:

  Fixed();
  Fixed(Fixed const &src);
  ~Fixed();

  Fixed &operator=(Fixed const &obj);

  int getRawBits( void ) const;
  void setRawBits( int const raw );
private:
  int fixedValue;
  static const int numOfBits = 8;
};

#endif
