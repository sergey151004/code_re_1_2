/**
 * @file LinkedList.cpp
 * @brief Реализация методов циклического двусвязного списка
 */

#include "LinkedList.h"
#include <iostream>

Node::Node(int value) : data(value), next(nullptr), prev(nullptr) {}

int Node::getData() const {
    return data;
}

Node* Node::getNext() const {
    return next;
}

Node* Node::getPrev() const {
    return prev;
}

void Node::setNext(Node* node) {
    next = node;
}

void Node::setPrev(Node* node) {
    prev = node;
}

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

bool LinkedList::isEmpty() const {
    return head == nullptr;
}

void LinkedList::addLast(int value) {
    Node* newNode = new Node(value);

    if (isEmpty()) {
        head = tail = newNode;
        head->setNext(head);
        head->setPrev(head);
    }
    else {
        newNode->setPrev(tail);
        newNode->setNext(head);
        tail->setNext(newNode);
        head->setPrev(newNode);
        tail = newNode;
    }
}

void LinkedList::removeNodesWithEqualNeighbors() {
    if (isEmpty()) return;

    Node* current = head;
    Node* nextNode = nullptr;

    do {
        nextNode = current->getNext();

        if (current->getPrev()->getData() == current->getNext()->getData() && current->getPrev() != current->getNext()) {
            if (current == head && current == tail) {
                delete current;
                head = tail = nullptr;
                break;
            }
            else if (current == head) {
                head = current->getNext();
            }
            else if (current == tail) {
                tail = current->getPrev();
            }

            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
            delete current;
        }

        current = nextNode;
    } while (current != head && !isEmpty());
}

void LinkedList::show() const {
    if (isEmpty()) {
        std::cout << "Список пуст" << std::endl;
        return;
    }

    Node* current = head;
    do {
        std::cout << current->getData() << " ";
        current = current->getNext();
    } while (current != head);

    std::cout << std::endl;
}

void LinkedList::clear() {
    if (isEmpty()) return;

    Node* current = head;
    do {
        Node* temp = current;
        current = current->getNext();
        delete temp;
    } while (current != head);

    head = tail = nullptr;
}