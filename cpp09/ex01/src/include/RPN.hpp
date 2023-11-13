#pragma once

#include <iostream>
#include <stack>
#include <sstream>
#include <algorithm>
#include <cctype>

class RPN {
    public:
        RPN();
        RPN(std::stack<double> operands);
        RPN(const RPN &other);
        ~RPN();
        RPN &operator=(const RPN &rhs);

        void RPNCalculator(std::string input);

    private:
        std::stack<double> operands;

        void handleOperator(const std::string& _operator);
        void printResult(const std::string& input);
};

class CustomException : public std::runtime_error {
    public:
        enum ErrorMessages {
            RPN_ERROR_DIVISION_BY_ZERO,
            RPN_ERROR_INSUFFICIENT_OPERANDS,
            RPN_ERROR_INSUFFICIENT_OPERATORS,
            RPN_ERROR_INVALID_INPUT
        };

        CustomException(ErrorMessages errorType);

    private:
        static std::string getErrorMessage(ErrorMessages errorType);
};

class Utils {
    public:
        static bool isValidOperand(const std::string& str);
        static bool isValidOperator(const std::string& str);
        static bool isValidOperandOrValidOperator(const std::string& str);
};