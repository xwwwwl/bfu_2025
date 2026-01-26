#include <string>
#include <iostream>
int error_invalid_type(std::string line){
    try{
        long long linew = stoll(line);
        return 1;
    }
    catch(std::invalid_argument){
        std::cout<<"Error: invalid_argument"<<std::endl;
        return 0;
    }
    return 0;
}

int error_out_of_range_and_invalid_type(std::string line){
    try{
        double linew = stoi(line);
        return 1;
    }
    catch(std::out_of_range){
        std::cout<<"Error: out_of_range"<<std::endl;
        return 0;
    }
    catch(std::invalid_argument){
        std::cout<<"Error: invalid_argument"<<std::endl;
        return 0;
    }
    
}