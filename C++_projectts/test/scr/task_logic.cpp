int a = 10;
    int b = 2;

    try {
        if (b == 0)
            throw std::runtime_error("Деление на ноль!");
        
        std::cout << "Результат деления: " << a / b << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << "Ошибка времени выполнения: " << e.what() << '\n';
    }

    return 0;