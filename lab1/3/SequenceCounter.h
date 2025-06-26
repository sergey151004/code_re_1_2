/**
 * @file SequenceCounter.h
 * @brief ������������ ���� ��� �������� K-����� ����� ��� ���� ������ ������ �����
 */

#pragma once

 /**
  * @class SequenceCounter
  * @brief ����� ��� �������� �������� �������������������
  */
class SequenceCounter {
public:
    /**
     * @brief ������������ ���������� K-����� ����� �� N �������� ��� ���� ������ ������ �����
     * @param n ���������� ��������
     * @param k ��������� ������� ���������
     * @return ���������� �������� �����
     * @throws std::invalid_argument ���� ������� ������ ���������
     */
    static double countValidSequences(int n, int k);
};