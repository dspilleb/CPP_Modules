/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:13:59 by dspilleb          #+#    #+#             */
/*   Updated: 2023/11/22 21:45:02 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

int	main(int ac, char **av)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	if (ac != 4)
		return (std::cout << RED << "Wrong number of arguments" << std::endl, 1);

	infile.open(av[1], std::ifstream::in);
	if (infile.is_open() && infile.good())
		outfile.open(get_outfile_name(av[1]).c_str(), std::ofstream::out | std::ofstream::trunc);
	if (infile.is_open() && infile.good() && outfile.is_open() && outfile.good())
		write_in_outfile(infile, outfile, av[2], av[3]);
	else
		std::cout << RED << "Error while opening files" << std::endl;

	infile.close();
	outfile.close();
}