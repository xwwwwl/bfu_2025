#include <vector>
#include <string>
#include <iostream>

void cards_screen(std::vector<std::vector<std::string>> &card_data){
  if (card_data.size()!=0){
    for (int i=0;i<card_data.size();i++){
      std::cout<<card_data[i][0]<<std::endl;
    }
  }
  else{
    std::cout<<"у вас нет карт"<<std::endl;
  }
}
void card_screen(std::vector<std::vector<std::string>> card_data, int number){
  
  std::cout<<"Данные ваших карт"<<std::endl;
  std::cout<<"1) номер карты 2) cvv код 3) пин-код"<<std::endl;
  std::cout<<card_data[number][0]<<" "<<card_data[number][1]<<" "<<card_data[number][2]<<std::endl;
  
}