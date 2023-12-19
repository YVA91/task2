
#include <iostream>

template <class T>
class Table {
    public:
        Table(int r, int c) {
            this->row = r;
            this->col = c;
            elements = new T * [row]{};
            for (int i=0; i < row; i++) {
                elements[i] = new T[col]{};
            }
        };
        ~Table() {
            for (int i = 0; i < row; i++)
            {
                delete[] elements[i];
            }
            delete[] elements;
        }

       T* operator[](int i) {
            return elements[i];
        }
       T* operator[](int i) const {
           return elements[i];
       }
     

        int Size() const {
            return row * col;
        }

    private:
        T** elements = nullptr;
        int row = 0;
        int col = 0;
};



int main()
{
    auto test = Table<int>(2, 8);
    test[0][0] = 4;
    
    /*for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 8; j++) {
            std::cout << test[i][j] << " ";
        }
        std::cout << "\n";
    }*/

    std::cout << test[0][0];
};
