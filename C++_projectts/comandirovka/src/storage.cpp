#include <iostream>
#include <string>
#include "../inc/help_func.hpp"
#include "../inc/struct_trip.hpp"


Trip* MAKE(std::string fmni, std::string departure_date, std::string return_date, std::string destination, std::string purpose_of_the_trip,std::string daily_allowance) {
    Trip* inf_about_trip = new Trip;
    inf_about_trip->fmni = fmni; 
    inf_about_trip->departure_date = departure_date;
    inf_about_trip->return_date = return_date;
    inf_about_trip->destination = destination;
    inf_about_trip->purpose_of_the_trip = purpose_of_the_trip;
    inf_about_trip->daily_allowance = daily_allowance;
    return inf_about_trip;
}
void sort_trip(Trip* head){
    if (head->next != nullptr & head->next->next !=  nullptr){
       Trip* trip1 = head->next;
       while(trip1->next!=nullptr) {
        if(toLowerUTF8(trip1->fmni)>toLowerUTF8(trip1->next->fmni)){  
            head->next=trip1->next;
            trip1->next=head->next->next;
            head->next->next=trip1;
        }
        else{
            trip1= trip1->next;
        }
        head=head->next;
       }
    }
    
}
void ADD(Trip* head, std::string fmni, std::string departure_date, std::string return_date, std::string destination, std::string purpose_of_the_trip,std::string daily_allowance) {
    Trip* inf_about_trip = MAKE(fmni, departure_date, return_date, destination, purpose_of_the_trip,daily_allowance);
    inf_about_trip->next = head->next;
    head->next = inf_about_trip;
    sort_trip(head);
}

void PRINT_ALL(Trip* head) {
    int counter =0;
    Trip* p = head->next;
    if (p==nullptr){
        std::cout<<"у вас нет командировок"<<std::endl;
    }
    else{
        while(p!=nullptr) {
        counter++;
        std::cout <<"id: "<<counter<<"\n"
        <<"ФИО: "<< p->fmni << "\n"
        <<"Дата выезда: "<<p->departure_date << "\n"
        <<"Дата возвращения: "<<p->return_date << "\n"
        <<"Место назначения: "<<p->destination<< "\n"
        <<"Цель поездки: "<<p->purpose_of_the_trip << "\n"
        <<"Суточные: "<<p->daily_allowance << "\n"<<std::endl;
        
        p = p->next;
        
    }
    std::cout<<"всего записей: "<<counter<<std::endl;
    }
    
}

void PRINT_FMNI(Trip* head, std::string fmni) {
    bool done = false;
    int counter =0;
    Trip* p = head->next;
    if (p==nullptr){
        std::cout<<"у вас нет командировок"<<std::endl;
    }
    else{
        while(p!=nullptr) {
        counter++;    
        if (p->fmni==fmni){
            std::cout <<"ФИО: "<< p->fmni << "\n"
        <<"Дата выезда: "<<p->departure_date << "\n"
        <<"Дата возвращения: "<<p->return_date << "\n"
        <<"Место назначения: "<<p->destination<< "\n"
        <<"Цель поездки: "<<p->purpose_of_the_trip << "\n"
        <<"Суточные: "<<p->daily_allowance << "\n"<<std::endl;
        done = true;
        
        std::cout<<"операций сравнения: "<<counter<<std::endl;
        }
        
        p = p->next;
    }
    if (done==false){
        std::cout<<"нет командировки у человека с таким ФИО"<<std::endl;
    }
    
        
    }
    
}

void DELETE_TRIP(Trip* head, std::string fmni) {
    int counter=0;
    bool done = false;
    Trip* p = head;
    if (p->next == nullptr){
        std::cout<<"у вас нет командировок"<<std::endl;
    }
    while(p->next != nullptr & done==false) {
        counter++;
        if (p->next->fmni == fmni) {
            Trip* tmp = p->next;
            p->next = p->next->next;
            delete tmp;
            std::cout<<"командировка у человека с id: "<<counter<<" удалена"<<std::endl;
            done = true;
        }
        else {
            p = p->next;
        }
    }
    if (done == false){
        std::cout<<"нет человека с таким ФИО"<<std::endl;
    }
}

void CLEAR(Trip* head) {
    Trip* p = head;
    while(p->next != nullptr) {
        Trip* tmp = p->next;
        p->next = p->next->next;
        delete tmp;
    }
}