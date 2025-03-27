/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_two.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:49:19 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/27 14:48:17 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_map(char *path_file)
{
	int		fd;
	int		len;
	char	*r_l_map;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (-1);
	len = 0;
	r_l_map = get_next_line(fd);
	while (r_l_map && r_l_map[0] == '1')
	{
		len++;
		free(r_l_map);
		r_l_map = get_next_line(fd);
	}
	free(r_l_map);
	return (len);
}

void	loop_map(char	*r_l_line, int fd, char **map)
{
	while (r_l_line)
	{
		if (r_l_line[0] != '\n')
		{
			free(r_l_line);
			exit_map(map);
		}
		free(r_l_line);
		r_l_line = get_next_line(fd);
	}
}

char	**get_map(char *path_file, int len)
{
	int		fd;
	int		i;
	char	*r_l_line;
	char	**map;

	fd = open(path_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * (len + 1));
	if (!map)
		return (NULL);
	i = 0;
	while (i < len)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	r_l_line = get_next_line(fd);
	loop_map (r_l_line, fd, map);
	return (map);
}

void	check_dot_ber(char *path_file)
{
	if (ft_strstr(path_file, ".ber") == 0)
	{
		write(1, "Error\n", 6);
		write(1, "I want file .ber", 17);
		exit(1);
	}
}

void	check_nonvalid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n'
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				exit_map(map);
			j++;
		}
		i++;
	}
}
