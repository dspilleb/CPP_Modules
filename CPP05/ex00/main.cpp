/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:54 by dspilleb          #+#    #+#             */
/*   Updated: 2024/10/05 11:30:00 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    {
        std::cout << "\n*-*-*-*-*-* Constructor Throw test *-*-*-*-*-*\n";
        try
        {
            Bureaucrat Dan = Bureaucrat("ConstructorThrow", 0);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n*-*-*-*-*-* Constructor Throw test *-*-*-*-*-*\n";
        try
        {
            Bureaucrat Dan = Bureaucrat("ConstructorThrow", 151);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n*-*-*-*-*-* Increment Throw test *-*-*-*-*-*\n";
        Bureaucrat Dan = Bureaucrat("IncrementThrow", 1);
        std::cout << Dan << std::endl;
        try
        {
            std::cout << "- Increment\n";
            Dan.increment();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    {
        std::cout << "\n*-*-*-*-*-* Decrement Throw test *-*-*-*-*-*\n";
        Bureaucrat Dan = Bureaucrat("DecrementThrow", 150);
        std::cout << Dan << std::endl;
        try
        {
            std::cout << "- Decrement\n";
            Dan.decrement();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::cout << "\n*-*-*-*-*-* No Throw test *-*-*-*-*-*\n";
        Bureaucrat Dan = Bureaucrat("DecrementThrow", 150);
        std::cout << Dan << std::endl;
        Dan.increment();
        std::cout << "- Increment\n";
        std::cout << Dan << std::endl;
    }

    return 0;
}