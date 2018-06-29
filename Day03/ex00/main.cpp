#include "FragTrap.hpp"

int main() {

  FragTrap warrior("Vasya");
  warrior.stats();
  warrior.rangedAttack("Greg");
  warrior.meleeAttack("Greg");
  warrior.rangedAttack("Greg");
  warrior.rangedAttack("Greg");
  warrior.rangedAttack("Greg");
  warrior.rangedAttack("Greg");
  warrior.stats();
  warrior.takeDamage(50);
  warrior.takeDamage(25);
  warrior.takeDamage(50);
  warrior.stats();
  warrior.beRepaired(50);
  warrior.beRepaired(50);
  warrior.beRepaired(50);
  warrior.stats();
  FragTrap warrior1("Killer");
  warrior1.vaulthunter_dot_exe("Fool");
  warrior1.vaulthunter_dot_exe("Fool");
  warrior1.vaulthunter_dot_exe("Fool");
  warrior1.vaulthunter_dot_exe("Fool");
  warrior1.vaulthunter_dot_exe("Fool");
  return 0;
}
