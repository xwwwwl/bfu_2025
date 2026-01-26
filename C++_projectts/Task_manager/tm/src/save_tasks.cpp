#include <vector>
#include <string>
#include <iostream>
#include <fstream>

void save_tasks(std::vector<std::vector<std::string>> tasks){
    std::string path = "../../tm/tasks.json";
    std::ofstream tasks_output;

    tasks_output.open(path);

    if (!tasks_output.is_open()){
        std::cout<<"Error: failed to open file"<<std::endl;
    }
    else{
        for (int i = 0; i < tasks.size(); i++ ){
        tasks_output << tasks[i][0]<< "#"<< tasks[i][1] <<"#"<< tasks[i][2] << std::endl; // идем по масиву и записываем в файл данные
    }
    std::cout<<"Список задач успешно сохранен"<<std::endl;
    }
    tasks_output.close();
    
}