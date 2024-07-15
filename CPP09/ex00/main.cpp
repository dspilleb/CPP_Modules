# include <iostream>
# include <string>
# include <map>
# include <iterator>
# include <fstream>
# include <limits>
# include <cmath>

#define ERR_FILE "Error: could not open file."
#define ERR_NEG "Error: not a positive number."
#define ERR_DATE "Error: date is not valid."
#define ERR_LARGE "Error: too large a number."
#define ERR_FORMAT "Error: bad input => "
#define CSV_EMPTY "Error: CSV file is empty."
#define FILENAME "data.csv"
#define CSV_FORMAT "Error: bad CSV line => "

void print_closest_date_value(std::string date, float amount, std::map<std::string, float> input)
{
	std::map<std::string, float>::key_compare my_comp = input.key_comp();
	std::map<std::string, float>::iterator it = input.begin();
	std::map<std::string, float>::iterator ite = input.end();
	float value = (*it).second;
	if (input.empty())
		std::cerr << CSV_EMPTY << std::endl;
	while (it != ite && !my_comp(date, (*it).first))
	{
		value = (*it).second;
		it++;
	}
	std::cout << date << " => " << amount << " = " << value * amount << std::endl;
}

std::map<std::string, float> extract_data_csv(void)
{
	std::ifstream csv_infile;
	std::map<std::string, float> ret;
	std::string line;
	std::string date;
	std::string string_of_value;
	size_t pos;

	csv_infile.open(FILENAME, std::ifstream::in);
	if (!csv_infile.is_open() || !csv_infile.good())
	{
		std::cerr << ERR_FILE << std::endl;
		return (ret);
	}
	std::getline(csv_infile, line); // skip first line of file
	while (std::getline(csv_infile, line))
	{
		pos = line.find(",");
		if (pos == std::string::npos)
		{
			std::cerr << CSV_FORMAT << line << std::endl;
			return (ret);
		}
		date = line.substr(0, pos);
		string_of_value = line.substr(pos + 1, line.size());
		if (date.empty() || string_of_value.empty())
			std::cerr << CSV_FORMAT << line << std::endl;
		else
			ret[date] = atof(string_of_value.c_str());
	}
	return (ret);
}

bool is_date_valid(std::string date)
{
	long year, month, day;
	bool valid;
	if (sscanf(date.c_str(),"%ld-%ld-%ld", &year, &month, &day) != 3)
		return (false);
	valid = (year > 0 && (month > 0 && month <= 12) && (day > 0 && day <= 31));
	if(!valid)
		std::cerr << ERR_DATE << date << std::endl;
	return (valid);
}

void read_input_file(std::string filename, std::map<std::string, float> data)
{
	std::ifstream input;
	std::string line;
	std::string date;
	float amount;
	size_t pos;

	(void) data;
	input.open(filename.c_str(), std::ifstream::in);
	if (!input.is_open() || !input.good())
	{
		std::cerr << ERR_FILE << std::endl;
		return;
	}
	std::getline(input, line); // skip first line of file
	while (std::getline(input, line))
	{
		pos = line.find("|");
		if (pos == std::string::npos)
		{
			std::cerr << ERR_FORMAT << line << std::endl;
			continue;
		}
		amount = atof((line.substr(pos + 2, line.size())).c_str());
		date = line.substr(0, pos - 1);
		if (amount < 0)
			std::cerr << ERR_NEG << std::endl; 
		else if (static_cast<double>(amount) > static_cast<double>(std::numeric_limits<int>::max()) || std::isinf(amount))
			std::cerr << ERR_LARGE << std::endl;

		else if (is_date_valid(date))
			print_closest_date_value(date, amount, data);
	}
	return;
}

int main(int ac, char **av)
{
	std::map<std::string, float> data;
	if (ac != 2)
		std::cerr << "Please insert a filename in argument : './btc <filename>' " << std::endl;
	else
	{
		data = extract_data_csv();
		if (!data.empty())
			read_input_file(av[1], data);
	}

	return (0);
}