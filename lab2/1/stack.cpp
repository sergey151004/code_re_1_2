/**
 * @file stack.cpp
 * @brief ���������� ������� ������ Stack.
 */

#include "stack.h"
#include <iostream>

 /**
  * @brief ����������� �� ���������.
  */
Stack::Stack() : top(nullptr), count(0) {}

/**
 * @brief ����������, ������������� ������.
 */
Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

/**
 * @brief ��������� ������� � ����.
 * @param value �������� ������������ ��������.
 */
void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    count += 1;
}

/**
 * @brief ��������� ������� �� ������� �����.
 * @details ������� �������� ������������ �������� � ����� ����� �������.
 *          ���� ���� ���������� ������, ������������� top � nullptr.
 */
void Stack::pop() {
    if (isEmpty()) {
        std::cerr << "������: ������� ������� ������� �� ������� �����." << std::endl;
        return;
    }

    Node* temp = top;
    std::cout << "����������� �������: " << top->data << std::endl;

    top = top->next;
    std::cout << "����� ����� �������: " << top << std::endl;

    if (top != nullptr) {
        std::cout << "�������� ����� �������: " << top->data << std::endl;
    }

    delete temp;
    count -= 1;
}

/**
 * @brief ���������, ���� �� ����.
 * @return true ���� ���� ����, false � ��������� ������.
 */
bool Stack::isEmpty() const {
    return top == nullptr;
}

/**
 * @brief ������� ���������� �����.
 */
void Stack::display() const {
    if (isEmpty()) {
        std::cout << "���� ����." << std::endl;
        return;
    }

    Node* current = top;
    std::cout << "���������� �����:" << std::endl;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}