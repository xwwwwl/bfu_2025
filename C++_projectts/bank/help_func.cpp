#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>   
#include <ctime>
#include "ui.hpp"

int search_last_digit_of_card(long long number_card){
    int sum_number;
    std::string number_card_str = std::to_string(number_card);
    int timer = 1;
    for (char ch : number_card_str) {
        int digit = ch - '0';
        if (timer%2==1){
          if (digit*2>9){
            sum_number+=(digit*2-9);
          }
          else{
            sum_number+=digit;
          } 
        }
        else{
             sum_number+=digit;
        }
        timer++;   
    }
    if (sum_number%10==0){
      return 0;
    }
    else{
      int last_digit = 10-sum_number%10;
    return last_digit;
    }
    
}
bool Check_moon_algorithm(long long number_card){
    int sum_number;
    std::string number_card_str = std::to_string(number_card);
    int timer = 1;
    for (char ch : number_card_str) {
        int digit = ch - '0';
        if (timer%2==1){
          if (digit*2>9){
            sum_number+=(digit*2-9);
          }
          else{
            sum_number+=digit;
          } 
        }
        else{
             sum_number+=digit;
        }
        timer++;   
    }
    if (sum_number%10==0){
        return 1;
    }
    else{
        return 0;
    }
}
std::string create_pseudorandom_number(int length){
    std::srand(static_cast<unsigned int>(std::time(nullptr))); 

    std::string random_number;

    
    for (int i = 0; i < length; ++i) {
        random_number += std::to_string(rand() % 10); 
    }

    return random_number;
}

std::string line_input(){
    std::string line;
    std::getline(std::cin, line);
    return line;
}
int check_pinc_cod(std::string pin_code){
  int chtchik =0;
  for (char digit: pin_code){
    if (digit >= '0' && digit <= '9') {
    chtchik += 1;
    }
    else{
      std::cout<<"Error: invalid_argument. the int type is expected"<<std::endl;
      return 0;
    }
  }

  if (chtchik==4){
    return 1;
    
  }
  else{
    std::cout<<"Error: The PIN code is not four digits long"<<std::endl;
    return 0;
  }
}
int check_exist_card(std::string card_number, std::vector<std::vector<std::string>> card_data){
  for (int i=0; i<card_data.size(); i++){
    if (card_data[i][0]==card_number){
      return 1;
    }
  }
  return 0;
}
std::string search_pincod(std::string card_number, std::vector<std::vector<std::string>> card_data){
   for (int i=0; i<card_data.size(); i++){
    if (card_data[i][0]==card_number){
      return card_data[i][2];
    }
}
return 0;
}
int search_id_card(std::string card_number, std::vector<std::vector<std::string>> card_data){
   for (int i=0; i<card_data.size(); i++){
    if (card_data[i][0]==card_number){
      return i;
    }
}
return 0;
}
std::string create_pin_code(){
    std::cout<<"придумайте 4-х значный пин-код для вашей карты"<<std::endl;
    std::string line=line_input();
    if (check_pinc_cod(line)!=0){
      return line;
    }
    return "0";
   
    
}
int what_currency(){
  std::cout<<"с какой валютой вы хотите работать? 1) ₽ 2) $"<<std::endl;
  std::string line = line_input();
  if (line == "1"){
    return 3;
  }
  else if (line == "2"){
    return 4;
  }
  else{
    std::cout<<error_no_variant<<std::endl;
    return 0;
  } 
}