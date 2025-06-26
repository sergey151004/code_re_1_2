/**
 * @file LinkedList.cpp
 * @brief Реализация методов класса LinkedList.
 */

#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::append(int data) {
    Node* newNode = new Node{ data, nullptr };

    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void LinkedList::insertAfterEverySecond(int value) {
    if (head == nullptr) {
        std::cerr << "Список пуст. Вставка невозможна." << std::endl;
        return;
    }

    Node* current = head;
    int count = 1;

    while (current != nullptr) {
        if (count % 2 == 0) {
            Node* newNode = new Node{ value, current->next };
            current->next = newNode;
            current = newNode->next;
            count += 1; // Пропускаем только что добавленный элемент
        }
        else {
            current = current->next;
        }
        count += 1;
    }
}

bool LinkedList::remove(int data) {
    if (head == nullptr) {
        std::cerr << "Список пуст. Удаление невозможно." << std::endl;
        return false;
    }

    Node* current = head;
    Node* prev = nullptr;

    while (current != nullptr && current->data != data) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        std::cerr << "Элемент не найден." << std::endl;
        return false;
    }

    if (prev == nullptr) {
        head = current->next;
    }
    else {
        prev->next = current->next;
    }

    delete current;
    return true;
}

void LinkedList::display() const {
    Node* current = head;
    std::cout << "Список: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* LinkedList::getLastNode() const {
    if (head == nullptr) {
        return nullptr;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    return current;
}

Node* LinkedList::find(int data) const {
    Node* current = head;
    while (current != nullptr && current->data != data) {
        current = current->next;
    }
    return current;
}