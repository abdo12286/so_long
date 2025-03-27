/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:49:25 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/27 13:17:05 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_element(char **map, t_map *mp)
{
	mp->i = 0;
	mp->c = 0;
	mp->e = 0;
	mp->p = 0;
	while (map[mp->i])
	{
		mp->j = 0;
		while (map[mp->i][mp->j])
		{
			if (map[mp->i][mp->j] == 'C')
				mp->c++;
			else if (map[mp->i][mp->j] == 'P')
			{
				mp->pos_y = mp->i;
				mp->pos_x = mp->j;
				mp->p++;
			}
			else if (map[mp->i][mp->j] == 'E')
				mp->e++;
			mp->j++;
		}
		mp->i++;
	}
	if (mp->c < 1 || mp->e != 1 || mp->p != 1)
		exit_map(map);
}

int	len_frst_line(char **map)
{
	int	i;
	int	j;
	int	k;

	k = 1;
	i = ft_strlen(map[0]);
	if (i == 0)
		exit_map(map);
	if (map[0][i - 1] == '\n')
		i--;
	while (map[k])
	{
		j = ft_strlen(map[k]);
		if (map[k][j - 1] == '\n')
			j--;
		if (j != i)
			return (1);
		k++;
	}
	return (0);
}

void	error_fd(void)
{
	write(1, "Error\n", 6);
	write(1, "Only valid \".ber\" map files are allowed!", 41);
	exit(1);
}

void	parsi_map(char *path_file, t_data *mlx)
{
	int		fd;
	char	**a;
	t_map	mp;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		error_fd();
	check_dot_ber(path_file);
	mlx->map = get_map(path_file, len_map(path_file));
	check_word(mlx->map, path_file);
	check_word_two(mlx->map, path_file);
	if (len_frst_line(mlx->map) == 1)
		exit_map(mlx->map);
	check_nonvalid(mlx->map);
	check_element(mlx->map, &mp);
	a = map_copy(mlx->map, path_file);
	foold_fill(mp.pos_x, mp.pos_y, a);
	if (check_element_copy(a, &mp) == 1)
	{
		free_map(a);
		exit_map(mlx->map);
	}
	free_map(mlx->map);
	free_map(a);
}
