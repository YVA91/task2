
#include <iostream>
#include <locale>
#include <Windows.h>
#include <vector>
#include <algorithm>

#include <list>
#include <set>

template <typename T>
void print_container(const T& container) {
	auto elem = container.begin();
	while (elem != container.end()) {
		std::cout << *elem << " ";
		elem++;
	}
	std::cout << "\n";
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::set<std::string> test_set = { "one", "two", "three", "four" };
	print_container(test_set); 
	std::list<std::string> test_list = { "one", "two", "three", "four" };
	print_container(test_list); 
	std::vector<std::string> test_vector = { "one", "two", "three", "four" };
	print_container(test_vector); 
}

