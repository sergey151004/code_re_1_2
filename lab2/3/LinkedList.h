/**
 * @file LinkedList.h
 * @brief ������������ ���� ��� ������ ������������ ������.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

 /**
  * @class Node
  * @brief ���� ������������ ������.
  */
class Node {
public:
    int data;      ///< ������ ����.
    Node* next;    ///< ��������� �� ��������� ����.
};

/**
 * @class LinkedList
 * @brief ����� ��� ������ � ����������� �������.
 */
class LinkedList {
public:
    LinkedList();
    ~LinkedList();

    /**
     * @brief ��������� ������� � ����� ������.
     * @param data �������� ��������.
     */
    void append(int data);

    /**
     * @brief ��������� �������� ����� ������� ������� ��������.
     * @param value �������� ��� �������.
     */
    void insertAfterEverySecond(int value);

    /**
     * @brief ������� ������� �� ��������.
     * @param data �������� �������� ��� ��������.
     * @return true, ���� �������� ������ �������, ����� false.
     */
    bool remove(int data);

    /**
     * @brief ������� ������ �� �����.
     */
    void display() const;

    /**
     * @brief ���������� ��������� �� ��������� ������� ������.
     * @return ��������� �� ��������� �������.
     */
    Node* getLastNode() const;

    /**
     * @brief ������� ���� �� ��������.
     * @param data �������� ��� ������.
     * @return ��������� �� ��������� ���� ��� nullptr, ���� �� ������.
     */
    Node* find(int data) const;

private:
    Node* head; ///< ��������� �� ������ ������.
};

#endif // LINKEDLIST_H