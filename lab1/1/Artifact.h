/**
 * @file Artifact.h
 * @brief Заголовочный файл для работы с артефактами
 *
 * Содержит структуру Артефакт и функцию для обработки данных об артефактах.
 */

#ifndef ARTIFACT_H
#define ARTIFACT_H

#include <vector>
#include <string>

 /**
  * @brief Структура, описывающая артефакт
  */
struct Artifact {
    int weight;  ///< Вес артефакта в кг
    int volume;  ///< Объем артефакта в куб.см
};

/**
 * @brief Обрабатывает данные об артефактах из файла
 * @param filename Имя входного файла
 * @param selectedIndices Вектор для хранения индексов выбранных артефактов
 * @param totalWeight Суммарный вес выбранных артефактов
 * @param totalVolume Суммарный объем выбранных артефактов
 * @return bool True если обработка прошла успешно, false при ошибке
 */
bool processArtifacts(const std::string& filename,
    std::vector<int>& selectedIndices,
    int& totalWeight,
    int& totalVolume);

#endif // ARTIFACT_H