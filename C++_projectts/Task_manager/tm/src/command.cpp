#include "../inc/help_func.hpp"
#include "../inc/save_tasks.hpp"
#include <algorithm>

void add_task(std::string task_name, std::string deadline, std::vector<std::vector<std::string>> &tasks, int list_limit) { // функция которая добавляет задачу
    if (tasks.size()< list_limit){
        std::vector<std::string> array;
        array.push_back(task_name);
        array.push_back("невыполнено");
        array.push_back(deadline);
        tasks.push_back(array);
        std::cout<<"задача: " + task_name+" с дедлайном: " <<deadline<<" успешно добавлена"<<std::endl;
        save_tasks(tasks);
    }
    else{
        std::cout<<"вы вышли за установленный вами лимит в "+ std::to_string(list_limit)+". Задача не будет добавлена"<<std::endl;
    }
    
}

void tasks_done(int number_of_task, std::vector<std::vector<std::string>> &tasks){ // функция меняет статус задачи на выполнено
    if (number_of_task-1<tasks.size())
    {
        tasks[number_of_task-1][1]="выполнено"; 
        std::cout<<"статус задачи: " +tasks[number_of_task-1][0]+" изменен на выполнено"<<std::endl;
        save_tasks(tasks);
    }
    else{
        std::cout<<"Error: There is no task with this number."<<std::endl;
    }  
    }

void sort_alph(std::vector<std::vector<std::string>>& tasks){ // сортировка по алфовиту
std::sort(tasks.begin(),tasks.end(), compare);
std::cout<<"Ваш список отсортирован"<<std::endl;
}

void sort_ready(std::vector<std::vector<std::string>>& tasks){ // сортировка по статусу
    std::sort(tasks.begin(),tasks.end(), sorted);
    std::cout<<"Ваш список отсортирован"<<std::endl;
}

void command_delete_task(std::vector<std::vector<std::string>>& tasks, int number_of_task){
    
       if (tasks.size()!=0){
        tasks.erase(tasks.begin() + number_of_task-1);
    std::cout<<"Задача успешно удалена."<<std::endl;
    save_tasks(tasks);
    }
    else{
        std::cout<<"Error: the tasks is empty"<<std::endl;
    }   
}