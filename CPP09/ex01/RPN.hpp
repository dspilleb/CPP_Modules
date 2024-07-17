#ifndef RPN_HPP
# define RPN_HPP
# include <iostream>
# include <stack>
# include <cstring>

# define ERR_FORMAT "Error: format is incorrect."
# define ERR_CHAR "Error: Invalid character in mathematical expression => "

bool is_token(const char c);
void handle_token(const char token, std::stack<int> &s);
int calculate_expression(const std::string expression);

#endif 