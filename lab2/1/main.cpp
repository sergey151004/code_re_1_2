/**
 * @file main.cpp
 * @brief Основной файл для демонстрации работы со стеком.
 */

#include "stack.h"
#include <iostream>
#include <limits>
#include <stdexcept>

 /**
  * @brief Проверяет корректность ввода числа.
  * @param message Сообщение для пользователя.
  * @return Введенное пользователем число.
  */
int getValidInput(const std::string& message) {
    int value;
    while (true) {
        std::cout << message;
        if (std::cin >> value) {
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Ошибка: введено некорректное значение. Повторите попытку." << std::endl;
        }
    }
    return value;
}

int main() {
    setlocale(LC_ALL, "Russian");

    try {
        Stack stack;

        int n = getValidInput("Введите количество элементов стека: ");
        for (int i = 0; i < n; ++i) {
            int num = getValidInput("Введите элемент стека: ");
            stack.push(num);
        }

        stack.display();

        if (!stack.isEmpty()) {
            stack.pop();
        }

        std::cout << "Текущий размер стека: " << stack.size() << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}