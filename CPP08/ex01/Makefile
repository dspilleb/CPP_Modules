NAME = Span

SRC =  main.cpp Span.cpp

GCC = c++ -std=c++98 -Wall -Wextra -Werror

OBJ = $(SRC:.cpp=.o)

GREEN='\033[32m'
ORANGE='\033[0;33m'
NONE='\033[0m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'


%.o: %.cpp
	$(GCC) -o $@ -c $^

all: $(NAME)

$(NAME): $(OBJ)
	$(GCC) $(OBJ) -o $(NAME)
	echo $(GREEN)"- Compiled -"$(NONE)

clean:
	echo $(BLUE)"- cleaning -"$(NONE)
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: $(NAME) $(OBJ) clean fclean