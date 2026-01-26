#include <iostream>
#include "command.hpp"
#include "error.hpp"
#include "help_func.hpp"
#include "ui.hpp"
int main(){
    
    std::vector<std::vector<std::string>> visa_card_data = {};
    std::vector<std::vector<std::string>> master_card_data = {};\
    bool bank_work = true;
    bool start = true;
    std::string line;
    double bank_rub= 50000.f;
    double bank_dol= 0.f;
    double* point_bank_rub = &bank_rub;
    double* point_bank_dol = &bank_dol;
    while(bank_work){
        if (start){
            std::cout<<start_bank<<std::endl;
            start=false;
            line=line_input();
        }
        else if(line=="/create_card"){
            std::cout<<"какую карту вы хотите создать? 1) Visa 2) Mastercard"<<std::endl;
            line=line_input();
            if (line=="1"){
                create_card(visa_card_data, "4");
                line=line_input();
            }
            else if (line=="2"){
                create_card(master_card_data, "5");
                line=line_input();
            }
            else{
                std::cout<<error_no_variant<<std::endl;
                line=line_input();
            }

        }
        else if (line=="/card"){
            if(visa_card_data.size()==0 && master_card_data.size()==0){
                std::cout<<no_cards<<std::endl;
                line=line_input();
            }
            else{
                std::cout<<input_number_of_card<<std::endl;
                line=line_input();
                if (error_invalid_type(line)){
                    if (Check_moon_algorithm(stoll(line))){
                        if (line[0]=='4'){
                            if (check_exist_card(line,visa_card_data)){
                                int card_id = search_id_card(line,visa_card_data);
                                std::string pin_cod = visa_card_data[card_id][2];
                                std::cout<<input_pincod<<std::endl;
                                line = line_input();
                                if (line==pin_cod){
                                    balance_card(visa_card_data,card_id,point_bank_rub,point_bank_dol);
                                    start=true;
                                }
                                else{
                                    std::cout<<error_pin_cod<<std::endl;
                                    line=line_input();
                                }
                            }
                            else{
                                std::cout<<no_card<<std::endl;
                                line=line_input();
                            }
                        }
                        else if(line[0]=='5'){
                            if (check_exist_card(line,master_card_data)){
                                int card_id = search_id_card(line,master_card_data);
                                std::string pin_cod = master_card_data[card_id][2];
                                std::cout<<input_pincod<<std::endl;
                                line=line_input();
                                if (line==pin_cod){
                                    balance_card(master_card_data,card_id,point_bank_rub,point_bank_dol);
                                     start=true;
                                }
                                else{
                                    std::cout<<error_pin_cod<<std::endl;
                                    line=line_input();
                                }
                            }
                            else{
                                std::cout<<no_card<<std::endl;
                                line=line_input();
                            }
                        }
                        else{
                            std::cout<<no_card<<std::endl;
                            line=line_input();
                        }
                    }
                    else{
                        std::cout<<error_input_number_of_card<<std::endl;
                        line=line_input();
                    }
                }
                else{
                    line=line_input();
                }
            }
        }
        else if(line=="/card_screen"){
            std::cout<<"Номера какой карты вы хотите посмотреть? 1) Visa 2) Mastercard"<<std::endl;
            line=line_input();
            if (line=="1"){
                cards_screen(visa_card_data);
                line=line_input();
            }
            else if (line=="2"){
                cards_screen(master_card_data);
                line=line_input();
            }
            else{
                std::cout<<error_no_variant<<std::endl;
                line=line_input();
            }
        }
        else if(line=="/change_pincode"){
            
            std::cout<<"пинкод какой карты вы хотите поменять? 1) Visa 2) Mastercard"<<std::endl;
            line=line_input();
            if (line=="1"){
                if (visa_card_data.size()==0){
                    std::cout<<no_card<<std::endl;
                    line=line_input();
                }
                else{
                    std::cout<<input_number_of_card<<std::endl;
                line=line_input();

                if (error_invalid_type(line)){
                    if (Check_moon_algorithm(stoll(line))){
                    std::string number_of_card = line;
                    std::cout<<input_old_pincod<<std::endl;
                    line=line_input();
                    change_pin_code(visa_card_data,line,number_of_card);
                    line=line_input();
                    }
                    else{
                    std::cout<<error_input_number_of_card<<std::endl;
                    line=line_input();
                    }
                }
                else{
                        line=line_input();
                }
                }
                
                
                
            }
            else if (line=="2"){
                if (master_card_data.size()==0){
                    std::cout<<no_cards<<std::endl;
                    line=line_input();
                }
                else{
                    std::cout<<input_number_of_card<<std::endl;

                line=line_input();
                if (error_invalid_type(line)){
                    if (Check_moon_algorithm(stoll(line))){
                    std::string number_of_card = line;
                    std::cout<<input_old_pincod<<std::endl;
                    line=line_input();
                    change_pin_code(master_card_data,line,number_of_card);
                    line=line_input();
                    }
                    else{
                    std::cout<<error_input_number_of_card<<std::endl;
                    line=line_input();
                    }
                }
            
                else{
                        
                        line=line_input();
                    }
                }
                
                
                
           
        }
        }
        else if(line=="/check_cash"){
            std::string bank_rub_string = std::to_string(bank_rub);
            std::string bank_dol_string = std::to_string(bank_dol);
            std::cout<<"У вас сейчас "<<bank_rub_string<<" рублей начиличных\n"<<
            "и "<<bank_dol_string<<" долларов начиличных"<<std::endl;
            line=line_input();
        }
        else if(line == "/end"){
            bank_work=false;
        }
        else{
            std::cout<<"вы ввели неправильную команду"<<std::endl;
            line=line_input();
        }
        
    }
    return 0;
}