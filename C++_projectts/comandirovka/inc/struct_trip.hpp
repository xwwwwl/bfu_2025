#include <string>
struct Trip {
    std::string fmni;
    std::string departure_date;
    std::string return_date;
    std::string destination;
    std::string purpose_of_the_trip;
    std::string daily_allowance;
    Trip* next;
};