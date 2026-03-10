#include <string>
#include <iostream>
class Penis{
    std::string text_;
    public:
        Penis(const char* text) {
            text_=text;
        }
        friend std::ostream& operator<<(std::ostream& out, const Penis& str){
            out<<str.text_;
            return out;
        }
};

int main(){
    Penis str("vsem ky");
    std::cout<<str<<std::endl;
    return 0;
}