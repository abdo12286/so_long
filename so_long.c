/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:49:28 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/27 23:50:38 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	height_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(map[i][j])
	{
		if(map[i][j] == '\n')
		{
			
		}
		else
		{
			j++;
		}
		
	}
}

void 	size_map(char **map, t_window **height, t_window **width)
{
	width = len_frst_line(map);
	
}

void new_win(char **map)
{
	void *mlx;
	void	*win;

	mlx = mlx_init();
	if(!mlx)
	{
		free_map(map);
		write(1, "Error\n", 6);
	}
	win = mlx_new_window(mlx,800,800,"so_long");

	mlx_loop(mlx);
}

int	main(int ac, char **av)
{
	t_data	mlx;

	if (ac != 2)
	{
		write(1, "Error\n", 6);
		write(1, "Give me fils", 13);
		exit(1);
	}
	mlx.map = NULL;
	parsi_map(av[1], &mlx);
	new_win(mlx.map);
	free_map(mlx.map);
}
