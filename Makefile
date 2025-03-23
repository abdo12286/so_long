CC = cc 
CFLAGS = -Wall -Wextra -Werror
SERC = pasing.c gnl.c so_long.c
NAME = so_long
OBJ = $(SERC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME) 

re: fclean all
