/**
 * @file main.cpp
 * @brief Основной файл программы для работы с циклическим двусвязным списком
 */

#include "LinkedList.h"
#include <iostream>
#include <limits>
#include <sstream>

int safeInputInt(const std::string& message) {
    int value;
    while (true) {
        std::cout << message;
        if (std::cin >> value) {
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Ошибка: введите целое число!" << std::endl;
        }
    }
    return value;
}

std::string intToString(int value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

int main() {
    setlocale(LC_ALL, "Russian");
    LinkedList list;

    int n = safeInputInt("Введите количество чисел, которые необходимо записать в список: ");
    if (n <= 0) {
        std::cerr << "Ошибка: количество элементов должно быть положительным!" << std::endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        int x = safeInputInt("Введите " + intToString(i + 1) + " число: ");
        list.addLast(x);
    }

    std::cout << "Исходный список: ";
    list.show();

    list.removeNodesWithEqualNeighbors();
    std::cout << "Изменённый список: ";
    list.show();

    return 0;
}