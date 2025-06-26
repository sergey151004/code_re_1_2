/**
 * @file ExpressionCalculator.h
 * @brief Заголовочный файл для вычисления арифметических выражений
 */

#pragma once
#include <string>

 /**
  * @class ExpressionCalculator
  * @brief Класс для вычисления арифметических выражений
  */
class ExpressionCalculator {
public:
    /**
     * Вычисляет значение арифметического выражения
     *
     * @param expression Строка с выражением для вычисления
     * @return Результат вычисления
     * @throws std::invalid_argument Если выражение некорректно
     */
    static int calculate(const std::string& expression);

private:
    /**
     * Обрабатывает элемент выражения (число или выражение в скобках)
     *
     * @param str Подстрока выражения
     * @return Значение элемента
     * @throws std::invalid_argument Если элемент некорректен
     */
    static int parseElement(const std::string& str);

    /**
     * Обрабатывает терм (умножение или простой элемент)
     *
     * @param str Подстрока выражения
     * @return Значение терма
     * @throws std::invalid_argument Если терм некорректен
     */
    static int parseTerm(const std::string& str);

    /**
     * Вычисляет выражение (сложение/вычитание термов)
     *
     * @param str Подстрока выражения
     * @return Результат вычисления
     * @throws std::invalid_argument Если выражение некорректно
     */
    static int evaluateExpression(const std::string& str);
};