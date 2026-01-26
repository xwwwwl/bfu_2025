#include <iostream>
#include <cmath>

bool isPowerOfTwoFloat(double n) {
    
    
    if (n > 0 && n < 1) {
        
        double reciprocal = 1.0 / n;

        return reciprocal > 0 && 
                std::floor(reciprocal) == reciprocal &&  // целое ли число
                (static_cast<int>(reciprocal) & (static_cast<int>(reciprocal) - 1)) == 0;
    }
    return false;
    
    
    // Для целых положительных чисел
    if (std::floor(n) == n) {  // если целое
        int intN = static_cast<int>(n);
        return (intN & (intN - 1)) == 0;
    }
    
    // Для дробных > 1
    return false;
}