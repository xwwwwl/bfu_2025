#pragma once
#include <vector>
#include <string>

const std::string error_no_variant = "нет такого варианта ответа";
const std::string balance_card_screen = "Что вы хотите сделать? 1) пополнить баланс 2) снять наличные 3) конвертировать валюту 4) посмотреть баланс\n"
"Если котите выйти из карты напишите /end_card";
const std::string error_negative_value ="нельзя производить действия с балансом с отрицательным числом";
const std::string no_cash = "у вас недостаточно наличных для пополнения";
const std::string no_money="недостаточно средств на карте";
const std::string start_bank = "вы зашли в приложение банка\n"
            "напишите /create_card - если хотите создать карту\n"
            "напишите /card - если хотите войти в свою карту и делать различные оперции со счетом\n"
            "напишите /card_screen - если хотите посмотреть какие у вас есть номера карт\n"
            "напишите /change_pincode - если хотите поменять пинкод\n"
            "напишите /check_cash - если хотите посмотреть сколько у вас наличных";
const std::string error_pin_cod="вы ввели неправильный пинкод";
const std::string no_card = "у вас нет такой карты";
const std::string no_cards = "у вас нет карт";
const std::string error_input_number_of_card = "Вы неправильно ввели номер карты";
const std::string input_pincod ="введите пин-код";
const std::string input_number_of_card ="введите номер карты";
const std::string input_old_pincod = "введите старый пинкод";
void cards_screen(std::vector<std::vector<std::string>> &card_data);
void card_screen(std::vector<std::vector<std::string>> card_data, int number);