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
        throw std::runtime_error("������� �����");
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
    std::cout << "\n�������� ����� ������� ��������: " << head << " " << (head ? head->getData() : 0) << "\n";
    std::cout << "�������� �������: ";

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->getData() << " ";
        current = current->getNext();
    }

    std::cout << "\n�������� ����� ���������� ��������: " << tail << " " << (tail ? tail->getData() : 0) << "\n";
}

void Queue::extractAndDisplay(int n) {
    std::cout << "\n����������� ��������:\n";
    for (int i = 0; i < n && !isEmpty(); ++i) {
        int value = dequeue();
        std::cout << "��������: " << value << ", �����: " << head << "\n";
    }
}

void Queue::displayFinalState() const {
    std::cout << "\n��������� ����� ����������:\n";
    if (isEmpty()) {
        std::cout << "������� �����\n";
        std::cout << "������ �������: nullptr\n";
        std::cout << "����� �������: nullptr\n";
    }
    else {
        std::cout << "����� ������ �������: " << head << " " << head->getData() << "\n";
        std::cout << "���������� ��������: ";

        Node* current = head;
        while (current != nullptr) {
            std::cout << current->getData() << " ";
            current = current->getNext();
        }

        std::cout << "\n����� ����� �������: " << tail << " " << tail->getData() << "\n";
    }
}