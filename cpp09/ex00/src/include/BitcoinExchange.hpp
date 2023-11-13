//
// Created by Jean-Rene Vigneault on 2023-11-11.
//

#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>


class BitcoinRateCalculator {
    public:
    /*-------Coplien Form-------*/
        BitcoinRateCalculator();
        ~BitcoinRateCalculator();
        BitcoinRateCalculator& operator=(BitcoinRateCalculator const &var);
        BitcoinRateCalculator(BitcoinRateCalculator const &var);

    /*------Getters/Setters*/
        void setExchangeRateValueByDate(std::string date, float exchangeRateValue);
        std::map<std::string, float> getExchangeRateValueByDateMap();
        std::vector<std::string> setVectorInputValues(const std::string& value, char delimiter);

    /*--------File Handling-------*/
        void processInputFile(std::string inputPath);

    private:
        std::map <std::string, float> exchangeRateValueByDateMap;

    /*--------File Handling-------*/
        void processFileLine(const std::string& line, size_t lineNumber, bool isDatabaseFile);
        void checkFileTitleLine(const std::string& line, bool isDatabaseFile);
        void parseAndValidateDatabaseFileValues(const std::string& line, size_t lineNumber);
        void parseAndValidateInputFileValues(const std::string& line, size_t lineNumber);
};

class CustomException : public std::runtime_error {
    public:
        enum ErrorMessages
        {
            ERROR_ENTRY_DB,
            ERROR_OPEN_DB,
            ERROR_TITLE_DB,
            ERROR_ENTRY_INPUT,
            ERROR_OPEN_INPUT,
            ERROR_NEGATIVE_INPUT,
            ERROR_NOT_A_NUMBER_INPUT,
            ERROR_TITLE_INPUT,
            ERROR_TOO_BIG_NUMBER_INPUT,
            ERROR_USAGE,
            WARNING_DATE_TOO_HIGH,
            WARNING_DATE_TOO_LOW
        };

        CustomException(ErrorMessages errorType, const std::string &line = "", size_t lineNumber = -1);

    private:
        static std::string getErrorMessage(ErrorMessages errorType);
};

class Utils {
    public:
        static std::string& trimFromStart(std::string& inputString);
        static std::string& trimFromEnd(std::string& inputString);
        static std::string& trimString(std::string& inputString);
};