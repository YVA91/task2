

#include <iostream>
#include <locale>
#include <Windows.h>
#include <set>

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int allItem;
    std::cout << "[IN]:" << "\n";
    std::cin >> allItem;
 
    std::set<int, std::greater<int>> s;

    for (int i = 0; i < allItem; i++) {
        int x;
        std::cin >> x;
        s.insert(x);
    }

    std::cout << "[OUT]:" << "\n";
    for (const auto& elem : s) {
        std::cout << elem << std::endl;
    }
}
