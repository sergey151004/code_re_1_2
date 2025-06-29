/**
 * @file stack.cpp
 * @brief Реализация методов класса Stack.
 */

#include "stack.h"
#include <iostream>
#include <stdexcept>

 /**
  * @brief Конструктор по умолчанию.
  */
Stack::Stack() : top(nullptr), count(0) {}

/**
 * @brief Деструктор, освобождающий память.
 */
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

/**
 * @brief Добавляет элемент в стек.
 * @param value Значение добавляемого элемента.
 */
void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    count++;
}

/**
 * @brief Извлекает элемент из вершины стека.
 * @throw std::runtime_error если стек пуст
 */
void Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Ошибка: попытка извлечь элемент из пустого стека.");
    }

    Node* temp = top;
    std::cout << "Извлеченный элемент: " << top->data << std::endl;

    top = top->next;
    std::cout << "Адрес новой вершины: " << top << std::endl;

    if (top != nullptr) {
        std::cout << "Значение новой вершины: " << top->data << std::endl;
    }

    delete temp;
    count--;
}

/**
 * @brief Проверяет, пуст ли стек.
 * @return true если стек пуст, false в противном случае.
 */
bool Stack::isEmpty() const {
    return top == nullptr;
}

/**
 * @brief Возвращает количество элементов в стеке.
 * @return Количество элементов в стеке.
 */
int Stack::size() const {
    return count;
}

/**
 * @brief Выводит содержимое стека.
 */
void Stack::display() const {
    if (isEmpty()) {
        std::cout << "Стек пуст." << std::endl;
        return;
    }

    Node* current = top;
    std::cout << "Содержимое стека (всего элементов: " << count << "):" << std::endl;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}