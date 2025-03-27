/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:49:22 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/27 12:59:23 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

void	exit_map(char **map)
{
	write(1, "Error\n", 6);
	write(1, "map invalid", 12);
	free_map(map);
	exit(1);
}

void	check_word(char **map, char *path_file)
{
	int	len_line;
	int	len_m;
	int	i;

	len_line = ft_strlen(map[0]);
	len_m = len_map(path_file);
	i = 0;
	while (i < len_m)
	{
		if (map[i][len_line - 2] != '1' || map[i][0] != '1')
			exit_map(map);
		i++;
	}
}

void	check_word_two(char **map, char *path_file)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = len_map(path_file);
	if (len == 0)
		exit_map(map);
	while (map[i][j])
	{
		if (map[i][j] != '1' && map[i][j] != '\n')
			exit_map(map);
		j++;
	}
	j = 0;
	while (map[len - 1][j])
	{
		if (map[len - 1][j] != '1' && map[len - 1][j] != '\n')
			exit_map(map);
		j++;
	}
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			while (to_find[j] != '\0')
			{
				if (to_find[j] != str[i])
					break ;
				i++;
				j++;
			}
			if (to_find[j] == '\0')
				return (1);
		}
		else
			i++;
	}
	return (0);
}
