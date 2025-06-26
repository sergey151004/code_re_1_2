/**
 * @file stack.cpp
 * @brief Реализация методов класса Stack.
 */

#include "stack.h"
#include <iostream>

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
    count += 1;
}

/**
 * @brief Извлекает элемент из вершины стека.
 * @details Выводит значение извлекаемого элемента и адрес новой вершины.
 *          Если стек становится пустым, устанавливает top в nullptr.
 */
void Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Ошибка: попытка извлечь элемент из пустого стека." << std::endl;
        return;
    }

    Node* temp = top;
    std::cout << "Извлеченный элемент: " << top->data << std::endl;

    top = top->next;
    std::cout << "Адрес новой вершины: " << top << std::endl;

    if (top != nullptr) {
        std::cout << "Значение новой вершины: " << top->data << std::endl;
    }

    delete temp;
    count -= 1;
}

/**
 * @brief Проверяет, пуст ли стек.
 * @return true если стек пуст, false в противном случае.
 */
bool Stack::isEmpty() const {
    return top == nullptr;
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
    std::cout << "Содержимое стека:" << std::endl;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}