#include "ContainerOperations.h"
#include <ctime>
#include <fstream>
#include <stdexcept>

template <typename Container>
bool ContainerOperations::inputContainer(Container& container, int size) {
    if (size < 5) {
        std::cerr << "������: ������ ������ ���� >= 5." << std::endl;
        return false;
    }

    int choice = 0;
    std::cout << "�������� ������ ���������� ����������:\n"
        << "1) ���� � ����������\n"
        << "2) ���� � ������� ������������\n"
        << "3) ���� �� �����\n";
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "������: ������������ ����." << std::endl;
        return false;
    }

    try {
        switch (choice) {
        case 1: {
            int value = 0;
            for (int i = 0; i < size; ++i) {
                std::cout << "������� ������� " << i + 1 << ": ";
                std::cin >> value;
                if (std::cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "������: ������������ ����." << std::endl;
                    return false;
                }
                container.insert(container.end(), value);
            }
            break;
        }
        case 2: {
            std::srand(std::time(0));
            for (int i = 0; i < size; ++i) {
                container.insert(container.end(), std::rand() % 101 - 50);
            }
            break;
        }
        case 3: {
            std::ifstream file("input.txt");
            if (!file.is_open()) {
                std::cerr << "������: �� ������� ������� ����." << std::endl;
                return false;
            }
            int value = 0;
            for (int i = 0; i < size; ++i) {
                if (!(file >> value)) {
                    std::cerr << "������: ������������ ������ � �����." << std::endl;
                    file.close();
                    return false;
                }
                container.insert(container.end(), value);
            }
            file.close();
            break;
        }
        default: {
            std::cerr << "������: �������� �����." << std::endl;
            return false;
        }
        }
    }
    catch (...) {
        std::cerr << "������ ��� ���������� ����������." << std::endl;
        return false;
    }

    return true;
}

template <typename Container>
void ContainerOperations::printContainer(const Container& container) {
    // ���������� auto ��� ���������, ��� ��� ��� ��������� ������� �� ����������
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

bool ContainerOperations::insertBeforeFifthFromEnd(std::list<int>& list, const std::deque<int>& deque) {
    if (list.size() < 5 || deque.size() < 5) {
        std::cerr << "������: ���������� ������ ��������� ������� 5 ���������." << std::endl;
        return false;
    }

    try {
        // ������� ������� ��� ������� (5-� ������� � �����)
        auto it = list.end();
        for (int i = 0; i < 5; ++i) {
            --it;
        }

        // ��������� �������� �� ���� � �������� �������
        list.insert(it, deque.rbegin(), deque.rbegin() + 5);
    }
    catch (...) {
        std::cerr << "������ ��� ���������� �������." << std::endl;
        return false;
    }

    return true;
}

// ����� ������������ �������� ��� ��������� ���������� ����������
template bool ContainerOperations::inputContainer<std::deque<int>>(std::deque<int>&, int);
template bool ContainerOperations::inputContainer<std::list<int>>(std::list<int>&, int);
template void ContainerOperations::printContainer<std::deque<int>>(const std::deque<int>&);
template void ContainerOperations::printContainer<std::list<int>>(const std::list<int>&);