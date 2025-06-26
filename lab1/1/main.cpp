/**
 * @file main.cpp
 * @brief Главная программа для задачи выбора артефактов
 *
 * Задача: Археолог нашел N артефактов с известными весами (ci) и объемами (di).
 * Необходимо выбрать подмножество артефактов, где суммарный вес не превышает B кг,
 * но максимально близок к B, при этом количество взятых артефактов должно быть максимальным.
 * Решение единственное. Программа выводит номера выбранных артефактов, их суммарный вес и объем.
 * Входные данные берутся из текстового файла, где первая строка содержит N и B,
 * вторая строка - веса артефактов, третья - их объемы.
 */

#include "Artifact.h"
#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> selectedIndices;
    int totalWeight = 0;
    int totalVolume = 0;

    const std::string filename = "f.txt";

    if (!processArtifacts(filename, selectedIndices, totalWeight, totalVolume)) {
        return 1;
    }

    std::cout << "Номера выбранных артефактов: ";
    for (size_t i = 0; i < selectedIndices.size(); ++i) {
        std::cout << selectedIndices[i] + 1;  // +1 для перехода к 1-индексации
        if (i != selectedIndices.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\n";

    std::cout << "Суммарный вес: " << totalWeight << " кг\n";
    std::cout << "Суммарный объем: " << totalVolume << " куб.см\n";

    return 0;
}