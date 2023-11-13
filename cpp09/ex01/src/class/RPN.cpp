//
// Created by Jean-Rene Vigneault on 2023-11-11.
//

#include "../include/RPN.hpp"


/*-------Exceptions---------*/

CustomException::CustomException(ErrorMessages errorType)
	: std::runtime_error(getErrorMessage(errorType)) {
}

std::string CustomException::getErrorMessage(ErrorMessages errorType) {
	switch (errorType) {
	case RPN_ERROR_INSUFFICIENT_OPERANDS:
		return "Error: insufficient operands to use all operators";
	case RPN_ERROR_DIVISION_BY_ZERO:
		return "Error: division by zero is impossible. Check the order of the operands";
	case RPN_ERROR_INVALID_INPUT:
		return "Error: invalid input be sure to respect the format (operands = [number] operator = [\"+ - * / \"])";
	case RPN_ERROR_INSUFFICIENT_OPERATORS:
		return "Error: insufficient operators to use all operands";
	default:
		return "Unknown error";
	}
}


/*--------Utlis-----------*/

struct IsDigit {
    bool operator()(char c) const {
        return std::isdigit(c);
    }
};

struct IsOperator {
    bool operator()(char c) const {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }
};

bool Utils::isValidOperand(const std::string& str) {
    return std::all_of(str.begin(), str.end(), IsDigit());
}

bool Utils::isValidOperator(const std::string& str) {
    return str.size() == 1 && IsOperator()(str[0]);
}

bool Utils::isValidOperandOrValidOperator(const std::string& str) {
    return isValidOperand(str) || isValidOperator(str);
}


/*-------Coplien Form---------*/

RPN::RPN() {
}

RPN::~RPN() {
}

RPN::RPN(std::stack<double> operands) {
	this->operands = operands;
}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &rhs) {
	this->operands = rhs.operands;
	return (*this);
}


/*------Calculation-------*/

void RPN::RPNCalculator(std::string input) {
    try {
        std::istringstream stream(input);
        std::string token;

        while (stream >> token) {
            if (!Utils::isValidOperandOrValidOperator(token)) {
                throw CustomException(CustomException::RPN_ERROR_INVALID_INPUT);
            }
            if (Utils::isValidOperand(token)) {
                double operand = std::stod(token);
                operands.push(operand);
            } else {
                 if (operands.size() < 2) {
                    throw CustomException(CustomException::RPN_ERROR_INSUFFICIENT_OPERANDS);
                }
                handleOperator(token);
            }
        }

        printResult(input);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void RPN::handleOperator(const std::string& _operator) {
    double operandA;
    double operandB;

    operandB = operands.top();
    operands.pop();
    operandA = operands.top();
    operands.pop();

    if (_operator == "+") {
        operands.push(operandA + operandB);
    } else if (_operator == "-") {
        operands.push(operandA - operandB);
    } else if (_operator == "*") {
        operands.push(operandA * operandB);
    } else if (_operator == "/") {
        if (operandB == 0) {
            throw CustomException(CustomException::RPN_ERROR_DIVISION_BY_ZERO);
        } else {
            operands.push(operandA / operandB);
        }
    }
}

void RPN::printResult(const std::string& input) {
    operands.size() == 1 ? std::cout << "The result for \"" << input << "\" is : " << operands.top() << std::endl
        : throw CustomException(CustomException::RPN_ERROR_INSUFFICIENT_OPERATORS);
}
