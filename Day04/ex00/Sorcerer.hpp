#ifndef SORCERER_HPP
# define SORCERER_HPP
#include <iostream>
#include "Victim.hpp"

class Sorcerer {
private:
  std::string name;
  std::string title;

public:
  Sorcerer(std::string name = "Vasya", std::string title = "The witcher");
  Sorcerer(Sorcerer const &src);
  Sorcerer &operator= (const Sorcerer &obj);
  ~Sorcerer();

  void introduce();
  std::string getName() const;
  std::string getTitle() const;
  void polymorph(Victim const &obj) const;
};

std::ostream &operator<<(std::ostream &res, Sorcerer const &obj);

#endif
