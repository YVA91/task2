
#include <iostream>
#include <vector>

template <class T>
T squar(T x) {
    return x*x;
}

template<class T>
std::vector<T> squar(std::vector<T> v) {
    std::vector<T> t;
    for (int i = 0; i < v.size(); i++) {
        t.push_back(v[i] * v[i]);
    }
    return t;
}


int main()
{
    int y = 4;
    int x = squar(y);
    std::cout << "[IN]: " << y << "\n" << "[OUT]: " << x << "\n";

    std::vector<int> v = { -1, 4, 8 };
    std::cout << "[IN]: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ", ";
    } 
    std::cout << "\n";
    std::cout << "[OUT]: "; 

    std::vector<int> t = squar(v);
    for (int i = 0; i < t.size(); i++) {
        std::cout << t[i] << ", ";
    }
}
