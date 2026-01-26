#include <string>
#include <iostream>
#include <vector>

void start_screen(){
    std::cout<<"Приветствую! Вы запустили приложение Task manager, чтобы ознакомиться со списком клманд введите '/help'"<<std::endl;
}
void error_no_command_screen(){
    std::cout<<"error: such command does not exist"<<
    std::endl<< "Чтобы ознакомиться со списком команд введите '/help'"<<std::endl;
}
void help_screen(){
    std::cout<<"/list - вывести список задач"<<std::endl
    <<"/add - добавить задачу"<<std::endl
    <<"/done - отметить выполненную задачу"<<std::endl
    <<"/start - переместиться в начальное окно"<<std::endl
    <<"/end - завершить программу"<<std::endl
    <<"/completion_rate - вывести процент выполненных задач"<<std::endl
    <<"/list_filter_completed_tasks - вывести только выполненные задачи"<<std::endl
    <<"/list_filter_uncompleted_tasks - вывести только невыполненные задачи"<<std::endl
    <<"/save_tasks - сохранить ваши задачи и их статус"<<std::endl
    <<"/sort_alph - сортирует список задач по алфавиту"<<std::endl
    <<"/sort_ready - сортирует список задач по статусу. Сначало выполненные потом невыполненные задачи"<<std::endl
    <<"/list_limit - устанавливает максимальное кличество задач, которое вы можете добавить"<<std::endl
    <<"/delete_task - удаляет выбранную команду"<<std::endl;
}
void error_invalid_argument_int_screen(){
    std::cout<<"error: command expects variable of type int"<<std::endl;
}
void command_add_task_name_screen(){
    std::cout<<"как вы хотите назвать вашу задачу?"<<std::endl;
}
void command_add_deadline_screen(){
    std::cout<<"Сколько часов вы будете ее выполнять?"<<std::endl;
}
void command_add_deadline_division_variant_screen(){
    std::cout<<"Как вы хоите поделить вашу функцию? 1) по 5 часов. 2) по 10 часов. 3) свой вариант"<<std::endl;
}
void command_add_deadline_division_screen(){
    std::cout<<"Напишите ваше количество часов по которым мы разделеим задачу"<<std::endl;
}
void command_add_deadline_division_offer_screen(std::string deadline){
    std::cout<<"Возможно вы хоите разделить deadline вот так: " + deadline +" 1) Да. 2) Нет."<<std::endl;
}
void command_done_number_of_done_screen(){
    std::cout<<"Номер какого задания вы хотите выполнить?"<<std::endl;
}
void command_list_limit_srceen(){
    std::cout<<"Какой лимит задач вы хотите поставить включительно?"<<std::endl;
}
void command_list_limit_sucses_srceen(std::string list_limit){
    std::cout<<"лимит задач установлен на "+ list_limit<<std::endl;
}
void command_delete_task_start_screen(){
    std::cout<<"Напишите номер задачи, которую вы хотите удалить"<<std::endl;
}
void command_delete_task_second_screen(std::vector<std::vector<std::string>>& tasks, int number_of_task){
    std::cout<<"вы уверены, что хотите удалить задачу: "+tasks[number_of_task-1][0]+". Напишите название задачи для ее удаления"<<std::endl;
}
void error_names_not_match( int number_of_task){
    std::cout<<"Задачи с номером: "<<number_of_task<<" и именем, которое вы написали не существует"<<std::endl;
}
void error_no_variant(){
    std::cout<<"Error: there is no such answer option."<<std::endl; 
}
void deadline_less_variant_screen(){
    std::cout<<"Error: the deadline is less than the part you want to divide into"<<std::endl;
}
void choice_task_list(){
    std::cout<<"Какие задачи вывести? 1) Все задачи  2) Выполненные 3) Невыполненные "<<std::endl;
}
void choice_all_sort(){
    std::cout<<"Как отсортировать? 1) По алфавиту 2) По статусу 3) Не сортировать"<<std::endl;
}
void choice_sort(){
    std::cout<<"Сортировать список? 1) Да 2) Нет"<<std::endl;
}
void error_zero_tasks(){
    std::cout<<"Список задач пуст"<<std::endl;
}
void tasks_screen(std::vector<std::vector<std::string>> tasks){ // выводит все задачи по порядку
    std::cout << "Ваши задачи: " << std::endl;
    if (tasks.size()==0){
        std::cout<<"У вас нет задач"<<std::endl;
    }
    else{
        for (int i = 0; i < tasks.size(); i++ ){
        std::cout << "задание " + std::to_string(i + 1) + ": " + tasks[i][0]<< " | "<<"статус: " + tasks[i][1] <<" | "<< "время на выполнение: "<<  tasks[i][2] << std::endl;
        
    }
    }
    
}
void list_filter_completed_tasks(std::vector<std::vector<std::string>> tasks) // выводит только выполненные задачи
    {
    if (tasks.size()==0)
    {
        std::cout<<"Error: no tasks found"<<std::endl;
    }
    else{
        for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i][1] == "выполнено")
        {
            std::cout << "задание " + std::to_string(i + 1) + ": " + tasks[i][0]<< " | "<<"статус: " + tasks[i][1] <<" | "<< "время на выполнение: "<<  tasks[i][2] << std::endl;
        }
    }
    }
    
}
void list_filter_uncompleted_tasks(std::vector<std::vector<std::string>> tasks)  // выводит только невыполненные задачи
{
    if (tasks.size()==0)
    {
        std::cout<<"Error: no tasks found"<<std::endl;
    }
    else{
       for (int i = 0; i < tasks.size(); i++)
    {
        if (tasks[i][1] == "невыполнено")
        {
            std::cout << "задание " + std::to_string(i + 1) + ": " + tasks[i][0]<< " | "<<"статус: " + tasks[i][1] <<" | "<< "время на выполнение: "<<  tasks[i][2] << std::endl;
        }
    } 
    }
    
}
void completion_rate(std::vector<std::vector<std::string>> tasks){ // выводит процент правильных задач
    std::cout<< "Процент выполненных задач: ";
    float task_done = 0; 
    float task_not_done = 0; 
    for (int i = 0; i < tasks.size(); i++){
        if ((tasks[i])[1] == "выполнено")
        
        {
            task_done += 1;
        }
        else{
            task_not_done += 1;
        }
    }
    int sum_tasks_done_and_not_done = task_done + task_not_done;
    if (sum_tasks_done_and_not_done != 0){
        float complited = (task_done * 100.00) / sum_tasks_done_and_not_done;
        std::cout<< complited<<std::endl;
    }
    else{
        std::cout<<"Error: no tasks found"<<std::endl;
    }
}

