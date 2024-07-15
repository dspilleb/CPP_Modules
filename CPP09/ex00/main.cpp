#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	std::map<std::string, float> data;
	if (ac != 2)
	{
		std::cerr << "Please insert a filename in argument : './btc <filename>' " << std::endl;
		return (-1);
	}
	data = extract_data_csv();
	if (!data.empty())
		read_input_file(av[1], data);
	return (0);
}