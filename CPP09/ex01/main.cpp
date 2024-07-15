#include "RPN.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN <Inverted Polish mathematical expression>" << std::endl;
		return (-1);
	}

	std::stack<int> s;
	std::string expression(av[1]);

	int has_space = true;
	int result;
	int tmp;

	for (size_t i = 0; i < expression.length(); i++)
	{
		if (expression[i] == ' ')
		{
			if (has_space)
			{
				std::cerr << ERR_FORMAT << std::endl;
				return (-1);
			}
			has_space = true;
		}
		else
		{
			if (is_token(expression[i]) && has_space)
			{
					tmp = s.top();
					s.pop();
					result = s.top();
					s.pop();
					// std::cout << result << " " << expression[i] << " " << tmp << std::endl; //! Debug
					if (expression[i] == '+') result += tmp;
					if (expression[i] == '*') result *= tmp;
					if (expression[i] == '-') result -= tmp;
					if (expression[i] == '/') result /= tmp;
					s.push(result);
			}
			else if (std::isdigit(expression[i]) && has_space)
			{
				s.push(expression[i] - '0');
			}
			else
			{
				std::cerr << ERR_CHAR << "'" <<expression[i] << "'" << std::endl;
				return (-1);
			}
			has_space = false;
		}
	}
	s.pop();
	if (!s.empty() || has_space)
	{
		std::cerr << ERR_FORMAT << std::endl;
		return (-1);
	}
	std::cout << result << std::endl;
	return (0);
}