/*
Задание: Вычислить значение целочисленного выражения, заданного в виде строки S.
Выражение определяется следующим образом:
<выражение> ::= <терм> | <выражение> + <терм> | <выражение> - <терм>
<терм> ::= <цифра> | <терм> * <цифра>
*/

#include <iostream>
#include <string>
#include "ExpressionCalculator.h"

/**
 * Основная функция программы.
 * Запрашивает у пользователя выражение для вычисления и выводит результат.
 *
 * @return 0 при успешном выполнении, 1 при ошибке
 */
int main() {
    setlocale(LC_ALL, "Russian");
    std::string input;

    std::cout << "Введите выражение: ";
    if (!getline(std::cin, input)) {
        std::cerr << "Ошибка ввода данных." << std::endl;
        return 1;
    }

    try {
        int result = ExpressionCalculator::calculate(input);
        std::cout << "Ответ: " << result << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}