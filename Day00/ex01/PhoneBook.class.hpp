#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include <string>
# include <iomanip>
# include <iostream>

class PhoneBook
{
public:
  std::string  fname;
  std::string  lname;
  std::string  nickname;
  std::string  login;
  std::string  paddr;
  std::string  eaddr;
  std::string  phone;
  std::string  bdate;
  std::string  meal;
  std::string  color;
  std::string  secret;

  PhoneBook();
  ~PhoneBook();

  void createEntry(void);
  void displayShort(int i);
  void displayAll();
};

#endif
