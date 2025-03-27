/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atigzim <atigzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 22:49:28 by atigzim           #+#    #+#             */
/*   Updated: 2025/03/27 14:46:03 by atigzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
}
