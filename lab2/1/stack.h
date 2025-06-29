/**
 * @file stack.h
 * @brief ������������ ���� ��� ������ Stack, ������������ ��������� ������ "����".
 *
 * �������: ��� ��������� P1 �� ������� ��������� �����. ������� �� ����� ������ (�������)
 * ������� � ������� ��� �������� D, � ����� ����� P2 ����� ������� �����. ���� �����
 * ���������� �������� ���� �������� ������, �� �������� P2 = nullptr.
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>

 /**
  * @class Stack
  * @brief �����, ����������� ��������� ������ "����" �� ������ ���������� ������.
  */
class Stack {
private:
    struct Node {
        int data;      ///< �������� �������� �����
        Node* next;    ///< ��������� �� ��������� �������

        explicit Node(int val) : data(val), next(nullptr) {}

        // ��������� ����������� � ������������ �����
        Node(const Node&) = delete;
        Node& operator=(const Node&) = delete;
    };

    Node* top;         ///< ��������� �� ������� �����
    int count;         ///< ���������� ��������� � �����

    // ��������� ����������� � ������������ �����
    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

public:
    Stack();
    ~Stack();

    void push(int value);
    void pop();
    void display() const;
    bool isEmpty() const;
    int size() const;
};

#endif // STACK_H