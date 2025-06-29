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
private:
    int data;     ///< ������ ����
    Node* next;   ///< ��������� �� ��������� ����

public:
    /**
     * @brief ����������� ����
     * @param value �������� ����
     * @param nextNode ��������� �� ��������� ����
     */
    Node(int value = 0, Node* nextNode = nullptr) : data(value), next(nextNode) {}

    // ������ �������
    int getData() const { return data; }
    Node* getNext() const { return next; }
    void setNext(Node* nextNode) { next = nextNode; }
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

    // ������ ����������� � ������������
    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;

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