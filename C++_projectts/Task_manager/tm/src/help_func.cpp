#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
int nearest_number_from_an_array_to_number(std::vector<int> array, int number){ //функция которая находит ближайщее число из масива чисел к числу которое мы указали
    int nearest_number;
    for (int i=0; i<array.size(); i++)
    {
        if (number<array[i]){ // если число из масива становится больше нашего числа то мы проверяем какая разница меньше с ним или с прошлым числом которое было меньше
            if (array[i]-number<number-array[i-1]){
                nearest_number=array[i];
                return  nearest_number;
            }
            else if (i-1>=0){
                 nearest_number=array[i-1];
                 return  nearest_number;
            }
        }
    }
    return array[0];
}
std::vector<int> all_divisors(int number) { // ищем все делители числа
    std::vector<int> divisors;  //масив где будем хранить делители
    for (int i = 1; i * i <= number; i++) { // ищем токо квадраты тоже самое что i < sqwr(number)
        if (number % i == 0) { 
            divisors.push_back(i);
            if (i != number / i) { //проверка чтоб не добовлять 2 одинаковых делителя
                divisors.push_back(number / i);
            }
        }
    }
    std::sort(divisors.begin(), divisors.end());  // сортирую по старшинству
    return divisors;
}
bool compare (std::vector<std::string>& a, std::vector<std::string>& b) { // вспомогательная функция сравнивает 1 и 2 элементы масива с индексом 0
    return a[0]<b[0];
}

bool sorted (std::vector<std::string>& a, std::vector<std::string>& b) { // вспомогательная функция сравнивает 1 и 2 элементы масива с индексом 1
    return a[1]<b[1];
}
int count_tasks(std::vector<std::vector<std::string>>& tasks){
    int count_tasks = 0;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i][0] != ""){
            count_tasks++;
        }
    }
    return count_tasks;
}
int count_tasks_complete(std::vector<std::vector<std::string>>& tasks){
    int count_tasks_complete = 0;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i][1] == "выполнено"){
            count_tasks_complete++;
        }
    }
    return count_tasks_complete;
}

int count_tasks_non_complete(std::vector<std::vector<std::string>>& tasks){
    int count_tasks_non_complete = 0;
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i][1] == "невыполнено"){
            count_tasks_non_complete++;
        }
    }
    return count_tasks_non_complete;
}

