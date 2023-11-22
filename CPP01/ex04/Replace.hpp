#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>

# define RED "\033[1;31m"
# define NONE "\033[0m"

std::string	get_outfile_name(std::string infile_name);
std::string	replace_in_string(std::string line, std::string word_to_replace, std::string new_word);
void		write_in_outfile(std::ifstream &infile, std::ofstream &outfile, std::string to_replace, std::string new_word);

#endif