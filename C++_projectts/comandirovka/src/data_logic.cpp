#include "../inc/ui.hpp"
#include "../inc/command.hpp"
#include "../inc/help_func.hpp"
#include <iostream>

void data_logic(){
    Trip head;

    head.next = nullptr;

    bool end = false;
    bool start = true;
    std::string line;
    while (!end)
    {
        if (start){
            std::cout<<menu<<std::endl;
            start = false;
            line = line_input();
        }
        else if(line=="0"){
            end=true;
        }
        else if(line=="1"){
            add_trip(&head);
            start = true;

        }
        else if(line=="2"){
            print_all(&head);
            start = true;
        }
        else if(line=="3"){
            look_trip(&head);
            start = true;
        }
        else if(line=="4"){
            delete_trip(&head);
            start = true;
        }
        else{
            std::cout<<error_no_command<<std::endl;
            start = true;
            
        }
    }
    
}