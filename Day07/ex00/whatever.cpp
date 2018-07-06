#include <iostream>

template <typename T>
void swap(T &one, T &two) {
	T	tmp = one;
	one = two;
	two = tmp;
}

template <typename T>
T max(T one, T two) {
	return (one > two ? one : two);
}

template <typename T>
T min(T one, T two) {
	return (one < two ? one : two);
}

int main() {
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

	std::string c = "abcde1";
	std::string d = "abcde2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;
	return (0);
}
