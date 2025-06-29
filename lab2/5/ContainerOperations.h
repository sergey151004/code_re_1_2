#ifndef CONTAINER_OPERATIONS_H
#define CONTAINER_OPERATIONS_H

#include <deque>
#include <list>
#include <iostream>

/**
 * @brief ����������� ����� ��� �������� � ������������
 */
class ContainerOperations {
private:
    // ������ �������� ����������� ������
    ContainerOperations() = delete;
    ~ContainerOperations() = delete;

public:
    /**
     * @brief ���������� ���������� �������
     * @param container ��������� ��� ����������
     * @param size ������ ����������
     * @return true ���� �������, false ��� ������
     */
    template <typename Container>
    static bool inputContainer(Container& container, int size);

    /**
     * @brief ����� ����������� ����������
     * @param container ��������� ��� ������
     */
    template <typename Container>
    static void printContainer(const Container& container);

    /**
     * @brief ������� ��������� 5 ��������� ���� ����� 5-� � ����� ��������� ������
     * @param list ������ ��� �����������
     * @param deque ��� � ���������� ��� �������
     * @return true ���� �������, false ��� ������
     */
    static bool insertBeforeFifthFromEnd(std::list<int>& list, const std::deque<int>& deque);
};

#endif // CONTAINER_OPERATIONS_H