#include "PhoneBook.class.hpp"
#include <stdio.h>

PhoneBook::PhoneBook()
{
  return;
}

PhoneBook::~PhoneBook()
{
  return;
}

void PhoneBook::createEntry()
{
  std::getline(std::cin, this->fname);
  std::cout << "first name: ";
  std::getline(std::cin, this->fname);
  std::cout << "last name: ";
  std::getline(std::cin, this->lname);
  std::cout << "nickname: ";
  std::getline(std::cin, this->nickname);
  std::cout << "login: ";
  std::getline(std::cin, this->login);
  std::cout << "postal address: ";
  std::getline(std::cin, this->paddr);
  std::cout << "email address: ";
  std::getline(std::cin, this->eaddr);
  std::cout << "phone number: ";
  std::getline(std::cin, this->phone);
  std::cout << "birthday date: ";
  std::getline(std::cin, this->bdate);
  std::cout << "favorite meal: ";
  std::getline(std::cin, this->meal);
  std::cout << "underwear color: ";
  std::getline(std::cin, this->color);
  std::cout << "darkest secret: ";
  std::getline(std::cin, this->secret);
  return;
}

std::string checkLength(std::string str)
{
  std::string name;

  if (str.length() > 10)
    name = str.substr(0, 9) + ".";
  else
    name = str;
  return name;
}

void PhoneBook::displayShort(int i)
{
  std::cout << "\033[1;32m" << std::setw(10) << std::to_string(i) << "|";
  std::cout << std::setw(10) << checkLength(this->fname)  << "|";
  std::cout << std::setw(10)  << checkLength(this->lname) << "|";
  std::cout << std::setw(10) << checkLength(this->nickname)  << "\033[0m" << std::endl;
}

void PhoneBook::displayAll()
{
  std::cout << "\033[1;35m" << "first name: " << this->fname << std::endl;
  std::cout << "last name: "<< this->lname << std::endl;
  std::cout << "nickname: "<< this->nickname << std::endl;
  std::cout << "login: "<< this->login << std::endl;
  std::cout << "postal address: "<< this->paddr << std::endl;
  std::cout << "email address: "<< this->eaddr<< std::endl;
  std::cout << "phone number: "<< this->phone<< std::endl;
  std::cout << "birthday date: "<< this->bdate << std::endl;
  std::cout << "favorite meal: "<< this->meal << std::endl;
  std::cout << "underwear color: "<< this->color << std::endl;
  std::cout << "darkest secret: "<< this->secret << "\033[0m" << std::endl;
  return;
}
