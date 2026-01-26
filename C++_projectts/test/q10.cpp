#include <iostream>
#include <vector>
#include <cmath>

bool sss(int number){
    int counter=0;
    for (int i=2;i<sqrt(number);i++){
        if (number%i==0){
            std::cout<<number/i<<" "<<i<<std::endl;
            return false;
        }
    }
    return true;
}
