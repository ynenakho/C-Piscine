#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base *generate(void) {
	Base	*res;
	int		x = std::rand() % 3;

	switch(x) {
		case 0:
			std::cout << "Making A class" << std::endl;
			res = new A;
			break;
		case 1:
			std::cout << "Making B class" << std::endl;
			res = new B;
			break;
		default:
			std::cout << "Making C class" << std::endl;
			res = new C;
	}
	return (res);
}

void identify_from_pointer(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify_from_reference( Base &p) {
	if (dynamic_cast<A*>(&p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(&p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(&p))
		std::cout << "C" << std::endl;
}

int main(void) {
	std::srand(time(NULL));
	Base	*ptr = generate();

	identify_from_pointer(ptr);
	identify_from_reference(*ptr);
	return (0);
}
