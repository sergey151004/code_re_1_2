/**
 * @file main.cpp
 * @brief Главный файл для задачи о черепашке.
 *
 * Черепашка на квадратной доске с числами должна добраться из правого верхнего угла
 * в левый нижний, двигаясь только влево или вниз, собирая максимальную сумму чисел.
 */

#include "TurtlePath.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        int choice = 0;
        int rows = 0, cols = 0;
        std::vector<std::vector<int>> board;

        std::cout << "Выберите способ ввода данных:\n"
            << "1. Прочитать из файла\n"
            << "2. Ввести с клавиатуры\n"
            << "3. Заполнить случайными числами\n"
            << "Ваш выбор: ";

        while (!(std::cin >> choice) || choice < 1 || choice > 3) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Ошибка: Введите число от 1 до 3: ";
        }

        switch (choice) {
        case 1: {
            std::string filename = "input.txt";
            board = readBoardFromFile(filename, rows, cols);
            break;
        }
        case 2:
            board = readBoardFromKeyboard(rows, cols);
            break;
        case 3:
            board = generateRandomBoard(rows, cols);
            break;
        }

        std::cout << "\nДоска:\n";
        printBoard(board);

        int maxSum = calculateMaxPathSum(board, rows, cols);
        std::cout << "\nМаксимальная сумма на пути: " << maxSum << std::endl;

        std::ofstream output("output.txt");
        if (!output.is_open()) {
            std::cerr << "Ошибка: Не удалось открыть файл для записи" << std::endl;
            return 1;
        }
        output << maxSum;
        output.close();

        std::cout << "Результат записан в файл output.txt" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Произошла ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}