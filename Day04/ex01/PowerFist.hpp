#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include <iostream>
#include "AWeapon.hpp"

class PowerFist : public AWeapon
{

public:
  PowerFist();
  PowerFist(PowerFist const &obj);
  PowerFist &operator= (const PowerFist &obj);
  virtual ~PowerFist();
  virtual void attack() const;
};

#endif
