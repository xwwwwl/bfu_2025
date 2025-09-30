// p2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#include <locale>
#include <cmath>


int main()
{
    setlocale(LC_ALL, "Russian");
    int b;
    int a;
    int number_of_bottles = 10;
    int number_of_bottles_purchased;

    std::cout << "золотые монеты: ";
    std::cin >> a;
    std::cout << "серебряные монеты: ";
    std::cin >> b;
    std::cout << "бутылок купить: ";
    std::cin >> number_of_bottles_purchased;

    int all_cilver_coins =  a * 100 + b;
    int max_count_of_bottle = floor(all_cilver_coins / 50);
    number_of_bottles_purchased = std::min(number_of_bottles_purchased, max_count_of_bottle);
    number_of_bottles_purchased = std::min(number_of_bottles_purchased, 10);

    all_cilver_coins = all_cilver_coins - number_of_bottles_purchased * 50;

    
    a = floor(all_cilver_coins / 100);
    b = all_cilver_coins - a * 100;
    number_of_bottles = number_of_bottles - number_of_bottles_purchased;
    std::cout << "У тебя осталось золотых монет: " << a << std::endl
        << "Серебряных монет: " << b << std::endl
        << "В магазине осталось бутылок: " << number_of_bottles << std::endl
        << "Ты купил бутылок: " << number_of_bottles_purchased << std::endl;

    all_cilver_coins = a * 100 + b;
    int max_length_all_cilver_coins = floor(log10(all_cilver_coins))+1;

    std::cout << "вариант 2" << std::endl;

    int reverse_all_cilver_coins = 0;
    std::cout << all_cilver_coins % 10;
    all_cilver_coins = floor(all_cilver_coins / 10);
    reverse_all_cilver_coins = all_cilver_coins % 10;
    all_cilver_coins = floor(all_cilver_coins / 10);
    reverse_all_cilver_coins = 10* reverse_all_cilver_coins + all_cilver_coins%10;
    all_cilver_coins = floor(all_cilver_coins / 10);
    reverse_all_cilver_coins = 10 * reverse_all_cilver_coins + all_cilver_coins % 10;
    all_cilver_coins = floor(all_cilver_coins / 10);
    reverse_all_cilver_coins = 10 * reverse_all_cilver_coins + all_cilver_coins % 10;
    all_cilver_coins = floor(all_cilver_coins / 10);
    reverse_all_cilver_coins = 10 * reverse_all_cilver_coins + all_cilver_coins % 10;
    all_cilver_coins = floor(all_cilver_coins / 10);
    reverse_all_cilver_coins = 10 * reverse_all_cilver_coins + all_cilver_coins % 10;
    all_cilver_coins = floor(all_cilver_coins / 10);
    reverse_all_cilver_coins = 10 * reverse_all_cilver_coins + all_cilver_coins % 10;
    all_cilver_coins = floor(all_cilver_coins / 10);
    reverse_all_cilver_coins = 10 * reverse_all_cilver_coins + all_cilver_coins % 10;
    all_cilver_coins = floor(all_cilver_coins / 10);
    reverse_all_cilver_coins = floor(reverse_all_cilver_coins / pow(10,9-max_length_all_cilver_coins));


    
    std::cout << reverse_all_cilver_coins;
        
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
