
#include <iostream>
#include <locale>
#include <cmath>


int main()
{
    
    int b;
    int a;
    int money;
    int number_of_bottles = 10;
    int const cost_bottles = 50;
    char const bottle_number = 1;
    int quantity_of_bread = 5;
    int const cost_bread = 120;
    char const bread_number = 2;
    int quantity_of_apple = 20;
    int const cost_apple = 30;
    char const apple_number = 3;
    float const discount_10 = 0.9f;
    float const discount_20 = 0.8f;
    int quantity_of_the_product_at_the_buyer = 0;
    int product_number;
    int quantity_of_product;

    std::cout << "Вариант 2" << std::endl;
    std::cout << "золотые монеты: ";
    std::cin >> a;
    std::cout << "серебряные монеты: ";
    std::cin >> b;
    std::cout << "номер товара, который хотите купить: ";
    std::cin >> product_number;
    std::cout << "количество товара, которое хотите купить: ";
    std::cin >> quantity_of_product;

    if (product_number < 0)
    {
        std::cout << "вы ввели отрицательное число" << std::endl;
    }
    money = a * 100 + b;
    switch (product_number)
    {
        case 1: 
            if (quantity_of_product <= number_of_bottles)
            {
                if (money >= cost_bottles * quantity_of_product)
                {

                    if (quantity_of_product > 5 and quantity_of_product <= 10)
                    {
                        money -= (cost_bottles * quantity_of_product)*discount_10;
                        std::cout << "скидка 10 процентов" << std::endl;
                    }
                    else if (quantity_of_product > 10)
                    {
                        money -= (cost_bottles * quantity_of_product) * discount_20;
                        std::cout << "скидка 20 процентов" << std::endl;
                    }
                    else {
                        money -= cost_bottles * quantity_of_product;
                    }
                    number_of_bottles -= quantity_of_product;
                    quantity_of_the_product_at_the_buyer+= quantity_of_product;
                    a = floor(money / 100);
                    b = money - a * 100;
                    std::cout << "У тебя осталось золотых монет: " << a << std::endl
                        << "Серебряных монет: " << b << std::endl
                        << "В магазине осталось бутылок: " << number_of_bottles << std::endl
                        << "Ты купил бутылок: " << quantity_of_the_product_at_the_buyer << std::endl;
                    
                }
                else {
                    std::cout << "у вас не хватает денег" << std::endl;
                }
            }
            else {
                std::cout << "такого количества товара нет в магазине" << std::endl;
            }
                
            break;
        case 2:
            if (quantity_of_product <= quantity_of_bread)
            {
                if (money >= cost_bread * quantity_of_product)
                {
                    if (quantity_of_product > 5 and quantity_of_product <= 10)
                    {
                        money -= (cost_bread * quantity_of_product) * discount_10;
                        std::cout << "скидка 10 процентов" << std::endl;
                    }
                    else if (quantity_of_product > 10)
                    {
                        money -= (cost_bread * quantity_of_product) * discount_20;
                        std::cout << "скидка 20 процентов" << std::endl;
                    }
                    else {
                        money -= cost_bread * quantity_of_product;
                    }
                    quantity_of_bread -= quantity_of_product;
                    quantity_of_the_product_at_the_buyer += quantity_of_product;
                    a = floor(money / 100);
                    b = money - a * 100;
                    std::cout << "У тебя осталось золотых монет: " << a << std::endl
                        << "Серебряных монет: " << b << std::endl
                        << "В магазине осталось хлеба: " << quantity_of_bread << std::endl
                        << "Ты купил хлеба: " << quantity_of_the_product_at_the_buyer << std::endl;
                }
                else {
                    std::cout << "у вас не хватает денег" << std::endl;
                }
            }
            else {
                std::cout << "такого количества товара нет в магазине" << std::endl;
            }

            break;
        case 3:
            if (quantity_of_product <= quantity_of_apple)
            {
                if (money >= cost_apple * quantity_of_product)
                {
                    if (quantity_of_product > 5 and quantity_of_product <= 10)
                    {
                        money -= (cost_apple * quantity_of_product) * discount_10;
                        std::cout << "скидка 10 процентов" << std::endl;
                    }
                    else if (quantity_of_product > 10)
                    {
                        money -= (cost_apple * quantity_of_product) * discount_20;
                        std::cout << "скидка 20 процентов" << std::endl;
                    }
                    else {
                        money -= cost_apple * quantity_of_product;
                    }
                    quantity_of_apple -= quantity_of_product;
                    quantity_of_the_product_at_the_buyer += quantity_of_product;
                    a = floor(money / 100);
                    b = money - a * 100;
                    std::cout << "У тебя осталось золотых монет: " << a << std::endl
                        << "Серебряных монет: " << b << std::endl
                        << "В магазине осталось яблок: " << quantity_of_apple << std::endl
                        << "Ты купил яблок: " << quantity_of_the_product_at_the_buyer << std::endl;
                }
                else {
                    std::cout << "у вас не хватает денег" << std::endl;
                }
            }
            else {
                std::cout << "такого количества товара нет в магазине" << std::endl;
            }

  
            break;

        default: std::cout << "товара с таким номером нет в магазине";
    }
    
    
    
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