#include "inc/task_logic.hpp"

int main(){
   std::vector<std::vector<std::string>> tasks=start_programm();
   int list_limit = INT_MAX;
   bool program_work=true;
   while(program_work == true){
        std::string line = line_input();
        command(line,tasks,list_limit,program_work);
   }
}