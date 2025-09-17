// main.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale>

using namespace std;
int main()
{   
    setlocale(LC_ALL, "RUSSIAN");
    int number;
    double number2;
    double number3;
    
    cout << "char c1 = 'A'; от -128 до 127 " <<  sizeof(char) << " байт\n"
        << "unsigned char c2 = 'A'; до 0 до 255 " << sizeof(unsigned char) << " байт\n"
        << "short s1 = -30000; от - 32768 до 37767 "<< sizeof(short)<< " байта\n"
        << "unsigned short 60000; = 1 0 до 65535 "<< sizeof(unsigned short) <<" байта; \n"
        << "int i1; = 1000000 от -2147483648 до 2147483647 "<< sizeof (int)<<" байта\n"
        << "unsigned int i2 = 4000000; от 0 до 4294967295 "<< sizeof(unsigned int) <<" байта\n"
        << "long long ll1 = 2000000; от -9223372036854775808 до 9223372036854775807 "<< sizeof(long long) <<" байтов\n"
        << "unsigned long long = 1; от 0 до 18446744073709551615 "<< sizeof(unsigned long long) << " байтов\n"
        << "float f = 3.141444f; примерно от 3,4E–38 до 3,4E+38 "<< sizeof(float) <<" байта\n"
        << "double f2 = 3.1343545444f; примерно от 1,7E–308 до 1,7E+308 "<< sizeof(double) <<" байтов\n"
        << "bool b = true; false = 0 true = любое кроме 0 true/false "<< sizeof(bool) <<" байт\n"<< endl;
    cout << "введите значение с клавиатуры: ";
        
    cin >> number;
    int del_0 = number / 4;
    int sum_0 = number + 4;
    int raz_0 = number - 4;
    int um_0 = number * 4;
    cout << "\n";
    cout << "ваше значение: " << number << endl;
    cout << "новые значения: " << sum_0 <<  " " << raz_0 << " "<< um_0 << " " << del_0 <<endl;
    cout << "доп введите 2 числа: ";
    cin >> number2 >> number3;
    double del = number2 / number3;
    int del_int = number2 / number3;
    int sum = number2 + number3;
    int raz = number2 - number3;
    int um = number2 * number3;
    cout << "сложение - " << sum << "\n"
        << "вычитание - " << raz << "\n"
        << "умножение - " << um << "\n"
        << "деление int - " << del_int << " деление double - " << del << endl;

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
