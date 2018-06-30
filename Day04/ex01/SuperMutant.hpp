#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include <iostream>
#include "Enemy.hpp"

class SuperMutant : public Enemy
{

public:
  SuperMutant();
  SuperMutant(SuperMutant const &obj);
  SuperMutant &operator= (const SuperMutant &obj);
  virtual ~SuperMutant();
  virtual void takeDamage(int);
};

#endif
