#include "A.hpp"

A::A(void) {}

A::~A(void) {}

A::A(const A &src) {
	*this = src;
}

A &A::operator= (const A &obj) {
	(void)obj;
	return (*this);
}
