#include "../include/PmergeMe.hpp"

/*-------Exception--------*/

CustomException::CustomException(const std::string& errorMessage)
    : std::runtime_error(errorMessage) {     
}


/*----------Utils-----------*/

struct IsDigit {
    bool operator()(char c) const {
        return std::isdigit(c);
    }
};

bool Utils::isValidPositiveInteger(const std::string& str) {
    return std::all_of(str.begin(), str.end(), IsDigit());
}


/*---------Printing Utils----------*/

template <typename T>
void PmergeMe::printContainerValues(const T& container, bool firstPrint, bool isDeque) {
    typename T::const_iterator _iterator;

    isDeque ? std::cout << "*[std::deque]*  " : std::cout << "*[std::list]*   ";
    firstPrint ? std::cout << "Input array before: " : std::cout << "Input array after: ";
    for (_iterator = container.begin(); _iterator != container.end(); ++_iterator)
        std::cout << *_iterator << " ";
    std::cout << std::endl;
}

void PmergeMe::printTimeRange(double duration, bool isDeque) {
    isDeque ? std::cout << "*[std::deque]*  " : std::cout << "*[std::list]*   ";
    std::cout << "Time to process a range of " << (isDeque ? inputDeque.size() : inputList.size());
    std::cout << " elements : " << duration << " us" << std::endl;
}

void PmergeMe::printResults(double duration1, double duration2) {
    printContainerValues(inputDeque, false, true);
    printContainerValues(inputList, false, false);
    printTimeRange(duration1, true);
    printTimeRange(duration2, false);
}


/*---------Coplien Form--------*/

PmergeMe::PmergeMe(int inputLength, char *inputArray[]) {
    clock_t start1;
    clock_t start2;
    clock_t end1;
    clock_t end2;
    double duration1;
    double duration2;

    try {
        setContainersValues(inputLength, inputArray);
        printContainerValues(inputDeque, true, true);
        printContainerValues(inputList, true, false);

        start1 = clock();
        mergeInsertSortDeque(inputDeque);
        end1 = clock();
        duration1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000;

        start2 = clock();
        mergeInsertSortList(inputList);
        end2 = clock();
        duration2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC * 1000;

        printResults(duration1, duration2);
    } catch (const CustomException &e) {
        std::cerr << e.what() << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

PmergeMe::PmergeMe(std::deque<int> inputDeque, std::list<int> inputList) {
    this->inputDeque = inputDeque;
    this->inputList = inputList;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &rhs) {
    this->inputDeque = rhs.inputDeque;
    this->inputList = rhs.inputList;
    return (*this);
}

PmergeMe::~PmergeMe() {
}


/*---------Merge-insert Sort-------*/

void PmergeMe::mergeInsertSortDeque(std::deque<int>& inputArray) {
    std::deque<int>::iterator _iterator1, _iterator2;

    for (_iterator1 = inputArray.begin() + 1; _iterator1 != inputArray.end(); ++_iterator1) {
        int temp = *_iterator1;
        _iterator2 = _iterator1;

        while (_iterator2 != inputArray.begin() && *(std::prev(_iterator2)) > temp) {
            *_iterator2 = *(std::prev(_iterator2));
            std::advance(_iterator2, -1);
        }
        *_iterator2 = temp;
    }
}

void PmergeMe::mergeInsertSortList(std::list<int>& inputArray) {
    std::list<int>::iterator _iterator1, _iterator2;

    for (_iterator1 = ++inputArray.begin(); _iterator1 != inputArray.end(); ++_iterator1) {
        int temp = *_iterator1;
        _iterator2 = _iterator1;

        while (_iterator2 != inputArray.begin() && *(std::prev(_iterator2)) > temp) {
            *_iterator2 = *(std::prev(_iterator2));
            std::advance(_iterator2, -1);
        }
        *_iterator2 = temp;
    }
}


/*-------Setter-------*/

void PmergeMe::setContainersValues(int inputLength, char *inputArray[]) {
    srand(time(NULL));

    for (int i = 1; i < inputLength; ++i) {
        std::istringstream inputStream(inputArray[i]);
        int value;

        if (!(inputStream >> value) || inputStream.rdbuf()->in_avail() != 0) {
            throw CustomException("Error: Invalid input value \"" + std::string(inputArray[i]) + "\". Only positive integers are allowed.");
        }

        inputDeque.push_back(value);
        inputList.push_back(value);
    }
}

