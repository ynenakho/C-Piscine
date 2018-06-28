NAME = pony
CC = clang++
FLAGS = -Wall -Wextra -Werror
OBJ = main.o Pony.o
DEPS = Pony.hpp

all: $(NAME)

%.o: %.cpp
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS) -I $(DEPS)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
