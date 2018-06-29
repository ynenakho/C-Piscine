#ifndef VICTIM_HPP
# define VICTIM_HPP
#include <iostream>

class Victim {
protected:
  std::string name;

public:
  Victim(std::string name = "Bobo");
  Victim(Victim const &src);
  Victim &operator= (const Victim &obj);
  ~Victim();

  void introduce();
  std::string getName() const;
  virtual void getPolymorphed() const;

};

std::ostream &operator<<(std::ostream &res, Victim const &obj);

#endif
