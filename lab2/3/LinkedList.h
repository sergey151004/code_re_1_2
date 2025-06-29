/**
 * @file LinkedList.h
 * @brief ������������ ���� ��� ������ ������������ ������.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
     * @brief ���������� �������� ���������� �������� ������.
     * @return �������� ���������� �������� ��� -1, ���� ������ ����.
     */
    int getLastValue() const;

    /**
     * @brief ��������� ������� �������� � ������.
     * @param data �������� ��� ������.
     * @return true, ���� ������� ������, ����� false.
     */
    bool contains(int data) const;

private:
    /**
     * @struct Node
     * @brief ���� ������������ ������.
     */
    struct Node {
        int data;      ///< ������ ����.
        Node* next;    ///< ��������� �� ��������� ����.
    };

    Node* head; ///< ��������� �� ������ ������.

    /**
     * @brief ���������� ��������� �� ��������� ���� ������.
     * @return ��������� �� ��������� ���� ��� nullptr, ���� ������ ����.
     */
    Node* getLastNode() const;
};

#endif // LINKEDLIST_H