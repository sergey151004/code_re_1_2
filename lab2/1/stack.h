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
        Node* next;     ///< ��������� �� ��������� �������
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* top;          ///< ��������� �� ������� �����
    int count;          ///< ���������� ��������� � �����

public:
    Stack();
    ~Stack();
    void push(int value);
    void pop();
    void display() const;
    bool isEmpty() const;
};

#endif // STACK_H