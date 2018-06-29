#include "FragTrap.hpp"

int main() {

  FragTrap warrior("Vasya");
  warrior.rangedAttack("Pidor");
  warrior.meleeAttack("Pidor");
  warrior.rangedAttack("Pidor");
  warrior.rangedAttack("Pidor");
  warrior.rangedAttack("Pidor");
  warrior.rangedAttack("Pidor");
  warrior.takeDamage(50);
  warrior.takeDamage(25);
  warrior.takeDamage(50);
  warrior.beRepaired(50);
  warrior.beRepaired(50);
  warrior.beRepaired(50);
  FragTrap warrior1("Killer");
  warrior1.vaulthunter_dot_exe("Gandon");
  warrior1.vaulthunter_dot_exe("Gandon");
  warrior1.vaulthunter_dot_exe("Gandon");
  warrior1.vaulthunter_dot_exe("Gandon");
  warrior1.vaulthunter_dot_exe("Gandon");
  return 0;
}
