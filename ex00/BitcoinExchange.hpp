#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>


class BitcoinExchange {
	private:
		std::map<std::string, float> exchangeRates;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);

		void loadDatabase(const std::string &filename);
		float getValue(const std::string &date, float amount);
};

