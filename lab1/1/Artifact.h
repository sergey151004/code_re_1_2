/**
 * @file Artifact.h
 * @brief ������������ ���� ��� ������ � �����������
 *
 * �������� ��������� �������� � ������� ��� ��������� ������ �� ����������.
 */

#ifndef ARTIFACT_H
#define ARTIFACT_H

#include <vector>
#include <string>

 /**
  * @brief ���������, ����������� ��������
  */
struct Artifact {
    int weight;  ///< ��� ��������� � ��
    int volume;  ///< ����� ��������� � ���.��
};

/**
 * @brief ������������ ������ �� ���������� �� �����
 * @param filename ��� �������� �����
 * @param selectedIndices ������ ��� �������� �������� ��������� ����������
 * @param totalWeight ��������� ��� ��������� ����������
 * @param totalVolume ��������� ����� ��������� ����������
 * @return bool True ���� ��������� ������ �������, false ��� ������
 */
bool processArtifacts(const std::string& filename,
    std::vector<int>& selectedIndices,
    int& totalWeight,
    int& totalVolume);

#endif // ARTIFACT_H