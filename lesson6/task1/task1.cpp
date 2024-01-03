
#include <iostream>
#include <locale>
#include <Windows.h>
#include <set>
#include <string>
#include <algorithm>
#include <map>

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string str;
    std::cout << "Введите фразу:" << std::endl;
    std::getline(std::cin, str);
    std::cout<< "[IN]: " << str << std::endl;
    std::multiset<char> m;
    std::map<char, int> mm;
    std::multimap<int, char, std::greater<int> > mmm;


    for (int i = 0; i < str.size(); i++) {
        m.insert(str[i]);
    }

    for (const auto& elem : m) {
        int i;
        i = m.count(elem);
        mm[elem] = i;
    }

    for (const auto& elem : mm) {
        mmm.insert(std::make_pair(elem.second, elem.first));
    }

    std::cout << "[OUT]: " << std::endl;

    for (const auto& elem : mmm) {
        std::cout << elem.second << ": " << elem.first << std::endl;
    }
      
}
