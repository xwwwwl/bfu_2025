#pragma once
#include <string>
#include <vector>

void add_task(std::string task_name, std::string deadline, std::vector<std::vector<std::string>> &tasks, int list_limit);
void tasks_done(int number_of_task, std::vector<std::vector<std::string>> &tasks);
void command_delete_task(std::vector<std::vector<std::string>>& tasks, int number_of_task);
void sort_alph(std::vector<std::vector<std::string>>& tasks);
void sort_ready(std::vector<std::vector<std::string>>& tasks);