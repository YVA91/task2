
#include <iostream>
#include <vector>

template <class T>
T squar(T x) {
    return x * x;
}
template<class T>
void squar(std::vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i]* v[i] << ", ";
    }
    std::cout << "\n";
   
}


int main()
{
    std::vector<int> x = { -1, 4, 8 };
    std::cout << "[IN]: ";
    for (int i = 0; i < x.size(); i++) {
        std::cout << x[i] << ", ";
    } 
    std::cout << "\n";
    std::cout << "[OUT]: "; 
    squar(x);
  
    int y = 4;
    std::cout << "[IN]: " << y << "\n" << "[OUT]: " << squar(y);
   
}
