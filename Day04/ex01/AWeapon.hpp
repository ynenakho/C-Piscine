#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>

class AWeapon
{
protected:
  std::string name;
  int damage;
  int apcost;
public:
  AWeapon();
  AWeapon(std::string const & name, int apcost, int damage);
  AWeapon &operator= (const AWeapon &obj);
  virtual ~AWeapon();
  std::string const getName() const;
  int getAPCost() const;
  int getDamage() const;
  virtual void attack() const = 0;
};

#endif
