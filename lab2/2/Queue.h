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
private:
    int data;     ///< Данные узла
    Node* next;   ///< Указатель на следующий узел

public:
    /**
     * @brief Конструктор узла
     * @param value Значение узла
     * @param nextNode Указатель на следующий узел
     */
    Node(int value = 0, Node* nextNode = nullptr) : data(value), next(nextNode) {}

    // Методы доступа
    int getData() const { return data; }
    Node* getNext() const { return next; }
    void setNext(Node* nextNode) { next = nextNode; }
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

    // Запрет копирования и присваивания
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

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