#include "Queue.h"
#include <iostream>

Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int value) {
    Node* newNode = new Node(value);

    if (isEmpty()) {
        head = tail = newNode;
    }
    else {
        tail->setNext(newNode);
        tail = newNode;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Очередь пуста");
    }

    Node* temp = head;
    int value = temp->getData();
    head = head->getNext();

    if (head == nullptr) {
        tail = nullptr;
    }

    delete temp;
    return value;
}

bool Queue::isEmpty() const {
    return head == nullptr;
}

void Queue::displayInitialState() const {
    std::cout << "\nИсходный адрес первого элемента: " << head << " " << (head ? head->getData() : 0) << "\n";
    std::cout << "Исходная очередь: ";

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->getData() << " ";
        current = current->getNext();
    }

    std::cout << "\nИсходный адрес последнего элемента: " << tail << " " << (tail ? tail->getData() : 0) << "\n";
}

void Queue::extractAndDisplay(int n) {
    std::cout << "\nИзвлеченные элементы:\n";
    for (int i = 0; i < n && !isEmpty(); ++i) {
        int value = dequeue();
        std::cout << "Значение: " << value << ", Адрес: " << head << "\n";
    }
}

void Queue::displayFinalState() const {
    std::cout << "\nСостояние после извлечения:\n";
    if (isEmpty()) {
        std::cout << "Очередь пуста\n";
        std::cout << "Начало очереди: nullptr\n";
        std::cout << "Конец очереди: nullptr\n";
    }
    else {
        std::cout << "Новое начало очереди: " << head << " " << head->getData() << "\n";
        std::cout << "Оставшиеся элементы: ";

        Node* current = head;
        while (current != nullptr) {
            std::cout << current->getData() << " ";
            current = current->getNext();
        }

        std::cout << "\nНовый конец очереди: " << tail << " " << tail->getData() << "\n";
    }
}