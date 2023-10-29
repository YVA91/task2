
#include <iostream>
#include <locale>
#include <Windows.h>
#include <exception>
#include <string>


class Smart_array {
private:
	int size = 0;
	int* arr;
	int count = 0;
public:
	Smart_array (int a_size) {
		size = a_size;
		arr = new int[size];
	}
	~ Smart_array() {
		delete[] arr;
	}

	void add_element(int a) {
		if (count < size) {
			arr[count] = a;
			count++;
		}
		else {
			throw std::exception("Слишком много элементов");
		}
	}

	int get_element(int b) {
		if (b >= 0 && b < size) {
			return arr[b];
		}
		else {
			throw std::length_error("Такого элемента не существует");
		}
	}


};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		Smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);
		arr.add_element(14);
		arr.add_element(15);
		std::cout << arr.get_element(1) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	} 
	catch (const std::length_error& ex) {
		std::cout << ex.what() << std::endl;
	}
}
