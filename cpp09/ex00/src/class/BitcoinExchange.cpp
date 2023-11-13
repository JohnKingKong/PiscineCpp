//
// Created by Jean-Rene Vigneault on 2023-11-11.
//

#include "../include/BitcoinExchange.hpp"


/*-------Exceptions---------*/

CustomException::CustomException(ErrorMessages errorType, const std::string &line, size_t lineNumber)
    : std::runtime_error(getErrorMessage(errorType) +
            (line.empty() ? "" : line + "\"" +
            (lineNumber >= 0 ? " line: " + std::to_string(lineNumber) + ")." : ""))) {
}


/*--------Utlis-----------*/

std::string CustomException::getErrorMessage(ErrorMessages errorType) {
    switch (errorType)
    {
    case ERROR_ENTRY_DB:
        return "Error: an entry in the database is not formatted correctly (culprit: \"";
    case ERROR_OPEN_DB:
        return "Error: while opening the database file. Be sure to check if it's in the current directory and named \"data.csv\"";
    case ERROR_TITLE_DB:
        return "Error: be sure the database file starts on the first line with \"date,exchange_rate\"";
    case ERROR_OPEN_INPUT:
        return "Error: while opening the input file. Be sure to check the usage (./BitcoinRateCalculator [filename])";
    case ERROR_ENTRY_INPUT:
        return "Error: an entry in the input is not formatted correctly (culprit: \"";
    case ERROR_NEGATIVE_INPUT:
        return "Error: the value is not a postive number (culprit: \"";
    case ERROR_NOT_A_NUMBER_INPUT:
        return "Error: the value is not a valid number (culprit: \"";
    case ERROR_TITLE_INPUT:
        return "Error: be sure the input file starts on the first line with \"date | value\"";
    case ERROR_TOO_BIG_NUMBER_INPUT:
        return "Error: the value is a number too high (culprit: \"";
    case ERROR_USAGE:
        return "Error: wrong usage of the program. Be sure it's correctly formatted (\"./BitcoinRateCalculator [inputFileName]\")";
    default:
        return "Unknown error";
    }
}

std::string& Utils::trimFromStart(std::string& inputString) {
    return inputString.erase(0, inputString.find_first_not_of(" \t\n\r"));
}

std::string& Utils::trimFromEnd(std::string& inputString) {
    return inputString.erase(inputString.find_last_not_of(" \t\n\r") + 1);
}

std::string& Utils::trimString(std::string& inputString) {
    trimFromStart(inputString);
    return trimFromEnd(inputString);
}

struct NotEqualTo {
    char value;

    NotEqualTo(char val) : value(val) {}

    bool operator()(char c) const {
        return c != value;
    }
};


/*-------Coplien Form---------*/

BitcoinRateCalculator::BitcoinRateCalculator() {
    std::string line;
    size_t lineNumber = 1;

        std::ifstream databaseFile("./data.csv");

        if (!databaseFile.is_open()) {
            throw CustomException(CustomException::ERROR_OPEN_DB);
        }

        while (std::getline(databaseFile, line)) {
            processFileLine(line, lineNumber, true);
            lineNumber++;
        }
        databaseFile.close();
}

BitcoinRateCalculator::~BitcoinRateCalculator() {
}

BitcoinRateCalculator &BitcoinRateCalculator::operator=(BitcoinRateCalculator const &rhs) {
	this->exchangeRateValueByDateMap = rhs.exchangeRateValueByDateMap;
	return (*this);
}

BitcoinRateCalculator::BitcoinRateCalculator(BitcoinRateCalculator const &copy) {
	*this = copy;
}


/*---------Getters/Setters---------*/

void BitcoinRateCalculator::setExchangeRateValueByDate(std::string date, float exchangeRateValue) {
	this->exchangeRateValueByDateMap.insert(std::make_pair(date, exchangeRateValue));
}

std::map<std::string, float> BitcoinRateCalculator::getExchangeRateValueByDateMap() {
	return (this->exchangeRateValueByDateMap);
}

std::vector<std::string> BitcoinRateCalculator::setVectorInputValues(const std::string& value, char delimiter) {
    std::vector<std::string> inputValuesVector;

    std::string::const_iterator start = value.begin();
    std::string::const_iterator end = value.begin();

    while (end != value.end()) {
        end = std::find(start, value.end(), delimiter);
        inputValuesVector.push_back(std::string(start, end));
        start = std::find_if(end, value.end(), NotEqualTo(delimiter));
        end = start;
    }

    return inputValuesVector;
}


