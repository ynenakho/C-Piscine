#include <list>
#include <vector>

#include "easyfind.hpp"

template <typename T>
void searchResult(T container, int search, std::string type) {
	std::cout << "Searching in " << type << std::endl;
	try {
		for (typename T::iterator it = container.begin(); it != container.end(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;
		int ret = easyfind(container, search);
		std::cout << "Found value [" << search << "] at index [" << ret << "]" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Value [" << search << "] not found" << std::endl;
	}
}

void testVector(size_t len, int search) {
	std::vector<int> myvector;
	std::vector<int>::iterator it;

	for (size_t i = 0; i < len; i++) {
		it = myvector.begin();
		myvector.insert(it, std::rand() % 10);
	}
	searchResult(myvector, search, "vector");
}

void testList(size_t len, int search) {
	std::list<int> list;

	for (size_t i = 0; i < len; i++)
		list.push_back(std::rand() % 10);
	searchResult(list, search, "list");
}

int	main(int ac, char **av) {
	std::srand(time(0));

	if (ac != 2) {
		std::cout << "Usage: ./easyfind [number]" << std::endl;
		return (0);
	}
	int search = atoi(av[1]);
	testList(10, search);
	testVector(10, search);
	return (0);
}
