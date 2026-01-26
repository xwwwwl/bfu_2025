#include <iostream>
#include <string>

double sss(int number, int power){
    int power1 = abs(power);
    double result=1;
    
        for (int i=0; i<power1; i++){
        result*=number;
    }
    if (power>=0){
        return result;
    }
    else{
        return 1/result;
    }
    
}
