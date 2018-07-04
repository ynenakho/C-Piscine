#include "B.hpp"

B::B(void) {}

B::~B(void) {}

B::B(const B &src) {
	*this = src;
}

B &B::operator= (const B &obj) {
	(void)obj;
	return (*this);
}
