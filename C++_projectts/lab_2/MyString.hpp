#include <cstring> 
#include <iostream>
namespace ds {
class MyString{
public:
    MyString(const char* str);
    MyString();
    MyString(const MyString &other);
    ~MyString();
    void print();
    MyString& operator=(const MyString& other);
    friend MyString operator+(const MyString& str1, const MyString& str2);
    friend std::ostream& operator<<(std::ostream& os, const MyString& str);
private: 
    size_t size_;
    char* str_;
    
};
}
    