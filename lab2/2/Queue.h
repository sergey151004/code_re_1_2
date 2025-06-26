/**
 * @file Queue.h
 * @brief ������������ ���� ��� ������ � ��������
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

 /**
  * @class Node
  * @brief ���� �������
  */
class Node {
public:
    int data;     ///< ������ ����
    Node* next;   ///< ��������� �� ��������� ����
};

/**
 * @class Queue
 * @brief ����� ��� ������ � ��������
 */
class Queue {
private:
    Node* head;   ///< ��������� �� ������ �������
    Node* tail;   ///< ��������� �� ����� �������

public:
    /**
     * @brief ����������� �� ���������
     */
    Queue();

    /**
     * @brief ����������
     */
    ~Queue();

    /**
     * @brief ���������� �������� � �������
     * @param value �������� ��������
     */
    void enqueue(int value);

    /**
     * @brief ���������� �������� �� �������
     * @return �������� ������������ ��������
     * @throws std::runtime_error ���� ������� �����
     */
    int dequeue();

    /**
     * @brief �������� �� ������� �������
     * @return true ���� ������� �����, ����� false
     */
    bool isEmpty() const;

    /**
     * @brief ����������� ���������� ��������� �������
     */
    void displayInitialState() const;

    /**
     * @brief ���������� � ����������� N ���������
     * @param n ���������� ��������� ��� ����������
     */
    void extractAndDisplay(int n);

    /**
     * @brief ����������� ��������� ��������� �������
     */
    void displayFinalState() const;
};

#endif // QUEUE_H