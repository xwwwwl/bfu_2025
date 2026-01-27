#include "MyString.hpp"
#include <iostream>

int main(){
    ds::MyString s1("Hello");
    ds::MyString s2(" World");
    ds::MyString s3;
    ds::MyString s4(s1);
    std::cout<<s4<<std::endl;
    std::cout<<s3<<std::endl;
    s3=s1+s2;
    std::cout<<s3<<std::endl;
    std::cout << s1 + s2; 

    return 0;
}