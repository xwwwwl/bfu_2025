#include <iostream>
#include <string>

std::string sss(std::string str){
    std::string str2;
    for (char s: str){
        if(s != ' '){
            str2+=s;
        }
    }
    return str2;
}