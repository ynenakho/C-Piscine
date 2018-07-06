#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iterator>
#include <iostream>

template<typename T>
int easyfind(T obj, int toFind) {
  typename T::iterator it;
  for (it = obj.begin(); it != obj.end(); ++it) {
    if (*it == toFind)
      return (std::distance(obj.begin(), it));
  }
  throw std::exception();
}

#endif
