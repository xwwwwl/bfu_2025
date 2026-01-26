#include <iostream>
#include <string>
#include <stdexcept>

double sss(double a, double b){
    if (b==0){
        throw std::invalid_argument("Negativeva lue");
    }
    return a/b;
}