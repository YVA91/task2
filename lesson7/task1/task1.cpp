
#include <iostream>
#include <locale>
#include <Windows.h>
#include <vector>
#include <algorithm>


template <class T> 
void delete_duplicates(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    auto last = std::unique(v.begin(), v.end());
    v.erase(last, v.end());
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::vector <int> v{ 1, 1, 2, 5, 6, 1, 2, 4 };

    std::cout << "[IN] ";

    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";

    delete_duplicates(v);

    std::cout << "[OUT] ";

    for (const auto& elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
    
}

