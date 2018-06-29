NAME = fragtrap
CC = clang++
FLAGS = -Wall -Wextra -Werror
OBJ = FragTrap.o ScavTrap.o ClapTrap.o NinjaTrap.o main.o

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
