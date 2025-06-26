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
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value);
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList();
    ~LinkedList();
    void addLast(int value);
    void removeNodesWithEqualNeighbors();
    void show() const;
    void clear();
};

#endif // LINKEDLIST_H