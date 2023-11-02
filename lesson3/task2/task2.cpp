#include <iostream>
#include <locale>
#include <Windows.h>
#include <exception>
#include <string>
#include <algorithm>

class smart_array {
public:
	int size = 0;
	int* arr;
	int count = 0;

public:
	smart_array(int a_size) {
		size = a_size;
		arr = new int[size];
	}
	~smart_array() {
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

	smart_array& operator=(const smart_array& v)
	{
		
		if (this->arr != nullptr) {
			delete[] this->arr;
		}
		
		this->size = v.size;
		this->count = v.count;

		this->arr = new int[size] {};
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = v.arr[i];
		}
		
		return *this;
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(7);
		new_array.add_element(8);

		std::cout << arr.get_element(1) << std::endl;
		std::cout << new_array.get_element(1) << std::endl;

		

		arr = new_array;

		std::cout << arr.get_element(1) << std::endl;
		std::cout << new_array.get_element(1) << std::endl;

	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (const std::length_error& ex) {
		std::cout << ex.what() << std::endl;
	}
}