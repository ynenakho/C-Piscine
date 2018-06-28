#ifndef HUMANA_HPP
# define HUMANA_HPP
# include <iostream>
# include <sstream>
# include "Weapon.hpp"

class HumanA {
private:
  Weapon *weapon;
  std::string name;
public:
  HumanA(std::string name);
  HumanA(std::string name, Weapon &weapon);
  ~HumanA();
  void attack();
};


#endif
