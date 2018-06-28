NAME = zombie
CC = clang++
FLAGS = -Wall -Wextra -Werror
OBJ = ZombieHorde.o Zombie.o main.o
DEPS = ZombieHorde.hpp Zombie.hpp

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
