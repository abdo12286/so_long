/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:49:28 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/29 02:57:35 by atigzim          ###   ########.fr       */
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
int key_press(int keycode ,char **map)
{
	
    if (keycode == ESC  || keycode == CLOSE)
    {
		free_map(map);
        exit(0); 
    }
    return (0);
}
int sed(void)
{
	exit(0);
}
void new_win(char **map)
{
	void *mlx;
	void	*win;
	t_map mp;
	t_window wi;
	int a = 32;
	int b = 32;
	mp.pos_x = 0;
	
	mlx = mlx_init();
	if(!mlx)
	{
		free_map(map);
		write(1, "Error\n", 6);
	}
	wi.height = height_map(map);
	wi.width = width_map(map);
	win = mlx_new_window(mlx,wi.width * 32, wi.height * 32 ,"so_long");
	wi.player =  mlx_xpm_file_to_image(mlx, "assets/pac.xpm",&a,&b); // hia li kathawel lik l file mn xpm lwahed l forma li t9der t afichiha fl window , kat returni pointer
	wi.collectibles = mlx_xpm_file_to_image(mlx, "assets/coins.xpm",&a,&b);
	wi.exit = mlx_xpm_file_to_image(mlx,"assets/portal.xpm",&a,&b);
	wi.bg = mlx_xpm_file_to_image(mlx, "assets/wall.xpm",&a,&b);
	while(map[mp.pos_x])
	{
		mp.pos_y = 0;
		while(map[mp.pos_x][mp.pos_y])
		{
			if(map[mp.pos_x][mp.pos_y]  == '1')
				mlx_put_image_to_window(mlx,win,wi.bg,mp.pos_y* 32, mp.pos_x * 32);
			else if(map[mp.pos_x][mp.pos_y]  == 'P')
				mlx_put_image_to_window(mlx,win,wi.player,mp.pos_y * 32, mp.pos_x *32); // hna fin bgheti thet hadak tswira 
			else if(map[mp.pos_x][mp.pos_y]  == 'C')
				mlx_put_image_to_window(mlx,win,wi.collectibles, mp.pos_y * 32, mp.pos_x * 32);
			else if(map[mp.pos_x][mp.pos_y]  == 'E')
				mlx_put_image_to_window(mlx,win,wi.exit,mp.pos_y * 32, mp.pos_x *32);
			mp.pos_y++;
			
		}
		mp.pos_x++;
	}
	
	mlx_key_hook(win, key_press, NULL);
	mlx_hook(win,17,a,sed,NULL);
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
