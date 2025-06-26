/**
 * @file stack.h
 * @brief Заголовочный файл для класса Stack, реализующего структуру данных "стек".
 *
 * Задание: Дан указатель P1 на вершину непустого стека. Извлечь из стека первый (верхний)
 * элемент и вывести его значение D, а также адрес P2 новой вершины стека. Если после
 * извлечения элемента стек окажется пустым, то положить P2 = nullptr.
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>

 /**
  * @class Stack
  * @brief Класс, реализующий структуру данных "стек" на основе связанного списка.
  */
class Stack {
private:
    struct Node {
        int data;      ///< Значение элемента стека
        Node* next;     ///< Указатель на следующий элемент
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* top;          ///< Указатель на вершину стека
    int count;          ///< Количество элементов в стеке

public:
    Stack();
    ~Stack();
    void push(int value);
    void pop();
    void display() const;
    bool isEmpty() const;
};

#endif // STACK_H