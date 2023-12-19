
#include <iostream>
#include <vector>

class Count_functor {
    
    int sum = 0;
    int count = 0;

public: 

    void operator()(std::vector<int> v) {
        for (int i = 0; i < v.size(); i++) {
            if (v[i] % 3 == 0) {
                sum = sum+v[i];
                count++;
            }
        }
    }; 

    int get_sum() {
        return sum;
    }
        
    int get_count() {
        return count;
    }

};

int main()
{
    std::vector<int> v = { 4, 1, 3, 6, 25, 54 };
    std::cout << "[IN]: ";
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << ", ";
    }
    std::cout << "\n";
    Count_functor count_functor;
    count_functor(v);
    std::cout << "[OUT]: get_sum() = " << count_functor.get_sum() << "\n";
    std::cout << "[OUT]: get_count() = " << count_functor.get_count() << "\n";
}

