#include"../inc/storage.hpp"
#include "../inc/ui.hpp"
#include "../inc/command.hpp"
#include "../inc/error.hpp"
#include "../inc/help_func.hpp"
#include <iostream>

std::string line_input(){ // записываем строку в переменную типа string
    std::string line;
    std::getline(std::cin, line);
    return line;
}
std::vector<std::vector<std::string>> start_programm(){ // при старте программы записываем из файла tasks.json все в масив
    std::vector<std::vector<std::string>> tasks = {};
    input_tasks(tasks);
    std::cout<<start_screen<<std::endl;
    return tasks;
}
void command(std::string command,std::vector<std::vector<std::string>> &tasks,int &list_limit,bool &program_work){ // все команды 
    
    if (command=="/start"){
        std::cout<<start_screen<<std::endl;
    }
    else if (command == "/help"){
        std::cout<<help_screen<<std::endl;
    }
    else if (command == "/add"){
        std::cout<<command_add_task_name_screen<<std::endl;
        std::string task_name=line_input(); // сначало узнаем имя задачи
        std::cout<<command_add_deadline_screen<<std::endl;
        std::string deadline_string = line_input(); // сколько часов ее выполнять будут
        if (Check_error_invalid_argument_int(deadline_string)){ // проверка на то может ли deadline_string перейти в int
            int deadline_int = stoi(deadline_string);
            std::cout<<command_add_deadline_division_variant_screen<<std::endl;
            std::string variant = line_input();
            if (variant == "1"){ //если 1 то делим по 5
                if (deadline_int<5){
                    std::cout<<deadline_less_variant_screen<<std::endl;
                }
                else{
                    for (int i=0; i<deadline_int/5;i++){
                    deadline_string+=" 5";
                }
                if (deadline_int%5!=0)
                {
                        deadline_string+=" "+std::to_string(deadline_int%5);
                }
                add_task(task_name,deadline_string, tasks, list_limit); 
                }
            }
            else if (variant == "2"){ //если 2 то делим по 10
                if (deadline_int<10){
                    std::cout<<deadline_less_variant_screen<<std::endl;
                }
                else{
                    for (int i=0; i<deadline_int/10;i++){
                    deadline_string+=" 10";
                }
                if (deadline_int%10!=0)
                {
                        deadline_string+=" "+std::to_string(deadline_int%10);
                }
                add_task(task_name,deadline_string, tasks, list_limit); 
                }
            }
            else if (variant == "3"){ //если 3 то делим по варианту который напишем
                std::cout<<command_add_deadline_division_screen<<std::endl;
                std::string deadline_devision_string = line_input();
                if (Check_error_invalid_argument_int(deadline_devision_string)){
                    int deadline_division_int=stoi(deadline_devision_string);
                    if (deadline_division_int<deadline_int){
                        int the_proposed_division_option = nearest_number_from_an_array_to_number(all_divisors(deadline_int),deadline_division_int); // сравниваем число которое написал пользователь с числами из масива со всеми делителями из дедлайна и находим ближайшее
                            for (int i=0; i<deadline_int/the_proposed_division_option;i++){ // делаем строку с дедлайном которую мы хотим предложить пользователя
                            deadline_string+=(" "+std::to_string(the_proposed_division_option)); 
                            }
                            command_add_deadline_division_offer_screen(deadline_string);
                            
                            std::string variant = line_input();
                            if (variant=="1"){ // программа формирует свой вариант и справшивает у пользователя хочет ли он его выбрать если да то его записываем
                                add_task(task_name,deadline_string, tasks, list_limit);
                            }
                            else if (variant=="2"){
                                deadline_string=std::to_string(deadline_int);
                                for (int i=0; i<deadline_int/deadline_division_int;i++){
                                    deadline_string+=" "+std::to_string(deadline_division_int);
                                }
                                if (deadline_int%deadline_division_int!=0)
                                {
                                    deadline_string+=" "+std::to_string(deadline_int%deadline_division_int); 
                                }
                                    
                                add_task(task_name,deadline_string, tasks, list_limit); 
                            }
                            else{
                                std::cout<<error_no_variant<<std::endl;
                            }
                    }
                    else{
                        std::cout<<deadline_less_variant_screen<<std::endl;
                    }
                }
                else{
                    std::cout<<error_invalid_argument_int_screen<<std::endl;
                }

            }
            else{
                std::cout<<error_no_variant<<std::endl;
            }
            
        }
        else{
            std::cout<<error_invalid_argument_int_screen<<std::endl;
        }

    }
    else if (command=="/done"){
        std::cout<<command_done_number_of_done_screen<<std::endl;
        std::string number_of_done = line_input();
        if (Check_error_invalid_argument_int(number_of_done)==1){
            int number_of_done_int = stoi(number_of_done);
            tasks_done(number_of_done_int,tasks);
        }
        else{
            std::cout<<error_invalid_argument_int_screen<<std::endl;
        }
    }
    else if (command=="/list_limit"){
        std::cout<<command_list_limit_srceen<<std::endl;
        std::string limit_task = line_input();
        if (Check_error_invalid_argument_int(limit_task)==1){
            int list_limit = stoi(limit_task);
            command_list_limit_sucses_srceen(limit_task);
        }
        else{
            std::cout<<error_invalid_argument_int_screen<<std::endl;
        }
    }
    else if (command == "/end"){
        program_work = false;
    }
    else if (command == "/delete_task"){
        std::cout<<command_delete_task_start_screen<<std::endl;
        std::string number_of_task_string = line_input();
        if (Check_error_invalid_argument_int(number_of_task_string)){
            int number_of_task=stoi(number_of_task_string);
            if (number_of_task>0 && number_of_task<=tasks.size()){
                command_delete_task_second_screen(tasks, number_of_task);
                std::string task_name = line_input();
                if (task_name==tasks[number_of_task-1][0]){
                    command_delete_task(tasks, number_of_task);
                }
                else{
                    error_names_not_match(number_of_task);
                }
            }
            else{
                std::cout<<"Error: There is no task with this number."<<std::endl;
            }
            
        }
        else{
            std::cout<<error_invalid_argument_int_screen<<std::endl;
        }
    }
    else if (command == "/list"){
        std::cout<<choice_task_list<<std::endl; //спрашиваем какой список вывести
        std::string task_name=line_input();
        if (task_name == "1" || task_name == "1)"){  //все задачи
            if (count_tasks(tasks) > 0){ //смотрим есть ли задачи
                tasks_screen(tasks);
                std::cout<<choice_all_sort<<std::endl; //спрашиваем как отсортировать
                std::string task_name=line_input();
                if (task_name == "1" || task_name == "1)"){ //по алфОвиту
                    sort_alph(tasks);
                    tasks_screen(tasks);
                }
                else if (task_name == "2" || task_name == "2)"){ //по статусу
                    sort_ready(tasks); 
                    tasks_screen(tasks);
                }
                else if (task_name == "3" || task_name == "3)"){ //не сортируем
                    
                }
                else { //ошибка если вводится что-то другое
                    std::cout<<error_no_variant<<std::endl;
                }
            }
            else { // ошибка список задач пуст
                std::cout<<error_zero_tasks<<std::endl;
            }
        }
        else if (task_name == "2" || task_name == "2)") { //выводим выполненные задачи
            if (count_tasks_complete(tasks) > 0) {
                list_filter_completed_tasks(tasks);
                std::cout<<choice_sort<<std::endl; // спрашиваем сортировать или нет
                std::string task_name=line_input();
                if (task_name == "1" || task_name == "1)"){ //по алфОвиту
                    sort_alph(tasks);
                    list_filter_completed_tasks(tasks);
                }
                else if (task_name == "2" || task_name == "2)"){ //не сортируем
                    
                }
                else { //ошибка если вводится что-то другое
                    std::cout<<error_no_variant<<std::endl; 
                }
            }
            else { // ошибка список задач пуст
                std::cout<<error_zero_tasks<<std::endl; 
            }
        }
        else if (task_name == "3" || task_name == "3)") { //выводим невыполненные задачи
            if (count_tasks_non_complete(tasks) > 0) {
                list_filter_uncompleted_tasks(tasks);
                 std::cout<<choice_sort<<std::endl;  // спрашиваем сортировать или нет
                std::string task_name=line_input();
                if (task_name == "1" || task_name == "1)"){ //по алфОвиту
                    sort_alph(tasks);
                    list_filter_uncompleted_tasks(tasks);
                }
                else if (task_name == "2" || task_name == "2)"){ //не сортируем
                    
                }
                else { //ошибка если вводится что-то другое
                     std::cout<<error_no_variant<<std::endl; 
                }
            }
            else { // ошибка список задач пуст
                std::cout<<error_zero_tasks<<std::endl; 
            }
        }
        else { //ошибка если вводится что-то другое
                    std::cout<<error_no_variant<<std::endl; 
                }
    }
    else{
        std::cout<<error_no_command_screen<<std::endl; 
    }

}