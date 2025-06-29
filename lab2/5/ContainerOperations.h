#ifndef CONTAINER_OPERATIONS_H
#define CONTAINER_OPERATIONS_H

#include <deque>
#include <list>
#include <iostream>

/**
 * @brief Статический класс для операций с контейнерами
 */
class ContainerOperations {
private:
    // Запрет создания экземпляров класса
    ContainerOperations() = delete;
    ~ContainerOperations() = delete;

public:
    /**
     * @brief Заполнение контейнера данными
     * @param container Контейнер для заполнения
     * @param size Размер контейнера
     * @return true если успешно, false при ошибке
     */
    template <typename Container>
    static bool inputContainer(Container& container, int size);

    /**
     * @brief Вывод содержимого контейнера
     * @param container Контейнер для вывода
     */
    template <typename Container>
    static void printContainer(const Container& container);

    /**
     * @brief Вставка последних 5 элементов дека перед 5-м с конца элементом списка
     * @param list Список для модификации
     * @param deque Дек с элементами для вставки
     * @return true если успешно, false при ошибке
     */
    static bool insertBeforeFifthFromEnd(std::list<int>& list, const std::deque<int>& deque);
};

#endif // CONTAINER_OPERATIONS_H