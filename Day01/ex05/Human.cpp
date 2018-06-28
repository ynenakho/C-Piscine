#include "Human.hpp"
#include "Brain.hpp"

const Brain &Human::getBrain() {
    return (this->myBrain);
 }

 std::string Human::identify() {
   return getBrain().identify();
 }

 Human::Human() {
   std::cout << "Human activated" << std::endl;
   return;
 }

 Human::~Human() {
   std::cout << "Human deactivated" << std::endl;
 }
