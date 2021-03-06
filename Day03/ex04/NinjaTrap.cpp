#include "NinjaTrap.hpp"

void NinjaTrap::ninjaShoebox(NinjaTrap const & obj) {
  std::cout << this->type << this->name << " kiked " << obj.getType()
  << obj.getName() << " and he flew away." << std::endl;
}
void NinjaTrap::ninjaShoebox(FragTrap const & obj) {
  std::cout << this->type << this->name << " jumped on " << obj.getType()
  << obj.getName() << " and made him fall." << std::endl;
}
void NinjaTrap::ninjaShoebox(ScavTrap const & obj) {
  std::cout << this->type << this->name << " ran away " << obj.getType()
  << "from " << obj.getName() << " and made him feel lonly." << std::endl;
}

NinjaTrap::~NinjaTrap() {
  std::cout << "NNJ4-TP named " << this->name << " destructed." << std::endl;
  return;
}

NinjaTrap::NinjaTrap(std::string name) {
  srand(time(NULL));
  this->name = name;
  this->type = "NNJ4-TP ";
  this->hitPoints = 60;
  this->maxHitPoints = 60;
  this->energyPoints = 120;
  this->maxEnergyPoints = 120;
  this->level = 1;
  this->meleeAttackDmg = 60;
  this->rangedAttackDmg = 5;
  this->armorDmgReduction = 0;
  std::cout << "NNJ4-TP named " << this->name << " created." << std::endl;
  return;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) {
  std::cout << "Copy constructor called" << std::endl;
  *this = src;
  return;
}

NinjaTrap &NinjaTrap::operator= (const NinjaTrap &obj)
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
