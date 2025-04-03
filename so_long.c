/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:49:28 by atigzim           #+#    #+#             */
/*   Updated: 2025/04/03 12:35:24 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	height_map(char **map)
{
	int i;
	// int j;
	// int k;

	 i = 0;
	// k = 0;
	while(map[i])
		i++;
	return (i);
}

int	width_map(char **map)
{
	t_window wi;

	wi.width = ft_strlen(map[0]) - 1;
	return (wi.width);
}
// void git_imag(char **map)
// {
// 	t_map mp;
// 	t_window wi;
	
// 	mp.i = 0;
	
// 	while (map[mp.i])
// 	{
// 		mp.j = 0;
// 		while(map[mp.i][mp.j])
// 		{
// 			if(map[mp.i][mp.j] == '1')
// 		}
		
// 	}
	
	
	
// }
int d_mov(int x, int y, t_window *mlx)
{
	if(mlx->map[x][y] == '1')
		return(1);
        if (mlx->map[x][y] != '1')
	{
		mlx->map[x][y = 1] = 'P';
		mlx->map[x][y] = '0';   
	}
    return 0;
}
int key_press(int keycode , t_window *mlx,t_map mp)
{
	// printf("pos_x  (%d)\n", mp.pos_x);
	(void) mp;
    if (keycode == ESC)
    {
		free_map(mlx->map);
        exit(0); 
    }
	// if(keycode == 100)
	// {
	// 	d_mov()
	// }
    return (0);
}
int sed(void)
{
	exit(0);
}
void load_images(t_window *mlx)
{
	int a;
	int b;
	
	mlx->player =  mlx_xpm_file_to_image(mlx->mlx, "assets/pac.xpm", &a, &b); // hia li kathawel lik l file mn xpm lwahed l forma li t9der t afichiha fl window , kat returni pointer
	if(!mlx->player)
		exit(1);
	mlx->collectibles = mlx_xpm_file_to_image(mlx->mlx, "assets/coins.xpm", &a, &b);
	if(!mlx->collectibles)
		exit(1);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, "assets/portal.xpm", &a, &b);
	if(!mlx->exit)
		exit(1);
	mlx->bg = mlx_xpm_file_to_image(mlx->mlx, "assets/wall.xpm", &a, &b);
	if(!mlx->bg)
		exit(1);
}

void new_win(t_window *mlx, char **map)
{
	t_map mp;
	
	mlx->height = height_map(map);
	mlx->width = width_map(map);
	mlx->window = mlx_new_window(mlx->mlx, mlx->width * 32, mlx->height * 32 ,"so_long");
	load_images(mlx);
	mp.pos_x = 0;
	while(map[mp.pos_x])
	{
		mp.pos_y = 0;
		while(map[mp.pos_x][mp.pos_y])
		{
			if(map[mp.pos_x][mp.pos_y]  == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->window,mlx->bg,mp.pos_y* 32, mp.pos_x * 32);
			else if(map[mp.pos_x][mp.pos_y]  == 'P')
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window,mlx->player,mp.pos_y * 32, mp.pos_x *32); // hna fin bgheti thet hadak tswira 
			}	
			else if(map[mp.pos_x][mp.pos_y]  == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->window,mlx->collectibles, mp.pos_y * 32, mp.pos_x * 32);
			else if(map[mp.pos_x][mp.pos_y]  == 'E')
				mlx_put_image_to_window(mlx->mlx, mlx->window,mlx->exit,mp.pos_y * 32, mp.pos_x *32);
			mp.pos_y++;
			
		}
		mp.pos_x++;
	}
}

int	main(int ac, char **av)
{
	t_window	mlx;
	

	if (ac != 2)
	{
		write(1, "Error\n", 6);
		write(1, "Give me fils", 13);
		exit(1);
	}
	mlx.mlx = mlx_init();
	if(!mlx.mlx)
	{
		perror("Allocation");
		return (2);
	}
	mlx.map = NULL;
	parsi_map(av[1], &mlx);
	new_win(&mlx, mlx.map);
	mlx_key_hook(mlx.window, key_press, &mlx);
	// ?mlx_key_hook(win,d_mov , NULL);
	mlx_hook(mlx.window, 17, 0, sed, NULL);
	mlx_loop(mlx.mlx);
}
