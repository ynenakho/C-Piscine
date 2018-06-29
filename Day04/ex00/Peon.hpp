#ifndef PEON_HPP
# define PEON_HPP
#include <iostream>
#include "Sorcerer.hpp"
#include "Victim.hpp"

class Peon : public Victim {
public:
  Peon(std::string name = "Gnom");
  Peon(Peon const &src);
  Peon &operator= (const Peon &obj);
  ~Peon();

  std::string getName() const;
  virtual void getPolymorphed() const;

};

#endif
