/**
 * @file TurtlePath.h
 * @brief ������������ ���� ��� ������� ������ � ���������.
 *
 * ������: ��������� �� ���������� ����� � ������� ������ ��������� �� ������� �������� ����
 * � ����� ������, �������� ������ ����� ��� ����, ������� ������������ ����� �����.
 */

#ifndef TURTLEPATH_H
#define TURTLEPATH_H

#include <vector>
#include <string>

 /**
  * @brief ������ ������ ����� �� �����.
  * @param filename ��� ����� � �������.
  * @param rows ���������� ����� � ����� (�������� ��������).
  * @param cols ���������� �������� � ����� (�������� ��������).
  * @return ������ ��������, �������������� �����.
  * @throws std::runtime_error ���� ���� �� ����� ���� ������ ��� ������ �����������.
  */
std::vector<std::vector<int>> readBoardFromFile(const std::string& filename, int& rows, int& cols);

/**
 * @brief ������ ������ ����� � ����������.
 * @param rows ���������� ����� � ����� (�������� ��������).
 * @param cols ���������� �������� � ����� (�������� ��������).
 * @return ������ ��������, �������������� �����.
 * @throws std::runtime_error ���� ���� �����������.
 */
std::vector<std::vector<int>> readBoardFromKeyboard(int& rows, int& cols);

/**
 * @brief ���������� ��������� �����.
 * @param rows ���������� ����� � ����� (�������� ��������).
 * @param cols ���������� �������� � ����� (�������� ��������).
 * @return ������ ��������, �������������� �����.
 * @throws std::runtime_error ���� ������� ����� �����������.
 */
std::vector<std::vector<int>> generateRandomBoard(int& rows, int& cols);

/**
 * @brief ��������� ������������ ����� ����� �� ���� ���������.
 * @param board ����� � �������.
 * @param rows ���������� ����� � �����.
 * @param cols ���������� �������� � �����.
 * @return ������������ ����� ����� �� ����.
 * @throws std::runtime_error ���� ����� ����� ��� ������� �����������.
 */
int calculateMaxPathSum(const std::vector<std::vector<int>>& board, int rows, int cols);

/**
 * @brief ������� ����� � �������.
 * @param board ����� ��� ������.
 */
void printBoard(const std::vector<std::vector<int>>& board);

#endif // TURTLEPATH_H