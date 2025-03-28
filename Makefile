CC = cc 
CFLAGS = -Wall -Wextra -Werror
SERC = pasing.c gnl.c so_long.c foold_fill.c parsing_utils.c parsing_utils_two.c
NAME = so_long
MLX = mlx/libmlx_Linux.a -lX11 -lXext
OBJ = $(SERC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MLX) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME) 

re: fclean all
