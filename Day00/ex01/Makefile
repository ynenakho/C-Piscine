NAME = phonebook
CC = clang++
FLAGS = -Wall -Wextra -Werror
OBJ = main.o PhoneBook.class.o
DEPS = PhoneBook.class.hpp

all: $(NAME)

%.o: %.c
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS) -I $(DEPS)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
