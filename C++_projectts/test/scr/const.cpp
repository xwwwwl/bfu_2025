#include <iostream>

// Прототип функции foo()
void foo(int *x);

int main() {
    int arr[20]= {1,2,3};
    int x = 10;
    int* px = &x;
    int& another_x = x;
    breakpoint;
    std::cout << x << std::endl;
    
    foo(px);
    
    std::cout << x << std::endl;

      // теперь компилятор знает о существовании функции foo()

   
    return 0;
}

// Определение функции foo()
void foo(int* px) {
    *px+=5;
}