#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>

class FragTrap {
public:
  FragTrap(std::string name = "Default");
  ~FragTrap();
  FragTrap(FragTrap const &src);
  FragTrap &operator= (const FragTrap &obj);
  void rangedAttack(std::string const & target);
  void meleeAttack(std::string const & target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  void vaulthunter_dot_exe(std::string const & target);
  void stats();

private:
  std::string type;
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
