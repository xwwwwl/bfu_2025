#include "MyString.hpp"

namespace ds{
MyString::MyString(const char* str) : size_(strlen(str)), str_(new char[size_]){  
    strcpy(str_, str);  
}
MyString::MyString() : size_(0), str_(nullptr){}
MyString::MyString(const MyString& other) : MyString(other.str_) {}
MyString::~MyString(){
  delete[] str_;
}
MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
      MyString tmp(other);
      std::swap(size_, tmp.size_);
      std::swap(str_, tmp.str_);
    }
    return *this;
}
MyString operator+( const MyString& str1, const MyString& str2){
  MyString result;
  result.size_=str1.size_+str2.size_;
  result.str_=new char[result.size_];
  for (int i1=0; i1<str1.size_; i1++)
    result.str_[i1]=str1.str_[i1];
  for (int i2=0; i2<str2.size_; i2++)
    result.str_[i2+str1.size_]=str2.str_[i2];
  
  return result;
}
std::ostream& operator<<(std::ostream& os, const MyString& str) {
    if (str.str_==nullptr){
      os << "";
    }
    else{
      os << str.str_;
    }
    
    return os;
}
void MyString::print(){
    for (size_t i = 0; i < size_; ++i) {
      std::cout << str_[i];
    }
    std::cout << std::endl;
}

}

    