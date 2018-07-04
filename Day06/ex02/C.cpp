#include "C.hpp"

C::C(void) {}

C::~C(void) {}

C::C(const C &src) {
	*this = src;
}

C &C::operator= (const C &obj) {
	static_cast<void>(obj);
	return (*this);
}
