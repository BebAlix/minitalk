GREEN = /bin/echo -e "\x1b[1;3;32m$1\x1b[0m"
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRC = utils.c server.c client.c
SRC_BONUS = utils_bonus.c server_bonus.c client_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = server client
PRINT_LIB = ft_printf/libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJ)
		make -s -C ./ft_printf	
		$(CC) $(CFLAGS) server.o $(PRINT_LIB) -o server	
		$(CC) $(CFLAGS) client.o utils.o $(PRINT_LIB) -o client
		$(call GREEN,"Compilation success 😁")

bonus:		$(OBJ_BONUS)
		make -C ./ft_printf 
		$(CC) $(CFLAGS) server_bonus.o $(PRINT_LIB) -o server
		$(CC) $(CFLAGS) client_bonus.o utils_bonus.o $(PRINT_LIB) -o client
		$(call GREEN,"Bonus compilation success 😁")

clean:
		make fclean -C ./ft_printf
		rm -f $(OBJ) $(OBJ_BONUS)
		$(call GREEN,"The .o cleaned up !")

fclean:		clean
		rm -f $(NAME)
		$(call GREEN,"The rest too !")

re:		fclean all

.SILENT:
.PHONY:		all clean fclean re bonus
