#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap {
public:
  ClapTrap();
  ~ClapTrap();
  ClapTrap(ClapTrap const &src);
  void rangedAttack(std::string const & target);
  void meleeAttack(std::string const & target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void stats();

protected:
  int hitPoints;
  int maxHitPoints;
  int energyPoints;
  int maxEnergyPoints;
  int level;
  std::string name;
  int meleeAttackDmg;
  int rangedAttackDmg;
  int armorDmgReduction;
  std::string type;

};

#endif
