#include "BitcoinExchange.hpp"
#include <regex>

bool isValidDate(const std::string &date) {
    std::regex datePattern(R"(\d{4}-\d{2}-\d{2}\s*)");
    if (!std::regex_match(date, datePattern)) {
        return false;
    }
    std::istringstream ss(date);
    int year, month, day;
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;
    if (dash1 != '-' || dash2 != '-' || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input file>" << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    try {
        btc.loadDatabase("data.csv");
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream ss(line);
        std::string date, valueStr;
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            try {
                float value = std::stof(valueStr);
                if (value < 0 || value > 1000) {
                    std::cerr << "Error: value out of range." << std::endl;
                    continue;
                }
                if (!isValidDate(date)) {
                    std::cerr << "Error: invalid date." << std::endl;
                    continue;
                }
                float result = btc.getValue(date, value);
                std::cout << date << " => " << value << " = " << result << std::endl;
            } catch (const std::exception &e) {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        } else {
            std::cerr << "Error: bad input => " << line << std::endl;
        }
    }

    inputFile.close();
    return 0;
}