/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:49:34 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/26 22:49:35 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_da
{
	char	**map;

}			t_data;

typedef struct s_map
{
	int		i;
	int		j;
	int		c;
	int		p;
	int		e;
	int		pos_x;
	int		pos_y;
}			t_map;

int			ft_strlen(const char *s);
char		*get_next_line(int fd);
void		parsi_map(char *path_file, t_data *mlx);
int			len_map(char *path_file);
char		**get_map(char *path_file, int len);
int			len_frst_line(char **map);
void		exit_map(char **map);
void		free_map(char **map);
int			ft_strstr(char *str, char *to_find);
void		check_dot_ber(char *path_file);
void		check_nonvalid(char **map);
char		**map_copy(char **map, char *path_file);
char		*ft_strdup(const char *s);
void		foold_fill(int x, int y, char **map);
int			check_element_copy(char **map, t_map *mp);
void		check_word(char **map, char *path_file);
void		check_word_two(char **map, char *path_file);
#endif