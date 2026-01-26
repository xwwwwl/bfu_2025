#pragma once
#include <string>
class Counter{
    public:
        Counter();
        Counter(int startValue);
        ~Counter();
        void increment();
        void decrement();
        int get_value() const;
        double get_value_double() const;
        void reset_value();
        void exponentiation(int x);
        void value_screen();
    private:
       int _value=0;
};