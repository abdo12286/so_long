CC = cc 
CFLAGS = -Wall -Wextra -Werror
SERC = 
NAME = SO_LONG
OBJ = $(SERC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
%.c : %.o
	@$(CC) $(CFLAGS) -c $< -o $@
clean :
	@rm -rf $(OBJ)
fclean : clean
	@rm -rf $(NAME) 
re: fclean all
