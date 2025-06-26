/**
 * @file Queue.h
 * @brief Заголовочный файл для работы с очередью
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

 /**
  * @class Node
  * @brief Узел очереди
  */
class Node {
public:
    int data;     ///< Данные узла
    Node* next;   ///< Указатель на следующий узел
};

/**
 * @class Queue
 * @brief Класс для работы с очередью
 */
class Queue {
private:
    Node* head;   ///< Указатель на начало очереди
    Node* tail;   ///< Указатель на конец очереди

public:
    /**
     * @brief Конструктор по умолчанию
     */
    Queue();

    /**
     * @brief Деструктор
     */
    ~Queue();

    /**
     * @brief Добавление элемента в очередь
     * @param value Значение элемента
     */
    void enqueue(int value);

    /**
     * @brief Извлечение элемента из очереди
     * @return Значение извлеченного элемента
     * @throws std::runtime_error если очередь пуста
     */
    int dequeue();

    /**
     * @brief Проверка на пустоту очереди
     * @return true если очередь пуста, иначе false
     */
    bool isEmpty() const;

    /**
     * @brief Отображение начального состояния очереди
     */
    void displayInitialState() const;

    /**
     * @brief Извлечение и отображение N элементов
     * @param n Количество элементов для извлечения
     */
    void extractAndDisplay(int n);

    /**
     * @brief Отображение конечного состояния очереди
     */
    void displayFinalState() const;
};

#endif // QUEUE_H