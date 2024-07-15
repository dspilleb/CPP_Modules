#include "RPN.hpp"

bool is_token(const char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' );
}

void handle_token(const char token, std::stack<int> &s)
{
	int value1;
	int value2;

	value2 = s.top();
	s.pop();
	value1 = s.top();
	s.pop();
	// std::cout << value1 << " " << token << " " << value2 << std::endl; //! Debug
	if (token == '+') value1 += value2;
	if (token == '*') value1 *= value2;
	if (token == '-') value1 -= value2;
	if (token == '/') value1 /= value2;
	s.push(value1);
}

int calculate_expression(const std::string expression)
{
	std::stack<int> s;
	bool has_space = true;
	int result;

	for (size_t i = 0; i < expression.length(); i++)
	{
		if (expression[i] == ' ');
		else if (is_token(expression[i]) && has_space) handle_token(expression[i], s);
		else if (std::isdigit(expression[i]) && has_space) s.push(expression[i] - '0');
		else return (std::cerr << ERR_CHAR << "'" << expression[i] << "'" << std::endl, -1);
		if (expression[i] == ' ' && has_space) return (std::cerr << ERR_FORMAT << std::endl, -1);
		has_space = (expression[i] == ' ');
	}

	if (!s.empty()) result = s.top();
	s.pop();

	if (!s.empty() || has_space)
	{
		std::cerr << ERR_FORMAT << std::endl;
		return (-1);
	}
	std::cout << result << std::endl;
	return (0);
}