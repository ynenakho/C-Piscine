#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap {
public:
  SuperTrap(std::string name = "Default");
  ~SuperTrap();
  SuperTrap(SuperTrap const &src);
  SuperTrap &operator= (const SuperTrap &obj);
  void meleeAttack(std::string const &target);
  void rangedAttack(std::string const &target);
};

#endif
