#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <iterator>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{

	public:
		typedef typename Container::iterator iterator;

		MutantStack(){}
		MutantStack( MutantStack const & src ) : std::stack<T, Container>(src) {}
		~MutantStack() {}

		MutantStack &		operator=( MutantStack const & rhs ) 
		{
			if (this != &rhs)
				std::stack<T, Container>::operator=(rhs);
			return (*this);
		}
		iterator begin(void) {return(this->c.begin());}
		iterator end(void) {return(this->c.end());}
		typename Container::const_iterator begin(void)const  {return(this->c.begin());}
		typename Container::const_iterator end(void) const {return(this->c.end());}
	private:
		
};

#endif /* ***************************************************** MUTANTSTACK_H */