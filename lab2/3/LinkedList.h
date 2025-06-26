/**
 * @file LinkedList.h
 * @brief Заголовочный файл для класса односвязного списка.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

 /**
  * @class Node
  * @brief Узел односвязного списка.
  */
class Node {
public:
    int data;      ///< Данные узла.
    Node* next;    ///< Указатель на следующий узел.
};

/**
 * @class LinkedList
 * @brief Класс для работы с односвязным списком.
 */
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    /**
     * @brief Добавляет элемент в конец списка.
     * @param data Значение элемента.
     */
    void append(int data);

    /**
     * @brief Вставляет значение после каждого второго элемента.
     * @param value Значение для вставки.
     */
    void insertAfterEverySecond(int value);

    /**
     * @brief Удаляет элемент по значению.
     * @param data Значение элемента для удаления.
     * @return true, если удаление прошло успешно, иначе false.
     */
    bool remove(int data);

    /**
     * @brief Выводит список на экран.
     */
    void display() const;

    /**
     * @brief Возвращает указатель на последний элемент списка.
     * @return Указатель на последний элемент.
     */
    Node* getLastNode() const;

    /**
     * @brief Находит узел по значению.
     * @param data Значение для поиска.
     * @return Указатель на найденный узел или nullptr, если не найден.
     */
    Node* find(int data) const;

private:
    Node* head; ///< Указатель на голову списка.
};

#endif // LINKEDLIST_H