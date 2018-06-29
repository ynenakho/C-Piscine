#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>

class ScavTrap {
public:
  ScavTrap(std::string name = "Default");
  ~ScavTrap();
  void rangedAttack(std::string const & target);
  void meleeAttack(std::string const & target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void challengeNewcomer(std::string const & target);

private:
  int hitPoints;
  int maxHitPoints;
  int energyPoints;
  int maxEnergyPoints;
  int level;
  std::string name;
  int meleeAttackDmg;
  int rangedAttackDmg;
  int armorDmgReduction;
};

#endif
