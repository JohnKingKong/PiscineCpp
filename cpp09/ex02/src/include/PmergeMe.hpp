#pragma once

#include <iostream>
#include <deque>
#include <list>
#include <ctime>
#include <cstdlib>
#include <sstream>

class PmergeMe {
    public:
        PmergeMe(int inputLength, char *inputArray[]);
        PmergeMe(std::deque<int> inputDeque, std::list<int> inputList);
        PmergeMe(const PmergeMe &other);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &rhs);

        template <typename T>
        void printContainerValues(const T& container, bool firstPrint, bool isDeque);

        void mergeInsertSortDeque(std::deque<int>& inputArray);
        void mergeInsertSortList(std::list<int>& inputArray);

    private:
        void setContainersValues(int inputLength, char *inputArray[]);
        void printResults(double duration1, double duration2);
        void printTimeRange(double duration, bool isDeque);

        std::deque<int> inputDeque;
        std::list<int> inputList;
};


class CustomException : public std::runtime_error {
	public:
		CustomException(const std::string& errorMessage);
};

class Utils {
	public:
		static bool isValidPositiveInteger(const std::string& str);
};