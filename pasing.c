#include "so_long.h"

int len_map(char *path_file)
{
	int fd;
	int len;
	char *r_l_map;

	fd = open(path_file, O_RDONLY);
	if(fd == -1)
		return(-1);
	len = 0;
	r_l_map = get_next_line(fd);
	while (r_l_map && r_l_map[0] == '1')
	{
		len++;
		free(r_l_map);
		r_l_map = get_next_line(fd);
	}
	free(r_l_map);
	return(len);
	
}
char **get_map(char *path_file, int len)
{
	int fd;
	int i;
	char **map;

	fd = open(path_file, O_RDONLY);
	if(fd == -1)
		return(NULL);
	map = malloc(sizeof(char *) * (len + 1));
	if(!map)
		return(NULL);
 
	i = 0;
	while (i < len)
	{
		map[i] =  get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return(map);

}
int len_frst_line(char **map)
{
	int i;
	int j;

	i = ft_strlen(map[i]);
	while(map)

}
void	parsi_map(char *path_file, t_data *mlx)
{
	int fd;

	fd = open(path_file, O_RDONLY);
	if(fd == -1)
		return;
	mlx->map =get_map(path_file,len_map(path_file));

}
