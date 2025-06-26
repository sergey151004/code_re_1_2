/**
 * @file main.cpp
 * @brief ������� ��������� ��� ������ ������ ����������
 *
 * ������: �������� ����� N ���������� � ���������� ������ (ci) � �������� (di).
 * ���������� ������� ������������ ����������, ��� ��������� ��� �� ��������� B ��,
 * �� ����������� ������ � B, ��� ���� ���������� ������ ���������� ������ ���� ������������.
 * ������� ������������. ��������� ������� ������ ��������� ����������, �� ��������� ��� � �����.
 * ������� ������ ������� �� ���������� �����, ��� ������ ������ �������� N � B,
 * ������ ������ - ���� ����������, ������ - �� ������.
 */

#include "Artifact.h"
#include <iostream>
#include <string>

int main() {
    setlocale(LC_ALL, "Russian");
    std::vector<int> selectedIndices;
    int totalWeight = 0;
    int totalVolume = 0;

    const std::string filename = "f.txt";

    if (!processArtifacts(filename, selectedIndices, totalWeight, totalVolume)) {
        return 1;
    }

    std::cout << "������ ��������� ����������: ";
    for (size_t i = 0; i < selectedIndices.size(); ++i) {
        std::cout << selectedIndices[i] + 1;  // +1 ��� �������� � 1-����������
        if (i != selectedIndices.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\n";

    std::cout << "��������� ���: " << totalWeight << " ��\n";
    std::cout << "��������� �����: " << totalVolume << " ���.��\n";

    return 0;
}