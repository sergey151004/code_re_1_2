/**
 * @file LinkedList.h
 * @brief Заголовочный файл для класса односвязного списка.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
     * @brief Возвращает значение последнего элемента списка.
     * @return Значение последнего элемента или -1, если список пуст.
     */
    int getLastValue() const;

    /**
     * @brief Проверяет наличие элемента в списке.
     * @param data Значение для поиска.
     * @return true, если элемент найден, иначе false.
     */
    bool contains(int data) const;

private:
    /**
     * @struct Node
     * @brief Узел односвязного списка.
     */
    struct Node {
        int data;      ///< Данные узла.
        Node* next;    ///< Указатель на следующий узел.
    };

    Node* head; ///< Указатель на голову списка.

    /**
     * @brief Возвращает указатель на последний узел списка.
     * @return Указатель на последний узел или nullptr, если список пуст.
     */
    Node* getLastNode() const;
};

#endif // LINKEDLIST_H