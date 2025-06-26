#include "ExpressionCalculator.h"
#include <stdexcept>
#include <string>

using namespace std;

int ExpressionCalculator::calculate(const std::string& expression) {
    if (expression.empty()) {
        throw invalid_argument("Пустое выражение");
    }
    return evaluateExpression(expression);
}

int ExpressionCalculator::parseElement(const std::string& str) {
    if (str.empty()) {
        throw invalid_argument("Пустой элемент");
    }

    if (str[0] == '(' && str[str.size() - 1] == ')') {
        return evaluateExpression(str.substr(1, str.size() - 2));
    }

    try {
        return stoi(str);
    }
    catch (const exception&) {
        throw invalid_argument("Некорректное число: " + str);
    }
}

int ExpressionCalculator::parseTerm(const std::string& str) {
    if (str.empty()) {
        throw invalid_argument("Пустой терм");
    }

    int level = 0;
    int pos = -1;

    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] == ')') level += 1;
        if (str[i] == '(') level -= 1;

        if (level == 0 && str[i] == '*') {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        return parseElement(str);
    }

    string leftPart = str.substr(0, pos);
    string rightPart = str.substr(pos + 1);

    if (leftPart.empty() || rightPart.empty()) {
        throw invalid_argument("Некорректное умножение");
    }

    return parseTerm(leftPart) * parseElement(rightPart);
}

int ExpressionCalculator::evaluateExpression(const std::string& str) {
    if (str.empty()) {
        throw invalid_argument("Пустое выражение");
    }

    int level = 0;
    int pos = -1;
    char op = '\0';

    for (int i = str.size() - 1; i >= 0; --i) {
        if (str[i] == ')') level += 1;
        if (str[i] == '(') level -= 1;

        if (level == 0 && (str[i] == '+' || str[i] == '-')) {
            pos = i;
            op = str[i];
            break;
        }
    }

    if (pos == -1) {
        return parseTerm(str);
    }

    string leftPart = str.substr(0, pos);
    string rightPart = str.substr(pos + 1);

    if (leftPart.empty() || rightPart.empty()) {
        throw invalid_argument("Некорректная операция");
    }

    int leftValue = evaluateExpression(leftPart);
    int rightValue = parseTerm(rightPart);

    return (op == '+') ? leftValue + rightValue : leftValue - rightValue;
}