/*------------File Handling---------*/

void BitcoinRateCalculator::checkFileTitleLine(const std::string& line, bool isDatabaseFile) {
    try {
        if (isDatabaseFile && line != "date,exchange_rate") {
            throw CustomException(CustomException::ERROR_TITLE_DB);
        } else if (!isDatabaseFile && line != "date | value") {
            throw CustomException(CustomException::ERROR_TITLE_INPUT);
        }
    } catch (const CustomException& exception) {
        std::cerr << exception.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

void BitcoinRateCalculator::processFileLine(const std::string& line, size_t lineNumber, bool isDatabaseFile) {
    try {
        if (lineNumber == 1) {
            checkFileTitleLine(line, isDatabaseFile);
            return;
        }
        isDatabaseFile ? parseAndValidateDatabaseFileValues(line, lineNumber) : parseAndValidateInputFileValues(line, lineNumber);
    } catch (const CustomException& exception) {
        std::cerr << exception.what() << std::endl;
    }
}

void BitcoinRateCalculator::processInputFile(std::string filename) {
    std::string line;
    size_t lineNumber = 1;

    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        throw CustomException(CustomException::ERROR_OPEN_INPUT);
    }

    while (std::getline(inputFile, line)) {
        processFileLine(line, lineNumber, false);
        lineNumber++;
    }
    inputFile.close();
}

void BitcoinRateCalculator::parseAndValidateDatabaseFileValues(const std::string& line, size_t lineNumber) {
    std::string date;
    size_t commaPosition;
    double exchangeRateValue;

    commaPosition = line.find(',');

    if (commaPosition == std::string::npos) {
        throw CustomException(CustomException::ERROR_ENTRY_DB, line, lineNumber);
        std::exit(EXIT_FAILURE);
    } else {
        date = line.substr(0, commaPosition);
        try {
            exchangeRateValue = std::stod(line.substr(commaPosition + 1));
        } catch(const std::exception &exception) {
            throw CustomException(CustomException::ERROR_ENTRY_DB, line, lineNumber);
            std::exit(EXIT_FAILURE);
        }
    }

    this->setExchangeRateValueByDate(date, exchangeRateValue);

}

void BitcoinRateCalculator::parseAndValidateInputFileValues(const std::string& line, size_t lineNumber) {
    float inputValue;
    std::pair<std::string, float> pair;
    std::map<std::string, float>::iterator iterator;
    std::vector<std::string> vectorInputValue = setVectorInputValues(line, '|');
    
    if (vectorInputValue[0].empty() || vectorInputValue.size() != 2) {
        throw CustomException(CustomException::ERROR_ENTRY_INPUT, line, lineNumber);
    }

    iterator = exchangeRateValueByDateMap.upper_bound(Utils::trimString(vectorInputValue[0]));

    if (iterator == exchangeRateValueByDateMap.begin()) {
        std::cerr << "Warning: Input date is earlier than any date in the database. Using the earliest available date." << std::endl;
        pair = *exchangeRateValueByDateMap.begin();
    } else {
        std::string inputDate = Utils::trimString(vectorInputValue[0]);
        iterator = exchangeRateValueByDateMap.begin();
        while (iterator != exchangeRateValueByDateMap.end() && iterator->first < inputDate) {
            ++iterator;
        }

        if (iterator == exchangeRateValueByDateMap.end()) {
            --iterator;
            std::cerr << "Warning: Input date is beyond the latest date in the database. Using the latest available date." << std::endl;
        } else {
            --iterator;
        }

        pair = *iterator;
    }

    try {
        inputValue = std::stof(vectorInputValue[1]);

        if (inputValue > 1000) {
            throw CustomException(CustomException::ERROR_TOO_BIG_NUMBER_INPUT, line, lineNumber);
        }
        if (inputValue < 0) {
            throw CustomException(CustomException::ERROR_NEGATIVE_INPUT, line, lineNumber);
        }

        std::cout << "For the date: " << vectorInputValue[0] << ", with an exchange rate of" << vectorInputValue[1];
        std::cout << ", for " << pair.second << " bitcoin, the result is: " << inputValue * pair.second << std::endl;
    } catch (const std::invalid_argument& e) {
        throw CustomException(CustomException::ERROR_NOT_A_NUMBER_INPUT, line, lineNumber);
    }


}

