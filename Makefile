NAME	=		push_swap

CFLAGS	=		-g3 -Wall -Werror -Wextra -I  ./push_swap.h

DIR_SRC	=		src
DIR_OBJ	=		obj

SRC		=	algo3_5.c \
		lst_utils.c \
		push_swap.c \
		main.c \
		mouv.c \
		parsing.c \
		algos.c

OBJ		=		$(SRC:%.c=$(DIR_OBJ)/%.o)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(OBJ) -o  $(NAME)

$(DIR_OBJ)/%.o:	$(DIR_SRC)/%.c
				@mkdir -p $(DIR_OBJ)
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

clean:
				rm -rf $(DIR_OBJ)

fclean:			clean
				rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
