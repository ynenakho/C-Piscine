NAME = brain
CC = clang++
FLAGS = -Wall -Wextra -Werror
OBJ = Brain.o Human.o main.o
DEPS = Brain.hpp Human.hpp

all: $(NAME)

%.o: %.cpp
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS) -I.

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
