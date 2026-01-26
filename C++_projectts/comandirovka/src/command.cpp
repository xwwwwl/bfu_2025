#include <iostream>
#include <string>
#include "../inc/help_func.hpp"
#include "../inc/storage.hpp"


void print_all(Trip* head){
    PRINT_ALL(head);
}
void delete_trip(Trip* head){
    std::string line;
    std::cout<<"Командировку у человека с каким ФИО удалить?"<<std::endl;
    line=line_input();
    DELETE_TRIP(head,line);
}
void look_trip(Trip* head){
    std::string line;
    std::cout<<"Командировку у человека с каким ФИО вы хотите посмотреть?"<<std::endl;
    line=line_input();
    PRINT_FMNI(head,line);
}
void add_trip(Trip* head){
    std::string fmni = "0";
    std::string departure_date ="0";
    std::string return_date= "0";
    std::string destination;
    std::string purpose_of_the_trip;
    std::string daily_allowance = "-1";
    std::string line;
    
    while(fmni=="0"){
        std::cout<<"введите свою ФИО: ";
        fmni = input_fmni();
    }
    
    while(departure_date=="0"){
        std::cout<<"введите дату выезда"<<std::endl;
        departure_date=input_calendar_date();
    }
    while(return_date=="0"){
        std::cout<<"введите дату возвращения"<<std::endl;
        return_date=input_calendar_date();
    }
    std::cout<<"введите место назначения: ";
    destination= line_input();

    std::cout<<"введите цель поездки: ";
    purpose_of_the_trip= line_input();
    
    while (daily_allowance=="-1")
    {
        std::cout<<"сколько суточных вы хотите получать?: ";
        daily_allowance=input_daily_allowance();
    }
    ADD(head,fmni,departure_date,return_date,destination,purpose_of_the_trip,daily_allowance);
    std::cout<<"Данные успешно добавлены в список"<<std::endl;

    
    

}