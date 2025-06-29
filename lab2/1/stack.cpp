/**
 * @file stack.cpp
 * @brief ���������� ������� ������ Stack.
 */

#include "stack.h"
#include <iostream>
#include <stdexcept>

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
    count++;
}

/**
 * @brief ��������� ������� �� ������� �����.
 * @throw std::runtime_error ���� ���� ����
 */
void Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("������: ������� ������� ������� �� ������� �����.");
    }

    Node* temp = top;
    std::cout << "����������� �������: " << top->data << std::endl;

    top = top->next;
    std::cout << "����� ����� �������: " << top << std::endl;

    if (top != nullptr) {
        std::cout << "�������� ����� �������: " << top->data << std::endl;
    }

    delete temp;
    count--;
}

/**
 * @brief ���������, ���� �� ����.
 * @return true ���� ���� ����, false � ��������� ������.
 */
bool Stack::isEmpty() const {
    return top == nullptr;
}

/**
 * @brief ���������� ���������� ��������� � �����.
 * @return ���������� ��������� � �����.
 */
int Stack::size() const {
    return count;
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
    std::cout << "���������� ����� (����� ���������: " << count << "):" << std::endl;
    while (current != nullptr) {
        std::cout << current->data << std::endl;
        current = current->next;
    }
}