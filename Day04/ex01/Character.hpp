#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
private:
    int actonPoints;
    AWeapon *weapon;
    std::string name;
public:
  Character();
  Character(const Character &obj);
  Character(const std::string &name);
  ~Character();
  Character &operator= (const Character &rhs);

  void recoverAP();
  void equip(AWeapon *weapon);
  void attack(Enemy *enemy);
  int getAP() const;
  AWeapon *getWeapon() const;
  const std::string getName() const;
};

std::ostream &operator<< (std::ostream &res, const Character &rhs);

#endif
