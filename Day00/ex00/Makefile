NAME = megaphone
CC = clang++
FLAGS = -Wall -Wextra -Werror
OBJ = megaphone.o

all: $(NAME)

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
