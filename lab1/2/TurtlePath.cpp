#include "TurtlePath.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

std::vector<std::vector<int>> readBoardFromFile(const std::string& filename, int& rows, int& cols) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cerr << "������: �� ������� ������� ���� " << filename << std::endl;
        throw std::runtime_error("�� ������� ������� ����");
    }

    input >> rows >> cols;
    if (rows <= 0 || cols <= 0 || rows > 80 || cols > 80) {
        std::cerr << "������: ������������ ������� �����" << std::endl;
        throw std::runtime_error("������������ ������� �����");
    }

    std::vector<std::vector<int>> board(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(input >> board[i][j])) {
                std::cerr << "������: ������������ ������ � �����" << std::endl;
                throw std::runtime_error("������������ ������");
            }
            if (board[i][j] < 0 || board[i][j] > 100) {
                std::cerr << "������: ����� ��� ����������� ��������� [0, 100]" << std::endl;
                throw std::runtime_error("������������ ������");
            }
        }
    }
    input.close();
    return board;
}

std::vector<std::vector<int>> readBoardFromKeyboard(int& rows, int& cols) {
    std::cout << "������� ���������� ����� � �������� (1 < N < 80): ";
    std::cin >> rows >> cols;

    if (rows <= 0 || cols <= 0 || rows > 80 || cols > 80) {
        std::cerr << "������: ������������ ������� �����" << std::endl;
        throw std::runtime_error("������������ ������� �����");
    }

    std::vector<std::vector<int>> board(rows, std::vector<int>(cols));
    std::cout << "������� �������� ����� (�� �������):" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            while (!(std::cin >> board[i][j]) || board[i][j] < 0 || board[i][j] > 100) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cerr << "������: ������� ����� ����� �� 0 �� 100: ";
            }
        }
    }
    return board;
}

std::vector<std::vector<int>> generateRandomBoard(int& rows, int& cols) {
    std::cout << "������� ���������� ����� � �������� (1 < N < 80): ";
    std::cin >> rows >> cols;

    if (rows <= 0 || cols <= 0 || rows > 80 || cols > 80) {
        std::cerr << "������: ������������ ������� �����" << std::endl;
        throw std::runtime_error("������������ ������� �����");
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<std::vector<int>> board(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = std::rand() % 101;
        }
    }
    return board;
}

int calculateMaxPathSum(const std::vector<std::vector<int>>& board, int rows, int cols) {
    if (board.empty() || board[0].empty()) {
        std::cerr << "������: ������ �����" << std::endl;
        throw std::runtime_error("������ �����");
    }

    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));
    dp[0][cols - 1] = board[0][cols - 1];

    for (int j = cols - 2; j >= 0; --j) {
        dp[0][j] = dp[0][j + 1] + board[0][j];
    }

    for (int i = 1; i < rows; ++i) {
        dp[i][cols - 1] = dp[i - 1][cols - 1] + board[i][cols - 1];
    }

    for (int i = 1; i < rows; ++i) {
        for (int j = cols - 2; j >= 0; --j) {
            dp[i][j] = board[i][j] + std::max(dp[i - 1][j], dp[i][j + 1]);
        }
    }

    return dp[rows - 1][0];
}

void printBoard(const std::vector<std::vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}