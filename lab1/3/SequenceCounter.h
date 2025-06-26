/**
 * @file SequenceCounter.h
 * @brief Заголовочный файл для подсчета K-ичных чисел без двух подряд идущих нулей
 */

#pragma once

 /**
  * @class SequenceCounter
  * @brief Класс для подсчета валидных последовательностей
  */
class SequenceCounter {
public:
    /**
     * @brief Подсчитывает количество K-ичных чисел из N разрядов без двух подряд идущих нулей
     * @param n Количество разрядов
     * @param k Основание системы счисления
     * @return Количество валидных чисел
     * @throws std::invalid_argument Если входные данные невалидны
     */
    static double countValidSequences(int n, int k);
};