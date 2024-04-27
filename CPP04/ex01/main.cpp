/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:05:06 by dspilleb          #+#    #+#             */
/*   Updated: 2024/03/28 19:32:33 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
    	std::cout << "\n*-*-*-*-*-*- CHECK_DESTRUCTORS *-*-*-*-*-*-\n " << std::endl;
		int size = 4;
		Animal *arr[size];
		for (int i = 0; i < size; i++)
		{
			if (i % 2 == 0)
				arr[i] = new Cat();
			else
				arr[i] = new Dog();
			std::cout << "------" <<std::endl;
		}
		for (int i = 0; i < size; i++)
		{
			delete arr[i];
			std::cout << "------" <<std::endl;
		}
	}
	{
    	std::cout << "\n*-*-*-*-*-*- CHECK_LEAK *-*-*-*-*-*-\n " << std::endl;
		//check leak
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
    	std::cout << "\n*-*-*-*-*-*- CHECK_DEEPCOPY *-*-*-*-*-*-\n " << std::endl;
		//check deepcopy
		Dog original;
		original.getbrain()->setBrainAtIndex("Oui", 0);
		Dog copy = original;
		std::cout << "*-*-BEFORE*-*-" << std::endl;
		std::cout << "Original brain index 0: " << original.getbrain()->getBrainAtIndex(0) <<  std::endl;
	
		std::cout << "Copy brain index 0: " << copy.getbrain()->getBrainAtIndex(0) <<  std::endl;
	
		original.getbrain()->setBrainAtIndex("Non", 0);
		std::cout << "*-*-AFTER*-*-" << std::endl;
		std::cout << "Original brain index 0: " << original.getbrain()->getBrainAtIndex(0) <<  std::endl;
		std::cout << "Copy brain index 0: " << copy.getbrain()->getBrainAtIndex(0) <<  std::endl;

		std::cout << "\n*-*-*-*-*-*- CHECK_DEEPCOPY_SUITE *-*-*-*-*-*-\n " << std::endl;
		{
			Dog CheckCopy (original);
		}
		std::cout << "Original brain index 0: " << original.getbrain()->getBrainAtIndex(0) <<  std::endl; // Should not crash with deepcopy
		{
			Dog CheckCopy = original;
		}
		std::cout << "Original brain index 0: " << original.getbrain()->getBrainAtIndex(0) <<  std::endl; // Should not crash with deepcopy
	}
	{
		std::cout << "\n*-*-*-*-*-*-  ACCESSORS TESTS *-*-*-*-*-*-\n " << std::endl;
		Dog original;
		original.getbrain()->getBrainAtIndex(12);
		original.getbrain()->getBrainAtIndex(-1);
		original.getbrain()->getBrainAtIndex(100);
		original.getbrain()->setBrainAtIndex("test", -1);
		original.getbrain()->setBrainAtIndex("test", 100);
	}
	// system("leaks Animal");
	return 0;
}