#include "so_long.h"

int main(int ac, char **av)
{
	(void) av;
	if(ac != 2)
	{
		write(1,"Error\n",6);
		exit(1);
	}
	t_data mlx;
	parsi_map(av[1], &mlx);
	// for (size_t i = 0; mlx.map[i]; i++)
	// {
	// 	printf("%s",mlx.map[i]);
	// }
	
		
}