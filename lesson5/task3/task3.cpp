
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class Count_functor {
    
    int sum = 0;
    int count = 0;

public: 

    void operator()(int v) {
        if (v % 3 == 0) {
            sum = sum+v;
            count++;
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
    Count_functor count_functor;
    count_functor = std::for_each(v.begin(), v.end(), count_functor);

    std::cout << "[OUT]: get_sum() = " << count_functor.get_sum() << "\n";
    std::cout << "[OUT]: get_count() = " << count_functor.get_count() << "\n";
}

