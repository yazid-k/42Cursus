#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <map>
#include <limits>

class BitcoinExchange
{
private:
	std::string	file;
	std::map<std::string, double>	values;

public:
	BitcoinExchange(void);
	BitcoinExchange(std::string filename);
	BitcoinExchange(const BitcoinExchange &toCopy);
	BitcoinExchange	&operator = (const BitcoinExchange &toCopy);
	~BitcoinExchange(void);
	float	convert(std::string date, float value);
};

bool	validDate(std::string date);
bool	validPrice(std::string price);
bool	parseFile(int ac);
#endif
