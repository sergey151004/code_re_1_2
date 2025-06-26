#include "SequenceCounter.h"
#include <stdexcept>

/**
 * @brief Подсчитывает количество K-ичных чисел из N разрядов без двух подряд идущих нулей
 * @param n Количество разрядов
 * @param k Основание системы счисления
 * @return Количество валидных чисел
 * @throws std::invalid_argument Если входные данные невалидны
 */
double SequenceCounter::countValidSequences(int n, int k) {
    // Проверка входных данных
    if (k < 2 || k > 10) {
        throw std::invalid_argument("Основание системы счисления K должно быть в диапазоне [2, 10]");
    }
    if (n <= 1 || n >= 20) {
        throw std::invalid_argument("Количество разрядов N должно быть в диапазоне (1, 20)");
    }
    if (k + n >= 26) {
        throw std::invalid_argument("Сумма K + N должна быть меньше 26");
    }

    // nz = числа без двух подряд идущих нулей, не оканчивающиеся на 0
    // oz = числа без двух подряд идущих нулей, оканчивающиеся на 0
    // tz = числа с двумя подряд идущими нулями
    double nz = k - 1;  // Первая цифра может быть любой, кроме 0
    double oz = 1;       // Только число "0"
    double tz = 0;       // Невозможно для 1-разрядных чисел

    for (int i = 2; i <= n; ++i) {
        double prev_nz = nz;
        double prev_oz = oz;
        double prev_tz = tz;

        nz = prev_nz * (k - 1) + prev_oz * (k - 1);
        oz = prev_nz;
        tz = prev_tz * k + prev_oz;
    }

    return nz + oz;
}