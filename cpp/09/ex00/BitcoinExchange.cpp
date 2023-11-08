#include "BitcoinExchange.hpp"

int	getYear(std::string date)
{
	return (atoi(date.substr(0, 4).c_str()));
}

int	getMonth(std::string date)
{
	return (atoi(date.substr(5, 2).c_str()));
}

int	getDay(std::string date)
{
	return (atoi(date.substr(8, 2).c_str()));
}

bool	parseFile(int ac)
{
	std::ifstream	data;

	if (ac != 2)
		std::cout << "Usage : ./btc file" << std::endl;
	data.open("data.csv", std::ios::in);
	if (!data)
	{
		std::cout << "Error opening data file" << std::endl;
		return (false);
	}
	std::string		line;
	std::getline(data, line);
	while (std::getline(data, line))
	{
		if ((!validDate(line.substr(0, 10)) && line != "") || line[10] != ',' || (line != "" && !validPrice(line.substr(11, line.size() - 11))))
		{
			std::cout << "Error : invalid line in data.csv : " << line.substr(0, 10) << std::endl;
			data.close();
			return (false);
		}
	}
	data.close();
	return (true);
}

bool	validPrice(std::string price)
{
	int	comma = 0;
	if (price.length() == 0)
		return (false);
	if (price[0] == '.')
		return (false);
	for (size_t i = 0; i < price.size(); i++)
	{
		if ((price[i] < '0' || price[i] > '9') && price[i] != '.')
		{
			return (false);
		}
		if (price[i] == '.')
			comma++;
	}
	if (atoi(price.c_str()) == 0 && price[0] != '0')
		return (false);
	if (atoi(price.c_str()) < 0)
		return (false);
	return (comma == 1 || comma == 0);
}

bool	validDate(std::string date)
{
	int	year;
	int	month;
	int	day;

	if (date.length() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (date[i] < '0' || date[i] > '9')
			return (false);
	}
	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 2).c_str());
	day = atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return (false);
	if (month == 2)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			if (day < 1 || day > 29)
				return (false);
		}
		else
		{
			if (day < 1 || day > 28)
				return (false);
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day < 1 || day > 30)
			return (false);
	}
	else
	{
		if (day < 1 || day > 31)
			return (false);
	}
	return (true);
}

bool	dateIsBefore(std::string date1, std::string date2)
{
	if (getYear(date1) < getYear(date2))
		return (true);
	if (getYear(date1) > getYear(date2))
		return (false);
	if (getMonth(date1) < getMonth(date2))
		return (true);
	if (getMonth(date1) > getMonth(date2))
		return (false);
	if (getDay(date1) < getDay(date2))
		return (true);
	if (getDay(date1) > getDay(date2))
		return (false);
	return (false);
}

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::ifstream	input, data;
	std::string		line;

	file = filename;
	input.open(filename.c_str(), std::ios::in);
	if (!input)
	{
		std::cout << "Error opening " << file << std::endl;
		return ;
	}

	data.open("data.csv", std::ios::in);
	while (std::getline(data, line))
	{
		if (isdigit(line[0]))
			values[line.substr(0, 10)] = atof(line.substr(11, line.size() - 11).c_str());
	}
	data.close();
	std::getline(input, line);
	while (std::getline(input, line))
	{
		float	value;

		if (line == "")
			continue ;
		if (!validDate(line.substr(0,10)))
			std::cout << "Error: bad input => " << line.substr(0, 10) << std::endl;
		else if (!validPrice(line.substr(13, line.size() - 13)))
		{
			if (line[13] == '-')
				std::cout << "Error: not a positive number" << std::endl;
			else if (strtod(line.substr(13, line.size() - 13).c_str(), NULL) >= 1000)
				std::cout << "Error: too large a number" << std::endl;
			else
				std::cout << "Error: bad value input" << std::endl;
		}
		else
		{
			value = atof(line.substr(13, line.size() - 13).c_str());
			std::cout << line.substr(0, 10) << " => " << value << " = " << convert(line.substr(0, 10), value) << std::endl;;
		}
	}
	input.close();
}


BitcoinExchange	&BitcoinExchange::operator = (const BitcoinExchange &toCopy)
{
	if (this == &toCopy)
		return (*this);
	file = toCopy.file;
	values = toCopy.values;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &toCopy)
{
	(*this) = toCopy;
}

BitcoinExchange::~BitcoinExchange(void)
{
}

float	BitcoinExchange::convert(std::string date, float value)
{
	std::string	closest_date = "0000-00-00";

	if (values.find(date) == values.end())
	{
		for (std::map<std::string, double>::iterator it = values.begin(); it != values.end(); it++)
		{
			if (dateIsBefore(it->first, date) && dateIsBefore(closest_date, it->first))
				closest_date = it->first;
		}
		if (date == "0000-00-00")
			return (0);
		return (value * values[closest_date]);
}
	return (value * values[date]);
}
