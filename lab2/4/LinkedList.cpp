/**
 * @file LinkedList.cpp
 * @brief Реализация методов циклического двусвязного списка
 */

#include "LinkedList.h"
#include <iostream>

Node::Node(int value) : data(value), next(nullptr), prev(nullptr) {}

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::addLast(int value) {
    Node* newNode = new Node(value);

    if (tail == nullptr) {
        head = tail = newNode;
        head->next = head;
        head->prev = head;
    }
    else {
        newNode->prev = tail;
        newNode->next = head;
        tail->next = newNode;
        head->prev = newNode;
        tail = newNode;
    }
}

void LinkedList::removeNodesWithEqualNeighbors() {
    if (head == nullptr) return;

    Node* current = head;
    Node* nextNode = nullptr;

    do {
        nextNode = current->next;

        if (current->prev->data == current->next->data && current->prev != current->next) {
            if (current == head && current == tail) {
                delete current;
                head = tail = nullptr;
                break;
            }
            else if (current == head) {
                head = current->next;
            }
            else if (current == tail) {
                tail = current->prev;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }

        current = nextNode;
    } while (current != head && head != nullptr);
}

void LinkedList::show() const {
    if (head == nullptr) {
        std::cout << "Список пуст" << std::endl;
        return;
    }

    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);

    std::cout << std::endl;
}

void LinkedList::clear() {
    if (head == nullptr) return;

    Node* current = head;
    do {
        Node* temp = current;
        current = current->next;
        delete temp;
    } while (current != head);

    head = tail = nullptr;
}