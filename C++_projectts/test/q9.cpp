#include <vector>
#include <iostream>



int sss(int number){
    int count =0;
    while(number>0){
        count+=(number & 1);
        number= number>>1;
    }
    return count;
}