#include "MutantStack.hpp"
#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << "-------With list---------" << std::endl;


	std::list<int> Lstack;
	Lstack.push_back(5);
	Lstack.push_back(17);
	std::cout << Lstack.back() << std::endl;
	Lstack.pop_back();
	std::cout << Lstack.size() << std::endl;
	Lstack.push_back(3);
	Lstack.push_back(5);
	Lstack.push_back(737);
	//[...]
	Lstack.push_back(0);
	std::list<int>::iterator it2 = Lstack.begin();
	std::list<int>::iterator ite2 = Lstack.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
	std::cout << *it2 << std::endl;
	++it2;
	}

	return 0;
}