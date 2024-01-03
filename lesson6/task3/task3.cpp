
#include <iostream>
#include <locale>
#include <Windows.h>

template<class T>
class MyVector {

private:
    T* vector = nullptr;
    size_t size_v = 0;
    size_t capacity_v = 0;

public:

    MyVector(size_t s) {
        capacity_v = s;
        size_v = s;
        vector = new T[capacity_v]{};
    };

    ~MyVector() {
        delete[] vector;
    };

    MyVector(const MyVector&) = delete;
    MyVector& operator=(const MyVector&) = delete;

    size_t size()
    {
        return size_v;
    }

   size_t capacity() {
        return capacity_v;
    }

    void push_back(T value) {
        if (size_v == capacity_v) {
            capacity_v = capacity_v > 0 ? capacity_v * 2 : 2;
            T* newVector = new T[capacity_v]{};
            for (int i = 0; i < size_v; i++) {
                newVector[i] = vector[i];
            }
            delete[] vector;
            vector = newVector;
        }
        size_v++;
        vector[size_v] = value;
    }

    T& at(size_t num) {
        if (num < 0 || num > size_v) {
            throw std::out_of_range("Такого элемента не существует");
        }
        return vector[num];
    }

    const T& at(size_t num) const {
        if (num < 0 || num > size_v) {
            throw std::out_of_range("Такого элемента не существует");
        }
        return vector[num];
    }

};


int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    MyVector <int> v1(5);


    try {
        std::cout << v1.at(1) << std::endl;
        std::cout << v1.size() << std::endl;
        v1.push_back(6);
        std::cout << v1.capacity() << std::endl;
        std::cout << v1.at(6) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }



}


