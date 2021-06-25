SRC = 	main.c

OBJ = 	$(SRC:.c=.o)

NAME = 	btoo

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
