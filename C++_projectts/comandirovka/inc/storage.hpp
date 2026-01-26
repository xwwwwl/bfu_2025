#pragma once
#include <iostream>
#include <string>
#include "struct_trip.hpp"

void ADD(Trip* head, std::string fmni, std::string departure_date, std::string return_date, std::string destination, std::string purpose_of_the_trip,std::string daily_allowance);
void PRINT_ALL(Trip* head);
void DELETE_TRIP(Trip* head, std::string fmni);
void PRINT_FMNI(Trip* head, std::string fmni);
void sort_trip(Trip* head);