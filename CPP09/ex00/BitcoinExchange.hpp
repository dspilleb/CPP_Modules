#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

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


void print_closest_date_value(std::string date, float amount, std::map<std::string, float> input);
std::map<std::string, float> extract_data_csv(void);
void read_input_file(std::string filename, std::map<std::string, float> data);

#endif