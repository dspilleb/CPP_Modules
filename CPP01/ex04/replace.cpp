/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:40:28 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/22 21:50:31 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Replace.hpp"


std::string get_outfile_name(std::string infile_name)
{
	return (infile_name.append(".replace"));
}

std::string replace_in_string(std::string line, std::string word_to_replace, std::string new_word)
{
	size_t start_of_word;
	size_t word_to_replace_length = word_to_replace.length();

	while (!word_to_replace.empty() && (start_of_word = line.find(word_to_replace)) < std::string::npos)
	{
		line.erase(start_of_word, word_to_replace_length);
		line.insert(start_of_word, new_word);
	}
	return (line);
}

void write_in_outfile(std::ifstream &infile, std::ofstream &outfile, std::string to_replace, std::string new_word)
{
	size_t i = 0;
	std::string line;

	while (std::getline(infile, line))
	{
		if (i++ != 0)
			outfile << "\n";
		outfile << replace_in_string(line, to_replace, new_word);
	}
	return;
}
