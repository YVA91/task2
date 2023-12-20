
#include <iostream>
#include <locale>
#include <Windows.h>

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
            if (i > row || i > col) {
                throw std::length_error("Такого элемента не существует");
            }
            else if (i < 0) {
                throw std::length_error("Индекс не может быть отрицательным");
            }
            else {
                return elements[i];
            }
        }
       T* operator[](int i) const {
           if (i > row || i > col) {
               throw std::length_error("Такого элемента не существует");
           }
           else if (i < 0) {
               throw std::length_error("Индекс не может быть отрицательным");
           }
           else {
               return elements[i];
           }
       }
     

        int Size() const {
            return row * col;
        }
        
        Table& operator=(const Table& v)
        {

            if (this->elements != nullptr) {
                for (int i = 0; i < row; i++)
                {
                    delete[] elements[i];
                }
                delete[] elements;
            }

            this->row = v.row;
            this->col = v.col;

            this->elements = new T * [row] {};
            for (int i = 0; i < row; i++) {
                elements[i] = new T[col]{};
            }
        
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    this->elements[i][j] = v.elements[i][j];
                }
            }

            return *this;
        }
        
    private:
        T** elements = nullptr;
        int row = 0;
        int col = 0;
};



int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Table<int> t1(2, 3);
    Table<int> t2(2, 3);

    t1 = t2;

    try {
        t1[0][0] = 8;
        std::cout << t1[0][0];
    } 
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
};
