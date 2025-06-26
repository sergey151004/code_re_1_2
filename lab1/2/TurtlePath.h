/**
 * @file TurtlePath.h
 * @brief Заголовочный файл для решения задачи о черепашке.
 *
 * Задача: Черепашка на квадратной доске с числами должна добраться из правого верхнего угла
 * в левый нижний, двигаясь только влево или вниз, собирая максимальную сумму чисел.
 */

#ifndef TURTLEPATH_H
#define TURTLEPATH_H

#include <vector>
#include <string>

 /**
  * @brief Читает данные доски из файла.
  * @param filename Имя файла с данными.
  * @param rows Количество строк в доске (выходной параметр).
  * @param cols Количество столбцов в доске (выходной параметр).
  * @return Вектор векторов, представляющий доску.
  * @throws std::runtime_error Если файл не может быть открыт или данные некорректны.
  */
std::vector<std::vector<int>> readBoardFromFile(const std::string& filename, int& rows, int& cols);

/**
 * @brief Читает данные доски с клавиатуры.
 * @param rows Количество строк в доске (выходной параметр).
 * @param cols Количество столбцов в доске (выходной параметр).
 * @return Вектор векторов, представляющий доску.
 * @throws std::runtime_error Если ввод некорректен.
 */
std::vector<std::vector<int>> readBoardFromKeyboard(int& rows, int& cols);

/**
 * @brief Генерирует случайную доску.
 * @param rows Количество строк в доске (выходной параметр).
 * @param cols Количество столбцов в доске (выходной параметр).
 * @return Вектор векторов, представляющий доску.
 * @throws std::runtime_error Если размеры доски некорректны.
 */
std::vector<std::vector<int>> generateRandomBoard(int& rows, int& cols);

/**
 * @brief Вычисляет максимальную сумму чисел на пути черепашки.
 * @param board Доска с числами.
 * @param rows Количество строк в доске.
 * @param cols Количество столбцов в доске.
 * @return Максимальная сумма чисел на пути.
 * @throws std::runtime_error Если доска пуста или размеры некорректны.
 */
int calculateMaxPathSum(const std::vector<std::vector<int>>& board, int rows, int cols);

/**
 * @brief Выводит доску в консоль.
 * @param board Доска для вывода.
 */
void printBoard(const std::vector<std::vector<int>>& board);

#endif // TURTLEPATH_H