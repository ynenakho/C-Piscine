#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>

class ScavTrap {
public:
  ScavTrap(std::string name = "Default");
  ~ScavTrap();
  ScavTrap(ScavTrap const &src);
  ScavTrap &operator= (const ScavTrap &obj);
  void rangedAttack(std::string const & target);
  void meleeAttack(std::string const & target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void challengeNewcomer(std::string const & target);
  void stats();

private:
  std::string type;
  std::string name;
  int hitPoints;
  int maxHitPoints;
  int energyPoints;
  int maxEnergyPoints;
  int level;
  int meleeAttackDmg;
  int rangedAttackDmg;
  int armorDmgReduction;
};

#endif
