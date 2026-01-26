#pragma once
#include <vector>
#include <string>

std::vector<std::vector<std::string>> start_programm();
void command(std::string command,std::vector<std::vector<std::string>> &tasks,int &list_limit,bool &program_work);
std::string line_input();