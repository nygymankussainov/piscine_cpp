NAME = phonebook

SRC = phonebook.cpp ContactInfo.class.cpp

OBJ = $(SRC:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	clang++ $(FLAGS) -o $(NAME) $(OBJ) -I ./

%.o: %.cpp
	clang++ $(FLAGS) -o $@ -c $< -I ./

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
