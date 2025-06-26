/**
 * @file ExpressionCalculator.h
 * @brief ������������ ���� ��� ���������� �������������� ���������
 */

#pragma once
#include <string>

 /**
  * @class ExpressionCalculator
  * @brief ����� ��� ���������� �������������� ���������
  */
class ExpressionCalculator {
public:
    /**
     * ��������� �������� ��������������� ���������
     *
     * @param expression ������ � ���������� ��� ����������
     * @return ��������� ����������
     * @throws std::invalid_argument ���� ��������� �����������
     */
    static int calculate(const std::string& expression);

private:
    /**
     * ������������ ������� ��������� (����� ��� ��������� � �������)
     *
     * @param str ��������� ���������
     * @return �������� ��������
     * @throws std::invalid_argument ���� ������� �����������
     */
    static int parseElement(const std::string& str);

    /**
     * ������������ ���� (��������� ��� ������� �������)
     *
     * @param str ��������� ���������
     * @return �������� �����
     * @throws std::invalid_argument ���� ���� �����������
     */
    static int parseTerm(const std::string& str);

    /**
     * ��������� ��������� (��������/��������� ������)
     *
     * @param str ��������� ���������
     * @return ��������� ����������
     * @throws std::invalid_argument ���� ��������� �����������
     */
    static int evaluateExpression(const std::string& str);
};