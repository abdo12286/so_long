/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:49:28 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/28 14:32:57 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	height_map(char **map)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while(map[i])
	{
		 j = 0;
		while(map[i][j])
		{
			if(map[i][j] == '\n')
				k++;
			j++;
		}
		i++;
	}
	return (k);
}

int	width_map(char **map)
{
	t_window wi;

	wi.width = ft_strlen(map[0]) - 1;
	return (wi.width);
}

void new_win(char **map)
{
	void *mlx;
	void	*win;
	t_window wi;

	mlx = mlx_init();
	if(!mlx)
	{
		free_map(map);
		write(1, "Error\n", 6);
	}
	wi.height = height_map(map);
	wi.width = width_map(map);
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
