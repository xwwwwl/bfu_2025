#pragma once
#include <vector>
#include <string>

int search_last_digit_of_card(long long number_card);
bool Check_moon_algorithm(long long number_card);
std::string create_pseudorandom_number(int number_length);
std::string line_input();
int check_pinc_cod(std::string pin_code);
int check_exist_card(std::string card_number, std::vector<std::vector<std::string>> card_data);
std::string search_pincod(std::string card_number, std::vector<std::vector<std::string>> card_data);
int search_id_card(std::string card_number, std::vector<std::vector<std::string>> card_data);
std::string create_pin_code();
int what_currency();