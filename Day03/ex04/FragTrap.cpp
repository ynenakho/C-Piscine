#include "FragTrap.hpp"

void FragTrap::vaulthunter_dot_exe(std::string const & target) {
  if (this->energyPoints < 25) {
    std::cout << this->type << this->name << " doesnt have enougth energy." << std::endl;
    return;
  }
  this->energyPoints -= 25;
  std::string attackArray[5] = {
    "Hammer",
    "Gun",
    "Shovel",
    "Fork",
    "Rock"
  };
  std::cout << this->type << this->name << " attacks " << target
            << " with " << attackArray[rand() % 5]
            << "!" << std::endl;
}

FragTrap::~FragTrap() {
  std::cout << "FR4G-TP named " << this->name << " destructed." << std::endl;
  return;
}

FragTrap::FragTrap(std::string name) {
  srand(time(NULL));
  this->name = name;
  this->type = "FR4G-TP ";
  this->hitPoints = 100;
  this->maxHitPoints = 100;
  this->energyPoints = 100;
  this->maxEnergyPoints = 100;
  this->level = 1;
  this->meleeAttackDmg = 30;
  this->rangedAttackDmg = 20;
  this->armorDmgReduction = 5;
  std::cout << "FR4G-TP named " << this->name << " created." << std::endl;
  return;
}

FragTrap::FragTrap(FragTrap const &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

FragTrap &FragTrap::operator= (const FragTrap &obj)
{
  this->name = obj.name;
  this->type = obj.type;
  this->hitPoints = obj.hitPoints;
  this->maxHitPoints = obj.maxHitPoints;
  this->energyPoints = obj.energyPoints;
  this->maxEnergyPoints = obj.maxEnergyPoints;
  this->level = obj.level;
  this->meleeAttackDmg = obj.meleeAttackDmg;
  this->rangedAttackDmg = obj.rangedAttackDmg;
  this->armorDmgReduction = obj.armorDmgReduction;
	return (*this);
}
