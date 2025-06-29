/**
 * @file LinkedList.h
 * @brief Заголовочный файл для циклического двусвязного списка
 *
 * Продолжение задания №4 (удаление элементов с одинаковыми соседями)
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

class Node {
private:
    int data;
    Node* next;
    Node* prev;

public:
    Node(int value);
    int getData() const;
    Node* getNext() const;
    Node* getPrev() const;
    void setNext(Node* node);
    void setPrev(Node* node);
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList();
    ~LinkedList();
    void addLast(int value);
    void removeNodesWithEqualNeighbors();
    void show() const;
    void clear();
    bool isEmpty() const;
};

#endif // LINKEDLIST_H