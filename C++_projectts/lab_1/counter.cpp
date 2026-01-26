#include <iostream>
#include "counter.hpp"
#include <cmath>
Counter::Counter() = default;
Counter::Counter(int startValue) {
    if (startValue<0){
        _value=0;
        std::cout<<"Значение не может быть меньше 0. Value=0"<<std::endl;
    }
    else{
        _value=startValue; 
    }
}
Counter::~Counter(){
        std::cout << "Счётчик удален, финальное значение: "<< _value << std::endl;
}
void Counter::increment(){
    _value++;
}   
void Counter::decrement(){
    _value--;
}
int Counter::get_value() const {return _value;}

double Counter::get_value_double() const {return static_cast<double>(_value);}

void Counter::reset_value(){
    _value=0;
}
void Counter::exponentiation(int x){
    _value=pow(_value,x);
}
void Counter::value_screen(){
    std::cout<<"В настоящий момент значение равно: "<<_value<<std::endl;
}
