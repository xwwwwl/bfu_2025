#include "counter.hpp"
int main(){
    Counter first_counter;
    Counter two_counter(99);
    two_counter.value_screen();
    two_counter.increment();
    


    // first_counter.increment();
    // first_counter.increment();

    return 0;
}