NAME	=		push_swap

FLAGS	=		-Wall -Werror -Wextra

DIR_SRC	=		src
DIR_OBJ	=		obj

SRC		=		listes.c mouv_a.c mouv_b.c utils.c
OBJ		=		$(SRC:%.c=$(DIR_OBJ)/%.o)

$(NAME):		$(OBJ)
				$(CC) $(OBJ) -o $(NAME)

$(DIR_OBJ)/%.o:	$(DIR_SRC)/%.c
				@mkdir -p $(DIR_OBJ)
				$(CC) $(FLAGS) -c $< -o $@

all:			$(NAME)

clean:
				rm -rf $(DIR_OBJ)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re