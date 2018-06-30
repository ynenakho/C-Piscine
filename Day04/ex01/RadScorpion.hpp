#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP
# include <iostream>
#include "Enemy.hpp"

class RadScorpion : public Enemy
{

public:
  RadScorpion();
  RadScorpion(RadScorpion const &obj);
  virtual ~RadScorpion();
  RadScorpion &operator= (const RadScorpion &obj);
 // virtual void takeDamage(int);
};

#endif
