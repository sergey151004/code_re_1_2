/**
 * @file main.cpp
 * @brief Основной файл для демонстрации работы со стеком.
 */

#include "stack.h"
#include <iostream>
#include <limits>

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
    Stack stack;

    int n = getValidInput("Введите количество элементов стека: ");
    for (int i = 0; i < n; ++i) {
        int num = getValidInput("Введите элемент стека: ");
        stack.push(num);
    }

    stack.display();
    stack.pop();

    return 0;
}