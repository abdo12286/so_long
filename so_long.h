#ifndef SO_LONG_H
# define SO_LONG_H


#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_da
{
	char **map;

} t_data;

typedef struct s_map
{
	int i;
	int j;
	int c;
	int p;
	int e;
	int pos_x;
	int pos_y;
}t_map;

int	ft_strlen(const char *s);
char	*get_next_line(int fd);
void	parsi_map(char *path_file, t_data *mlx);
int len_map(char *path_file);
char **get_map(char *path_file, int len);
int len_frst_line(char **map);
void exit_map(char **map);
void free_map (char **map);
int ft_strstr(char *str, char *to_find);
void check_dot_ber(char *path_file);
void	check_nonvalid(char **map);

#endif