#pragma once
#include <string>
#include <iostream>
#include <vector>
int nearest_number_from_an_array_to_number(std::vector<int> array, int number);
std::vector<int> all_divisors(int number);
bool compare (std::vector<std::string>& a, std::vector<std::string>& b);
bool sorted (std::vector<std::string>& a, std::vector<std::string>& b);
int count_tasks(std::vector<std::vector<std::string>>& tasks);
int count_tasks_complete(std::vector<std::vector<std::string>>& tasks);
int count_tasks_non_complete(std::vector<std::vector<std::string>>& tasks);