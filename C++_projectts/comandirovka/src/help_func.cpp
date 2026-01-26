#include <iostream>
#include "../inc/error.hpp"

std::string line_input(){
    std::string line;
    std::getline(std::cin,line);
    return line;
}
std::string toLowerUTF8(const std::string& str) {
    std::string out;
    size_t i = 0;

    while (i < str.size()) {
        unsigned char c = str[i];

        // кириллица (2 байта)
        if ((c == 0xD0 || c == 0xD1) && i + 1 < str.size()) {
            unsigned char c2 = str[i + 1];

            // А–П (0xD20 0x90–0xAF) → а–п (0xD0 0xB0–0xBF)
            if (c == 0xD0 && c2 >= 0x90 && c2 <= 0xAF) {
                out.push_back(0xD0);
                out.push_back(c2 + 0x20);
            }
            // Р–Я (0xD1 0x80–0x8F) → р–я (0xD1 0x90–0x9F)
            else if (c == 0xD1 && c2 >= 0x80 && c2 <= 0x8F) {
                out.push_back(0xD1);
                out.push_back(c2 + 0x10);
            }
            // Ё (0xD0 0x81) → ё (0xD1 0x91)
            else if (c == 0xD0 && c2 == 0x81) {
                out.push_back(0xD1);
                out.push_back(0x91);
            }
            else {
                // оставить как есть
                out.push_back(c);
                out.push_back(c2);
            }

            i += 2;
        }
        else {
            // ASCII
            out.push_back(std::tolower(c));
            i++;
        }
    }

    return out;
}
int counter_symbol(const std::string& str) {
    size_t i = 0;
    int counter =0;
    while (i < str.size()) {
        unsigned char c = str[i];

        // кириллица (2 байта)
        if ((c == 0xD0 || c == 0xD1) && i + 1 < str.size()) {

            i += 2;
            counter++;
        }
        else {
            // ASCII
            
            i++;
            counter++;
        }
    }

    return counter;
}
std::string input_fmni(){
    std::string line;
    line=line_input();
    int count = counter_symbol(line);
    if (count>=5 & count<=60){
        return line;
    }
    else{
        std::cout<<"длина ФИО должна быть в диапозпне от 5 до 60"<<std::endl;
        return "0";
    }
}
std::string input_daily_allowance(){
    std::string line;
    line=line_input();
    if (error_invalid_type_int(line)){
        float number = stof(line);
        if (number>=0 & number<=100000){
            return line;
        }
        else{
            std::cout<<"число должо быть в диапозпне от 0.0 до 100000.0"<<std::endl;
            return "-1";
        }
    }
    else{
        return "-1";
    }
}
std::string input_calendar_date(){
    std::string day;
    std::string month;
    std::string year;
    std::string line;
    std::cout<<"введите день: ";
    line=line_input();
    if (error_invalid_type_int(line)){
        int number = stoi(line);
        if (number>=1 & number<=31){
            day = std::to_string(number);
            std::cout<<"введите месяц: ";
            line=line_input();
            if (error_invalid_type_int(line)){
                int number = stoi(line);
                if (number>=1 & number<=12){
                    month = std::to_string(number);
                    std::cout<<"введите год: ";
                    line=line_input();
                    if (error_invalid_type_int(line)){
                        int number = stoi(line);
                        if (number>=2020 & number<=2030){
                            year = std::to_string(number);
                            std::string data = day+"."+month+"."+year;
                            return data;
                        }
                        else{
                            std::cout<<"число должо быть в диапозпне от 2020 до 2030"<<std::endl;
                            return "0";
                        }
                    }
                    else{
                        return "0";
            }
                    }
                
                else{
                     std::cout<<"число должо быть в диапозпне от 1 до 12"<<std::endl;
                     return "0";
                }
            }
            else{
                return "0";
            }
        }
        else{
            std::cout<<"число должо быть в диапозпне от 1 до 31"<<std::endl;
            return "0";
        }
    }
    else{
        return "0";
    }


    return "0";
}
