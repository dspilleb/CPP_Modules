/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:28:54 by dspilleb          #+#    #+#             */
/*   Updated: 2024/10/05 11:55:29 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    {
        std::cout << "\n*-*-*-*-*-* Constructor Throw test *-*-*-*-*-*\n";
        try
        {
            Form Dan = Form("ConstructorThrow", 0, 1);
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
            Form Dan = Form("ConstructorThrow", 1, 151);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        std::cout << "\n*-*-*-*-*-* Sign Form Throw test *-*-*-*-*-*\n";
        Form Bocal = Form("BocalReview", 10, 10);
        Bureaucrat Member = Bureaucrat("19 member", 11);
        std::cout << Bocal << "\n" << Member << std::endl;
        Member.signForm(Bocal);
        std::cout << Bocal << std::endl;
    }
    {
        std::cout << "\n*-*-*-*-*-* Sign Form Success test *-*-*-*-*-*\n";
        Form Bocal = Form("BocalReview", 10, 10);
        Bureaucrat Member = Bureaucrat("19 member", 10);
        std::cout << Bocal << "\n" << Member << std::endl;
        Member.signForm(Bocal);
        std::cout << Bocal << std::endl;
    }

    return 0;
}