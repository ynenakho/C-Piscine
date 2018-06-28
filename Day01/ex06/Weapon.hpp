#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <sstream>

class Weapon {
private:
  std::string type;
public:

  Weapon(std::string wType);
  ~Weapon();


  const std::string &getType();
  void setType(std::string wType);
};


#endif
