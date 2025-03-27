/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foold_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:49:07 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/26 22:49:08 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;

	i = 0;
	d = (char *)malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (!d)
		return (NULL);
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

int	check_element_copy(char **map, t_map *mp)
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
				mp->p++;
			else if (map[mp->i][mp->j] == 'E')
				mp->e++;
			mp->j++;
		}
		mp->i++;
	}
	if (mp->c != 0 || mp->e != 0 || mp->p != 0)
		return (1);
	return (0);
}

char	**map_copy(char **map, char *path_file)
{
	int		i;
	int		len;
	char	**copy_map;

	i = 0;
	len = len_map(path_file);
	copy_map = malloc(sizeof(char *) * (len + 1));
	if (!copy_map)
	{
		free_map(map);
		return (NULL);
	}
	while (i < len)
	{
		copy_map[i] = ft_strdup(map[i]);
		i++;
	}
	copy_map[i] = NULL;
	return (copy_map);
}

void	foold_fill(int x, int y, char **map)
{
	if (map[y][x] == '1' || map[y][x] == 'Q')
		return ;
	map[y][x] = 'Q';
	foold_fill(x + 1, y, map);
	foold_fill(x - 1, y, map);
	foold_fill(x, y + 1, map);
	foold_fill(x, y - 1, map);
}
