/*
Продолжение задания №02 (Очередь)
Дано число N (> 0) и указатели P1 и P2 на начало и конец непустой очереди. Извлечь
из очереди N начальных элементов и вывести их значения (если очередь содержит менее N
элементов, то извлечь все ее элементы). Вывести также новые адреса начала и конца очереди
(для пустой очереди дважды вывести nullptr). После извлечения элементов из очереди
освобождать память, которую они занимали.
*/

#include <iostream>
#include "Queue.h"

/**
 * @brief Основная функция программы
 * @return Код завершения программы
 */
int main() {
    setlocale(LC_ALL, "Russian");
    try {
        Queue queue;
        int m = 0, n = 0;

        std::cout << "Введите количество элементов очереди: ";
        std::cin >> m;
        if (m <= 0 || std::cin.fail()) {
            std::cerr << "Ошибка: количество элементов должно быть положительным числом.\n";
            return 1;
        }

        std::cout << "Введите " << m << " значений элементов очереди: ";
        for (int i = 0; i < m; ++i) {
            int value = 0;
            std::cin >> value;
            if (std::cin.fail()) {
                std::cerr << "Ошибка: введено некорректное значение.\n";
                return 1;
            }
            queue.enqueue(value);
        }

        std::cout << "Введите количество элементов для извлечения (N > 0): ";
        std::cin >> n;
        if (n <= 0 || std::cin.fail()) {
            std::cerr << "Ошибка: N должно быть положительным числом.\n";
            return 1;
        }

        queue.displayInitialState();
        queue.extractAndDisplay(n);
        queue.displayFinalState();

    }
    catch (const std::exception& e) {
        std::cerr << "Произошла ошибка: " << e.what() << "\n";
        return 1;
    }

    return 0;
}