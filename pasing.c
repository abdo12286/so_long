#include "so_long.h"

void free_map (char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void exit_map(char **map)
{
	write(1,"Error\n",6);
	write(1,"map invalid",12);
	free_map(map);
	exit(1);
}

int ft_strstr(char *str, char *to_find)
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
	char *r_l_line;
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
	r_l_line =  get_next_line(fd);
	while(r_l_line)
	{
		if(r_l_line[0] != '\n')
			exit_map(map);
		r_l_line =  get_next_line(fd);
	}
	map[i] = NULL;

	return(map);

}
void check_dot_ber(char *path_file)
{
	if(ft_strstr(path_file,".ber") == 0)
	{
		write(1,"Error\n",6);
		write(1, "I want file .ber", 17);
		exit(1);
	}
}
void	check_nonvalid(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] != '0' &&  map[i][j] != '1' && map[i][j] != '\n' &&
			map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P')
				exit_map(map);
			j++;
		}
		i++;
	}
}
void check_element(char **map)
{
	t_map mp;

	mp.i = 0;
	mp.c = 0;
	mp.e = 0;
	mp.p = 0;
	while(map[mp.i])
	{
		mp.j = 0;
		while(map[mp.i][mp.j])
		{
			if(map[mp.i][mp.j] == 'C')
				mp.c++;
			else if(map[mp.i][mp.j] == 'P')
			{
				mp.pos_x = mp.i;
				mp.pos_y = mp.j;
				mp.p++;
			}	
			else if (map[mp.i][mp.j] == 'E')
				mp.e++;
			mp.j++;
		}
		mp.i++;
	}
	if(mp.c < 1 || mp.e != 1 || mp.p != 1)
		exit_map(map);
}

int len_frst_line(char **map)
{
	int i;
	int j;
	int k;

	k = 1;
	i = ft_strlen(map[0]);
	if(map[0][i - 1] == '\n')
			i--;
	while(map[k])
	{
		j = ft_strlen(map[k]);
		if(map[k][j - 1] == '\n')
			j--;
		if(j != i)	
			return (1);
		k++;
	}
	return(0);
}

void	parsi_map(char *path_file, t_data *mlx)
{
	int fd;

	fd = open(path_file, O_RDONLY);
	if(fd == -1)
	{
		write(1,"Error\n",6);
		write(1,"Only valid \".ber\" map files are allowed!",41);
		exit(1);
	}
	check_dot_ber(path_file);	
	mlx->map =get_map(path_file,len_map(path_file));
	if(len_frst_line(mlx->map) == 1)
		exit_map(mlx->map);
	check_nonvalid(mlx->map);
	check_element(mlx->map);
	free_map(mlx->map);	
	
}
