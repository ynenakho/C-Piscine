#include "ScavTrap.hpp"

void ScavTrap::challengeNewcomer(std::string const & target) {
  if (this->energyPoints < 25) {
    std::cout << "CL4P-TP " << this->name << " doesnt have enougth energy." << std::endl;
    return;
  }
  this->energyPoints -= 25;
  std::string attackArray[5] = {
    " Dance",
    " Trip",
    " Fall down",
    " Shoot himself",
    " Cook a cake"
  };
  std::cout << "CL4P-TP " << this->name << " made " << target
            << attackArray[rand() % 5]
            << "!" << std::endl;
}

ScavTrap::~ScavTrap() {
  std::cout << "CL4P-TP named " << this->name << " destructed." << std::endl;
  return;
}

ScavTrap::ScavTrap(std::string name) {
  srand(time(NULL));
  this->name = name;
  this->type = "CL4P-TP ";
  this->hitPoints = 100;
  this->maxHitPoints = 100;
  this->energyPoints = 50;
  this->maxEnergyPoints = 50;
  this->level = 1;
  this->meleeAttackDmg = 20;
  this->rangedAttackDmg = 13;
  this->armorDmgReduction = 3;
  std::cout << "CL4P-TP named " << this->name << " created." << std::endl;
  return;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}
