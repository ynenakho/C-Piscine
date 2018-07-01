NAME = ft_retro
CC = clang++
FLAGS = -Wall -Wextra -Werror -g
SOURCES = $(wildcard *.cpp)
OBJ = $(SOURCES:.cpp=.o)


all: $(NAME)

%.o: %.cpp
	$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJ)
	$(CC) -o $@ $^ $(FLAGS) -I. -l ncurses

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
