#include "Human.hpp"

void Human::meleeAttack(std::string const & target) {
  std::cout << "Attacked " << target << " with melee attack" << std::endl;
  return;
}


void Human::rangedAttack(std::string const & target) {
  std::cout << "Attacked " << target << " with ranged attack" << std::endl;
  return;
}

void Human::intimidatingShout(std::string const & target) {
  std::cout << "Shouted " << target << std::endl;
  return;
}

void Human::action(std::string const & action_name, std::string const & target) {
  std::string actionArray[3] = { "meleeAttack" , "rangedAttack" , "intimidatingShout" };
  typedef void (Human::*Actions)(std::string const & target);
  Actions actions[3] = {&Human::meleeAttack, &Human::rangedAttack, &Human::intimidatingShout};
  for (int i = 0; i < 3; i++)
    if (actionArray[i] == action_name)
      (this->*actions[i])(target);
  return;
}
