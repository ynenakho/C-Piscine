NAME = sorcerer
CC = clang++
FLAGS = -Wall -Wextra -Werror
OBJ = Sorcerer.o Peon.o Victim.o main.o

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
