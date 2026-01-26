#pragma once
#include <vector>
#include <string>

void balance_card(std::vector<std::vector<std::string>> &card_data, int card_id, double* cash_nabk_ru, double* cash_nabk_dol);
void create_card(std::vector<std::vector<std::string>> &card_data, std::string number_card);
int change_pin_code(std::vector<std::vector<std::string>> &card_data, std::string old_pin_code, std::string number_of_card);