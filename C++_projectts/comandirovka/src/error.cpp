#include <iostream>
#include <string>

int error_invalid_type_int(std::string number){
    try{
        float number_=stof(number);
        return 1;
    }
    catch(std::invalid_argument){
        std::cout<<"Error: invalid_argument"<<std::endl;
        return 0;
    }
    catch(std::out_of_range){
        std::cout<<"Error: out_of_range"<<std::endl;
        return 0;
    }
    
}