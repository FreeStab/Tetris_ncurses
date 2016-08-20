NAME		=	check_tetrimino

SRC		=	get_next_line.c \
			main.c \
			puts.c\
			my_getnbr.c

OBJ		=	$(SRC:.c=.o)

CC		?=	gcc

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
