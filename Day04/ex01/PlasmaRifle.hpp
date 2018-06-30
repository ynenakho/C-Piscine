#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{

public:
  PlasmaRifle();
  PlasmaRifle(PlasmaRifle const &obj);
  PlasmaRifle &operator= (const PlasmaRifle &obj);
  virtual ~PlasmaRifle();
  virtual void attack() const;
};

#endif
