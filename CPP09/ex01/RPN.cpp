#include "RPN.hpp"

bool is_token(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' );
}