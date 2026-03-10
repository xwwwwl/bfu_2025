#include <iostream>
#include <cstring>
// #include "q12.cpp"


void xorSwap(int &a, int &b) {
    if (&a != &b) {  // Важная проверка!//a=5 b=10 0101 1010
        a =a^b; // a = 1111 b = 1010
        b ^= a; // a=1111 b = 0101
        a ^= b; // a=1010 b = 0101
    }
}
int main() {
   int a = 4^8;
  std::cout<<a<<std::endl;
  return 0;
}

