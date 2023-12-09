/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:05:06 by dspilleb          #+#    #+#             */
/*   Updated: 2023/12/09 18:18:26 by dspilleb         ###   ########.fr       */
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
		int size = 10;
		Animal *arr[size];
		for (int i = 0; i < size; i++)
		{
			if (i % 2 == 0)
				arr[i] = new Cat();
			else
				arr[i] = new Dog();
		}
		for (int i = 0; i < size; i++)
			delete arr[i];
	}
	{
		//check leak
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		//check deepcopy
		const Dog i;
		i.my_brain->setBrainAtIndex("Oui", 0);
		std::cout << i.my_brain->getBrainAtIndex(0) <<  std::endl;
		const Dog i_copy = i;
		std::cout << i_copy.my_brain->getBrainAtIndex(0) <<  std::endl;
		i_copy.my_brain->setBrainAtIndex("Non", 0);
		std::cout << i.my_brain->getBrainAtIndex(0) <<  std::endl;
		std::cout << i_copy.my_brain->getBrainAtIndex(0) <<  std::endl;
	}
	return 0;
}