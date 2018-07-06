#include "Array.hpp"
#include <iostream>
#include <unistd.h>
#include <time.h>

int 	main() {

	srand(time(NULL));
	Array<int> test(20);
	Array<char> c_array(73);

	for (int i = 0; i < test.size(); i++)
		test[i] = rand() % 100;
	std::cout << test << std::endl;



	for (int i = 0 ; i < c_array.size(); i++) {
		char randomLetter = 'a' +  ( rand() % 26 ) ;
		c_array[i] = randomLetter;
	}
	std::cout << c_array << std::endl;

	Array<std::string> strings(5);

	std::string const	db[5] = {
		"first", "second", "third", "forth", "fifth"
	};

	for (int i = 0; i < strings.size(); i++) {
		strings[i] = db[rand() % 5];
	}
	std::cout << strings << std::endl;
}
