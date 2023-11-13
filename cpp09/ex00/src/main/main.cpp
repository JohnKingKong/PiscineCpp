//
// Created by Jean-Rene Vigneault on 2023-11-11.
//

#include "../include/BitcoinExchange.hpp"

int main(int ac , char *av[])
{
    try {
        if (ac != 2) {
            throw CustomException(CustomException::ERROR_USAGE);
        }

        BitcoinRateCalculator bitcoinRateCalculator;

        bitcoinRateCalculator.processInputFile(av[1]);
    
    } catch (const std::exception &exception) {
        std::cerr << exception.what() << std::endl;
    }
}
