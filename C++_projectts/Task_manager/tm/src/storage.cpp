#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void input_tasks(std::vector<std::vector<std::string>> &tasks){
    char delimiter = '#';
    bool file_is_empty=true; // флаг который обозначает пустой ли файл
    std::string path = "../../tm/tasks.json";   // путь к файлу

    std::ofstream create_file(path, std::ios::out | std::ios::app);
    create_file.close();
    
    std::ifstream tasks_input;
    tasks_input.open(path); 

    if (!tasks_input.is_open()){ 
        std::cout<<"Error: failed to open file"<<std::endl; // если файл не открывается, то ошибка
    }
    else{
        std::string str;

        while (!tasks_input.eof()) //работает пока не настанет конец файла
        {
            std::getline(tasks_input, str); 
            int pos = str.find("#");  // ищу индекс | с начала строки
            std::vector<std::string> tokens;
            std::string token;
            std::istringstream tokenStream(str);
            
            if (pos != -1) //смотрим есть ли в строке | если да то делим ее на 2 по этому символу и записываем каждую часть в масив, а потом этот масив в таски
            {
                
                while (std::getline(tokenStream, token, delimiter)) { // читает строку из tokenStream до # и сохраняет в token
                    tokens.push_back(token);
                }
                tasks.push_back(tokens);
                file_is_empty=false; // файл не пустой
                }
            
        
                
    

        }
        if (!file_is_empty){
            std::cout<<"Ваши прошлые задачи были успешно загружены."<<std::endl; 
        }
        tasks_input.close();
        }
    }