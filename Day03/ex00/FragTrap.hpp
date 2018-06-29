#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>

class FragTrap {
public:
  FragTrap(std::string name = "Default");
  ~FragTrap();
  void rangedAttack(std::string const & target);
  void meleeAttack(std::string const & target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void vaulthunter_dot_exe(std::string const & target);

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
