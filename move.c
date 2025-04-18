/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 15:59:33 by atigzim           #+#    #+#             */
/*   Updated: 2025/04/08 15:36:30 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mov_down(t_window *mlx)
{
	if (mlx->map[mlx->mp->pos_y + 1][mlx->mp->pos_x] == 'E' && mlx->mp->c == 0)
	{
		ft_putstr_fd("YOU WIN!!\n", 1);
		clear_win(mlx);
	}
	if (mlx->map && mlx->map[mlx->mp->pos_y + 1][mlx->mp->pos_x] != '1')
	{
		if (mlx->map[mlx->mp->pos_y + 1][mlx->mp->pos_x] == 'C')
			mlx->mp->c--;
		mlx->map[mlx->mp->pos_y + 1][mlx->mp->pos_x] = 'P';
		mlx->map[mlx->mp->pos_y][mlx->mp->pos_x] = '0';
		mlx->mp->pos_y++;
		mlx->moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd(" move\r", 1);
	}
}

void	mov_left(t_window *mlx)
{
	if (mlx->map[mlx->mp->pos_y][mlx->mp->pos_x - 1] == 'E' && mlx->mp->c == 0)
	{
		ft_putstr_fd("YOU WIN!!\n", 1);
		clear_win(mlx);
	}
	if (mlx->map && mlx->map[mlx->mp->pos_y][mlx->mp->pos_x - 1] != '1')
	{
		if (mlx->map[mlx->mp->pos_y][mlx->mp->pos_x - 1] == 'C')
			mlx->mp->c--;
		mlx->map[mlx->mp->pos_y][mlx->mp->pos_x - 1] = 'P';
		mlx->map[mlx->mp->pos_y][mlx->mp->pos_x] = '0';
		mlx->mp->pos_x--;
		mlx->moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd(" move\r", 1);
	}
}

void	mov_right(t_window *mlx)
{
	if (mlx->map[mlx->mp->pos_y][mlx->mp->pos_x + 1] == 'E' && mlx->mp->c == 0)
	{
		ft_putstr_fd("YOU WIN!!\n", 1);
		clear_win(mlx);
	}
	if (mlx->map && mlx->map[mlx->mp->pos_y][mlx->mp->pos_x + 1] != '1')
	{
		if (mlx->map[mlx->mp->pos_y][mlx->mp->pos_x + 1] == 'C')
			mlx->mp->c--;
		mlx->map[mlx->mp->pos_y][mlx->mp->pos_x + 1] = 'P';
		mlx->map[mlx->mp->pos_y][mlx->mp->pos_x] = '0';
		mlx->mp->pos_x++;
		mlx->moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd(" move\r", 1);
	}
}

void	mov_up(t_window *mlx)
{
	if (mlx->map[mlx->mp->pos_y - 1][mlx->mp->pos_x] == 'E' && mlx->mp->c == 0)
	{
		ft_putstr_fd("YOU WIN!!\n", 1);
		clear_win(mlx);
	}
	if (mlx->map && mlx->map[mlx->mp->pos_y - 1][mlx->mp->pos_x] != '1')
	{
		if (mlx->map[mlx->mp->pos_y - 1][mlx->mp->pos_x] == 'C')
			mlx->mp->c--;
		mlx->map[mlx->mp->pos_y - 1][mlx->mp->pos_x] = 'P';
		mlx->map[mlx->mp->pos_y][mlx->mp->pos_x] = '0';
		mlx->mp->pos_y--;
		mlx->moves++;
		ft_putnbr_fd(mlx->moves, 1);
		ft_putstr_fd(" move\r", 1);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
