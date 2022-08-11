SRCS =	ft_printf.c \
	ft_putchar_rl.c \
	ft_putstr_rl.c \
	ft_putnbr_base_rl.c \
	ft_strlen.c \
	ft_putadr_rl.c \
	ft_putnbr_base_rlu.c \

OBJ = $(SRCS:.c=.o)

NAME = libftprintf.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra 

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) -c $(CFLAGS) $(SRCS)
		ar rc $(NAME) $(OBJ)

clean: 
		$(RM) $(OBJ) $(BONUS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.SILENT:
.PHONY:		all clean fclean re
