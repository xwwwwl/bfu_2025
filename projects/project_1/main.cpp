﻿// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>


int main()
{   
    setlocale(LC_ALL, "RUSSIAN");
    int number;
    int number2;
    int number3;
    
    std::cout << "char c1 = 'A'; от "<<CHAR_MIN <<" до "<<CHAR_MAX <<" " << sizeof(char) << " байт\n"
        << "unsigned char c2 = 'A'; от 0 до "<<UCHAR_MAX << " " << sizeof(unsigned char) << " байт\n"
        << "short s1 = -30000; от "<<SHRT_MIN << " до "<< SHRT_MAX<< " "<< sizeof(short)<< " байта\n"
        << "unsigned short 60000; = 1 0 до "<<USHRT_MAX <<" "<< sizeof(unsigned short) <<" байта\n"
        << "int i1; = 1000000 от "<< INT_MIN<<" до "<<INT_MAX << sizeof (int)<< " байта\n"
        << "unsigned int i2 = 4000000; от 0 до " << UINT_MAX << " " << sizeof(unsigned int) << " байта\n"
        << "long long ll1 = 2000000; от "<<LLONG_MIN <<" до "<<LLONG_MAX <<" "<< sizeof(long long) <<" байтов\n"
        << "unsigned long long = 1; от 0 до "<<ULLONG_MAX <<" "<< sizeof(unsigned long long) << " байтов\n"
        << "float f = 3.141444f; примерно от "<<FLT_MIN <<" до "<<FLT_MAX <<" "<< sizeof(float) <<" байта\n"
        << "double f2 = 3.1343545444f; примерно от "<<DBL_MIN <<" до "<<DBL_MAX <<" "<< sizeof(double) <<" байтов\n"
        << "bool b = true; false = 0 true = любое кроме 0 true/false "<< sizeof(bool) <<" байт\n"<< std::endl;
    std::cout << "введите значение с клавиатуры: ";
        
    std::cin >> number;
    int del_0 = number / 4;
    int sum_0 = number + 4;
    int raz_0 = number - 4;
    int um_0 = number * 4;
    std::cout << "\n";
    std::cout << "ваше значение: " << number << std::endl;
    std::cout << "новые значения: " << sum_0 <<  " " << raz_0 << " "<< um_0 << " " << del_0 << std::endl;
    std::cout << "доп введите 2 числа: ";
    std::cin >> number2 >> number3;
    double number4 = number2;
    double number5 = number3;
    double del = number4 / number5;
    int del_int = number2 / number3;
    int sum = number2 + number3;
    int raz = number2 - number3;
    int um = number2 * number3;
    std::cout << "сложение - " << sum << "\n"
        << "вычитание - " << raz << "\n"
        << "умножение - " << um << "\n"
        << "деление int - " << del_int << " деление double - " << del << std::endl;

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.