/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:49:28 by atigzim           #+#    #+#             */
/*   Updated: 2025/04/03 18:38:36 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	height_map(char **map)
{
	int i;

	i = 0;
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
	
void draw_map(t_window *mlx, char **map)
{
	int pos_x;
	int pos_y;
	
	pos_x = 0;
	while(map[pos_x])
	{
		pos_y = 0;
		while(map[pos_x][pos_y])
		{
			if(map[pos_x][pos_y]  == '1')
				mlx_put_image_to_window(mlx->mlx, mlx->window,mlx->bg,pos_y* 32, pos_x * 32);
			else if(map[pos_x][pos_y]  == 'P')
				mlx_put_image_to_window(mlx->mlx, mlx->window,mlx->player,pos_y * 32, pos_x *32); // hna fin bgheti thet hadak tswira 
			else if(map[pos_x][pos_y]  == 'C')
				mlx_put_image_to_window(mlx->mlx, mlx->window,mlx->collectibles, pos_y * 32, pos_x * 32);
			else if(map[pos_x][pos_y]  == 'E')
			{
				mlx->mp->pos_x_e = pos_x;
				mlx->mp->pos_y_e = pos_y;
			}
			// 	mlx_put_image_to_window(mlx->mlx, mlx->window,mlx->exit,pos_y * 32, pos_x *32);
			pos_y++;
		}
		pos_x++;
	}
}

void mov_A_S(t_window *mlx, int keycode)
{
	if(keycode == S)
	{
		if(mlx->map[mlx->mp->pos_y + 1][mlx->mp->pos_x] == 'E' && mlx->mp->c == 0)
		 exit(0);
		if(mlx->map && mlx->map[mlx->mp->pos_y + 1][mlx->mp->pos_x] != '1')
		{
			if( mlx->map[mlx->mp->pos_y + 1][mlx->mp->pos_x] == 'C')
				mlx->mp->c--;
			mlx->map[mlx->mp->pos_y + 1][mlx->mp->pos_x] = 'P';
			mlx->map[mlx->mp->pos_y][mlx->mp->pos_x]  = '0';
			mlx->mp->pos_y++;
		}
	}
	else if(keycode == A)
	{
		if(mlx->map[mlx->mp->pos_y][mlx->mp->pos_x - 1] == 'E' && mlx->mp->c == 0)
		 	exit(0);
		if(mlx->map && mlx->map[mlx->mp->pos_y][mlx->mp->pos_x - 1] != '1')
		{
			if( mlx->map[mlx->mp->pos_y][mlx->mp->pos_x - 1] == 'C')
				mlx->mp->c--;
			mlx->map[mlx->mp->pos_y][mlx->mp->pos_x - 1] = 'P';
			mlx->map[mlx->mp->pos_y][mlx->mp->pos_x]  = '0';
			mlx->mp->pos_x--;
		}
	}
}

void mov_D_W(t_window *mlx, int keycode)
{
	if(keycode == D)
	{
		if(mlx->map[mlx->mp->pos_y][mlx->mp->pos_x + 1] == 'E' && mlx->mp->c == 0)
			 exit(0);
		if(mlx->map && mlx->map[mlx->mp->pos_y][mlx->mp->pos_x + 1] != '1')
		{
			if( mlx->map[mlx->mp->pos_y][mlx->mp->pos_x + 1] == 'C')
				mlx->mp->c--;
			mlx->map[mlx->mp->pos_y][mlx->mp->pos_x + 1] = 'P';
			mlx->map[mlx->mp->pos_y][mlx->mp->pos_x]  = '0';
			mlx->mp->pos_x++;
		}
	}
	else if(keycode == W)
	{
		if(mlx->map[mlx->mp->pos_y - 1][mlx->mp->pos_x] == 'E' && mlx->mp->c == 0)
		 	exit(0);
		if(mlx->map && mlx->map[mlx->mp->pos_y - 1][mlx->mp->pos_x] != '1')
		{
			if( mlx->map[mlx->mp->pos_y - 1][mlx->mp->pos_x] == 'C')
				mlx->mp->c--;
			mlx->map[mlx->mp->pos_y - 1][mlx->mp->pos_x] = 'P';
			mlx->map[mlx->mp->pos_y][mlx->mp->pos_x]  = '0';
			mlx->mp->pos_y--;
		}
	}
}

int key_press(int keycode , t_window *mlx)
{
	
    if (keycode == ESC)
    {
		free_map(mlx->map);
        exit(0); 
    }
	if(keycode == D  || keycode == W)
		mov_D_W(mlx, keycode);
	if(keycode == A || keycode == S)
		mov_A_S(mlx, keycode);
	mlx_clear_window(mlx->mlx, mlx->window);
	printf(" c = %d\n",mlx->mp->c);
	if(mlx->mp->c == 0)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window,mlx->exit, mlx->mp->pos_y_e * 32, mlx->mp->pos_x_e *32);
		mlx->map[mlx->mp->pos_x_e][mlx->mp->pos_y_e] = 'E';
	}
	draw_map(mlx, mlx->map);
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
	// t_map mp;
	
	mlx->height = height_map(map);
	mlx->width = width_map(map);
	mlx->window = mlx_new_window(mlx->mlx, mlx->width * 32, mlx->height * 32 ,"so_long");
	load_images(mlx);
	// mp.pos_x = 0;
	draw_map(mlx, map);
}

int	main(int ac, char **av)
{
	t_window	mlx;
	
	mlx.mp = malloc(sizeof(t_map));
	if(!mlx.mp)
		return (0);
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
	parsi_map(av[1], &mlx, mlx.mp);
	new_win(&mlx, mlx.map);
	mlx_key_hook(mlx.window, key_press, &mlx);
	mlx_hook(mlx.window, 17, 0, sed, NULL);
	mlx_loop(mlx.mlx);
}
