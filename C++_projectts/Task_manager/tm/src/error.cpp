#include <string>
#include <iostream>
int Check_error_invalid_argument_int(std::string argument){
    try{
         int int_argument = stoi(argument);
         return 1;
    }
    catch(std::invalid_argument){
            
            return 0;
    }
    
}