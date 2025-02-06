#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Wrong number of arguments" << std::endl;
        return 1;
    }
    try {
        Btc Btc;
        Btc.BtcCheck(argv[1]);
        return 0;
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}

