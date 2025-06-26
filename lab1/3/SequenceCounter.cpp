#include "SequenceCounter.h"
#include <stdexcept>

/**
 * @brief ������������ ���������� K-����� ����� �� N �������� ��� ���� ������ ������ �����
 * @param n ���������� ��������
 * @param k ��������� ������� ���������
 * @return ���������� �������� �����
 * @throws std::invalid_argument ���� ������� ������ ���������
 */
double SequenceCounter::countValidSequences(int n, int k) {
    // �������� ������� ������
    if (k < 2 || k > 10) {
        throw std::invalid_argument("��������� ������� ��������� K ������ ���� � ��������� [2, 10]");
    }
    if (n <= 1 || n >= 20) {
        throw std::invalid_argument("���������� �������� N ������ ���� � ��������� (1, 20)");
    }
    if (k + n >= 26) {
        throw std::invalid_argument("����� K + N ������ ���� ������ 26");
    }

    // nz = ����� ��� ���� ������ ������ �����, �� �������������� �� 0
    // oz = ����� ��� ���� ������ ������ �����, �������������� �� 0
    // tz = ����� � ����� ������ ������� ������
    double nz = k - 1;  // ������ ����� ����� ���� �����, ����� 0
    double oz = 1;       // ������ ����� "0"
    double tz = 0;       // ���������� ��� 1-��������� �����

    for (int i = 2; i <= n; ++i) {
        double prev_nz = nz;
        double prev_oz = oz;
        double prev_tz = tz;

        nz = prev_nz * (k - 1) + prev_oz * (k - 1);
        oz = prev_nz;
        tz = prev_tz * k + prev_oz;
    }

    return nz + oz;
}