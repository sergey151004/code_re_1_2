/**
 * @file main.cpp
 * @brief Основной файл для демонстрации работы с односвязным списком.
 * @details Продолжение задания: вставить значение M после каждого второго элемента списка.
 */

#include "LinkedList.h"
#include <iostream>

 /**
  * @brief Проверяет, является ли введённое число корректным.
  * @param value Введённое значение.
  * @param min Минимально допустимое значение.
  * @param message Сообщение для пользователя.
  * @return Корректное число.
  */
int getValidInput(int min, const std::string& message) {
    int value;
    while (true) {
        std::cout << message;
        std::cin >> value;
        if (std::cin.fail() || value < min) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Ошибка: введите число >= " << min << "." << std::endl;
        }
        else {
            break;
        }
    }
    return value;
}

int main() {
    setlocale(LC_ALL, "Russian");
    LinkedList list;
    int n, m, x;

    std::cout << "Добро пожаловать!" << std::endl;
    std::cout << "Перед нами задача: вставить значение M после каждого второго элемента списка." << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    n = getValidInput(3, "Введите количество элементов в списке (>= 3): ");
    std::cout << "Введите " << n << " элементов списка: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> x;
        list.append(x);
    }

    std::cout << "Введите значение M для вставки: ";
    std::cin >> m;

    list.display();
    list.insertAfterEverySecond(m);
    std::cout << "Список после вставки:" << std::endl;
    list.display();

    Node* lastNode = list.getLastNode();
    if (lastNode != nullptr) {
        std::cout << "Ссылка на последний элемент: " << lastNode << ", значение: " << lastNode->data << std::endl;
    }

    std::cout << "Хотите удалить какой-нибудь элемент? (1 - да, 2 - нет): ";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
        int num = getValidInput(1, "Введите количество элементов для удаления: ");
        for (int i = 0; i < num; ++i) {
            int value = getValidInput(0, "Введите значение элемента для удаления: ");
            if (!list.remove(value)) {
                std::cerr << "Элемент не был удалён." << std::endl;
            }
        }
        list.display();
    }

    std::cout << "Спасибо за использование программы!" << std::endl;
    return 0;
}