/**
 * @file Artifact.cpp
 * @brief Реализация функций для работы с артефактами
 *
 * Содержит функции для чтения данных об артефактах и выбора оптимального набора.
 */

#include "Artifact.h"
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

 /**
  * @brief Сравнивает артефакты по весу (для сортировки)
  */
static bool compareByWeight(const Artifact& a, const Artifact& b) {
    return a.weight < b.weight;
}

bool processArtifacts(const std::string& filename,
    std::vector<int>& selectedIndices,
    int& totalWeight,
    int& totalVolume) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        std::cerr << "Ошибка: Не удалось открыть файл " << filename << std::endl;
        return false;
    }

    int n = 0;  // Количество артефактов
    int b = 0;  // Максимально допустимый вес
    inputFile >> n >> b;

    // Проверка корректности входных данных
    if (n <= 0 || b <= 0) {
        std::cerr << "Ошибка: Некорректные входные данные (n=" << n << ", b=" << b << ")" << std::endl;
        inputFile.close();
        return false;
    }

    std::vector<Artifact> artifacts(n);
    std::vector<int> originalIndices(n);

    // Чтение весов артефактов
    for (int i = 0; i < n; ++i) {
        if (!(inputFile >> artifacts[i].weight)) {
            std::cerr << "Ошибка: Не удалось прочитать вес артефакта " << i << std::endl;
            inputFile.close();
            return false;
        }
        originalIndices[i] = i;
    }

    // Чтение объемов артефактов
    for (int i = 0; i < n; ++i) {
        if (!(inputFile >> artifacts[i].volume)) {
            std::cerr << "Ошибка: Не удалось прочитать объем артефакта " << i << std::endl;
            inputFile.close();
            return false;
        }
    }

    inputFile.close();

    // Сортировка артефактов по весу с сохранением оригинальных индексов
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (artifacts[i].weight > artifacts[j].weight) {
                std::swap(artifacts[i], artifacts[j]);
                std::swap(originalIndices[i], originalIndices[j]);
            }
        }
    }

    int maxWeight = 0;
    int maxVolume = 0;
    std::vector<int> bestIndices;

    // Поиск оптимального набора артефактов
    for (int start = 0; start < n; ++start) {
        int currentWeight = 0;
        int currentVolume = 0;
        std::vector<int> currentIndices;

        for (int i = start; i < n; ++i) {
            if (currentWeight + artifacts[i].weight <= b) {
                currentWeight += artifacts[i].weight;
                currentVolume += artifacts[i].volume;
                currentIndices.push_back(originalIndices[i]);
            }
        }

        // Обновляем лучший вариант если:
        // 1. Текущий вес лучше, или
        // 2. Вес такой же, но больше артефактов
        if (currentWeight > maxWeight ||
            (currentWeight == maxWeight && currentIndices.size() > bestIndices.size())) {
            maxWeight = currentWeight;
            maxVolume = currentVolume;
            bestIndices = currentIndices;
        }

        if (maxWeight == b) {
            break;  // Нашли идеальное решение
        }
    }

    // Сортируем индексы для вывода
    std::sort(bestIndices.begin(), bestIndices.end());

    selectedIndices = bestIndices;
    totalWeight = maxWeight;
    totalVolume = maxVolume;

    return true;
}