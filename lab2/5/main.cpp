/*
Продолжение задания №5 (работа с контейнерами)
Даны дек D и список L. Каждый исходный контейнер содержит не менее 5 элементов.
Вставить перед пятым с конца элементом списка последние 5 элементов дека в обратном порядке.
Использовать один вызов функции-члена insert.
*/

#include <ctime>
#include <deque>
#include <list>
#include <fstream>
#include <iostream>
#include "ContainerOperations.h"

int main() {
    setlocale(LC_ALL, "Russian");
    int dequeSize = 0;
    int listSize = 0;

    std::deque<int> D;
    std::list<int> L;

    // Ввод данных для дека
    std::cout << "Введите размерность дека (>= 5): ";
    std::cin >> dequeSize;
    if (!ContainerOperations::inputContainer(D, dequeSize)) {
        std::cerr << "Ошибка при вводе дека." << std::endl;
        return 1;
    }

    // Ввод данных для списка
    std::cout << "Введите размерность списка (>= 5): ";
    std::cin >> listSize;
    if (!ContainerOperations::inputContainer(L, listSize)) {
        std::cerr << "Ошибка при вводе списка." << std::endl;
        return 1;
    }

    // Вывод исходных данных
    std::cout << "\nИзначальное содержимое контейнеров:" << std::endl;
    std::cout << "Дек: ";
    ContainerOperations::printContainer(D);
    std::cout << "Список: ";
    ContainerOperations::printContainer(L);

    // Выполнение операции вставки
    if (!ContainerOperations::insertBeforeFifthFromEnd(L, D)) {
        std::cerr << "Ошибка при выполнении операции вставки." << std::endl;
        return 1;
    }

    // Вывод результатов
    std::cout << "\nИзменённое содержимое контейнеров:" << std::endl;
    std::cout << "Дек: ";
    ContainerOperations::printContainer(D);
    std::cout << "Список: ";
    ContainerOperations::printContainer(L);

    return 0;
}