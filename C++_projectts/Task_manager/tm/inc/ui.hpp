#pragma once
#include <string>
#include <vector>
std::string start_screen= "Приветствую! Вы запустили приложение Task manager, чтобы ознакомиться со списком клманд введите '/help'";
std::string error_no_command_screen="error: such command does not exist\n"
     "Чтобы ознакомиться со списком команд введите '/help'";
std::string help_screen= "/list - вывести список задач\n"
    "/add - добавить задачу\n"
    "/done - отметить выполненную задачу\n"
    "/start - переместиться в начальное окно\n"
    "/end - завершить программу\n"
    "/completion_rate - вывести процент выполненных задач\n"
    "/list_filter_completed_tasks - вывести только выполненные задачи\n"
    "/list_filter_uncompleted_tasks - вывести только невыполненные задачи\n"
    "/save_tasks - сохранить ваши задачи и их статус\n"
    "/sort_alph - сортирует список задач по алфавиту\n"
    "/sort_ready - сортирует список задач по статусу. Сначало выполненные потом невыполненные задачи\n"
    "/list_limit - устанавливает максимальное кличество задач, которое вы можете добавить\n"
    "/delete_task - удаляет выбранную команду";
std::string error_invalid_argument_int_screen="error: command expects variable of type int";
std::string command_add_task_name_screen="как вы хотите назвать вашу задачу?";
std::string command_add_deadline_screen="Сколько часов вы будете ее выполнять?";
std::string command_add_deadline_division_variant_screen="Как вы хоите поделить вашу функцию? 1) по 5 часов. 2) по 10 часов. 3) свой вариант";
std::string command_add_deadline_division_screen="Напишите ваше количество часов по которым мы разделеим задачу";
void command_add_deadline_division_offer_screen(std::string deadline);
std::string command_list_limit_srceen="Какой лимит задач вы хотите поставить включительно?";
std::string error_no_variant="Error: there is no such answer option."; 
std::string deadline_less_variant_screen="Error: the deadline is less than the part you want to divide into";
std::string command_done_number_of_done_screen="Номер какого задания вы хотите выполнить?";
void tasks_screen(std::vector<std::vector<std::string>> tasks);
void command_list_limit_sucses_srceen(std::string list_limit);
std::string choice_task_list="Какие задачи вывести? 1) Все задачи  2) Выполненные 3) Невыполненные ";
std::string choice_all_sort="Как отсортировать? 1) По алфавиту 2) По статусу 3) Не сортировать";
std::string choice_sort="Сортировать список? 1) Да 2) Нет";
std::string error_zero_tasks="Список задач пуст";
void list_filter_completed_tasks(std::vector<std::vector<std::string>> tasks);
void list_filter_uncompleted_tasks(std::vector<std::vector<std::string>> tasks);
std::string command_delete_task_start_screen="Напишите номер задачи, которую вы хотите удалить";
void command_delete_task_second_screen(std::vector<std::vector<std::string>>& tasks, int number_of_task);
void error_names_not_match( int number_of_task);
