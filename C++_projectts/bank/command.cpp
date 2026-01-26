#include <vector>
#include <string>
#include <iostream>
#include "help_func.hpp"
#include "error.hpp"
#include "ui.hpp"

int change_pin_code(std::vector<std::vector<std::string>> &card_data, std::string old_pin_code, std::string number_of_card){
  std::string pin_code="0";
  
  for (int i=0; i<card_data.size(); i++){
  if (card_data[i][0]==number_of_card && card_data[i][2]==old_pin_code){
    
    while (pin_code=="0"){
    pin_code=create_pin_code();
  }
  card_data[i][2]=pin_code;
  std::cout<<"вы успешно поменяли пинкод на "+pin_code<<std::endl;
  return 1;
  }
  }
  std::cout<<"вы ввели неправильный номер карты или пинкод"<<std::endl;
  return 0;


  }
  


void create_card(std::vector<std::vector<std::string>> &card_data, std::string number_card){
    
    std::string pin_code="0";
    std::vector<std::string> card_information;
    std::string pseudorandom_number = create_pseudorandom_number(14);
    std::string last_digit = std::to_string(search_last_digit_of_card(stoll(number_card+pseudorandom_number)));
    
    std::string card_number = number_card+pseudorandom_number+last_digit;
    
    std::string card_cvv =create_pseudorandom_number(3);
    while (pin_code=="0"){
      pin_code=create_pin_code();
    }
    card_information.push_back(card_number);
    card_information.push_back(card_cvv);
    card_information.push_back(pin_code);
    card_information.push_back("0");
    card_information.push_back("0");
    card_data.push_back(card_information);
    card_screen(card_data, card_data.size()-1);
}
void balance_card(std::vector<std::vector<std::string>> &card_data, int card_id, double* cash_bank_ru, double* cash_bank_dol){

  std::cout<<"Ваш баланс: "<<card_data[card_id][3]<<"₽, "<<card_data[card_id][4]<<"$"<<std::endl;
  std::cout<<balance_card_screen<<std::endl;
  
  std::string line = line_input();
  bool end=false;
  while(end==false){
    if (line=="1"){
    int currency =what_currency();
    if (currency == 0){
      line=line_input();
    }
    else{
      std::cout<<"Насколько вы хотите пополнить баланс?"<<std::endl;
      line=line_input();
      if( error_out_of_range_and_invalid_type(line)){
        double sum = stod(line);
        if (currency==3){
          if (sum>=0 && *cash_bank_ru>=sum){
            *cash_bank_ru-=sum;
            double new_balance = stod(card_data[card_id][currency])+sum;
            card_data[card_id][3] = std::to_string(new_balance);
            std::string sum_line =std::to_string(sum);
          std::cout<<"вы успешно поплнили карту на "<<sum_line<<" рублей"<<std::endl;
          line = line_input();
        }
        else if (*cash_bank_ru<sum){
          std::cout<<no_cash<<std::endl;
          line = line_input();
        }
        else if(sum<0){
          std::cout<<error_negative_value<<std::endl;
          line = line_input();
        }
        }
        else if( currency==4){
          if (sum>=0 && *cash_bank_dol>=sum){
            *cash_bank_dol-=sum;
            double new_balance = stod(card_data[card_id][currency])+sum;
            card_data[card_id][3] = std::to_string(new_balance);
            std::string sum_line =std::to_string(sum);
          std::cout<<"вы успешно поплнили карту на "<<sum_line<<" долларов"<<std::endl;
          line = line_input();
        }
        else if (*cash_bank_dol<sum){
          std::cout<<no_cash<<std::endl;
          line = line_input();
        }
        else if(sum<0){
          std::cout<<error_negative_value<<std::endl;
          line = line_input();
        }
        }
        
      }
      else{
        line = line_input();
      }
    }
    
  }
  else if (line=="2"){
    int currency =what_currency();
    if (currency==0){
      line = line_input();
    }
    else{
      std::cout<<"Сколько вы хотите снять с баланса?"<<std::endl;
      line=line_input();
      if(error_out_of_range_and_invalid_type(line)){
        
        double sum = stod(line);
        if (sum<=stod(card_data[card_id][currency]) && sum>=0 && currency==3){
          *cash_bank_ru+=sum;
          double new_balance = stod(card_data[card_id][currency])-sum;
          card_data[card_id][3] = std::to_string(new_balance);
          std::string sum_line =std::to_string(sum);
          std::cout<<"вы сняли с карты "<<sum_line<<" рублей"<<std::endl;
          line = line_input();
        }
        else if (sum<=stod(card_data[card_id][currency]) && sum>=0 && currency==4){
          *cash_bank_dol+=sum;
          double new_balance = stod(card_data[card_id][currency])-sum;
          card_data[card_id][4] = std::to_string(new_balance);
          std::string sum_line =std::to_string(sum);
          std::cout<<"вы сняли с карты "<<sum_line<<" долларов"<<std::endl;
          line = line_input();
        }
        else if(sum<0){
          std::cout<<error_negative_value<<std::endl;
          
          line = line_input();
        }
        else{
          std::cout<<no_money<<std::endl;
        }
      }
      else{
        line = line_input();
      }
    }
    
  }
  else if (line=="3"){
    double rub=80;
    int currency =what_currency();
    if (currency==0){
      line = line_input();
    }
    else{
      std::cout<<"сколько валюты вы хотите поменять?"<<std::endl;
      line=line_input();
      if (error_out_of_range_and_invalid_type(line)){
        double sum = stod(line);
        if (sum<=stod(card_data[card_id][currency]) && sum>=0 && currency==3){
          double new_sum = sum/rub;
          card_data[card_id][currency]=std::to_string(stod(card_data[card_id][currency])-sum);
          card_data[card_id][4]=std::to_string(stod(card_data[card_id][4])+new_sum);
          std::string sum_line =std::to_string(sum);
          std::string new_sum_line =std::to_string(new_sum);
          std::cout<<"вы успешно перевели "<<sum_line<<" рублей в "<<new_sum_line<<" долларов"<<std::endl;
          line= line_input();
        }
        else if (sum<=stod(card_data[card_id][currency]) && sum>=0 && currency==4){
          double new_sum = sum*rub;
          card_data[card_id][currency]=std::to_string(stod(card_data[card_id][currency])-sum);
          card_data[card_id][3]=std::to_string(stod(card_data[card_id][3])+new_sum);
          std::string sum_line =std::to_string(sum);
          std::string new_sum_line =std::to_string(new_sum);
          std::cout<<"вы успешно перевели "<<sum_line<<" долларов в "<<new_sum_line<<" рублей"<<std::endl;
          line= line_input();
        }
        else if(sum<0){
          std::cout<<error_negative_value<<std::endl;
          line= line_input();
        }
        else if(sum>stod(card_data[card_id][currency])){
          std::cout<<no_money<<std::endl;
          line= line_input();
        }
      }
      else{
        line = line_input();
      }
    }
    
    
  }
  else if (line == "4"){
    std::cout<<"Ваш баланс: "<<card_data[card_id][3]<<" рублей и "<<card_data[card_id][4]<<" долларов"<<std::endl;
    line=line_input();
  }
  else if (line=="/end_card"){
    end=true;
  }
  else{
    std::cout<<balance_card_screen<<std::endl;
    line = line_input();
  }
  
  }


}