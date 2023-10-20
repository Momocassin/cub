/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 03:45:17 by motaouss          #+#    #+#             */
/*   Updated: 2023/07/24 20:11:54 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	fill_map(char **file, t_cub *cub, int min, int max)
{
	int	x;
	int	y;
	int	z;
	int	w;

	y = min - 1;
	z = -1;
	w = 0;
	x = cub->width + 1;
	if (malloc_cub(cub))
		return (1);
	while (++y < max)
	{
		while ((size_t)--x > ft_strlen(file[y]))
			cub->map[++z][w] = ' ';
		while (--x >= 0)
			cub->map[++z][w] = file[y][x];
		w++;
		x = cub->width + 1;
		z = -1;
	}
	while (++z < cub->width)
		cub->map[z][cub->height] = '\0';
	cub->map[z] = NULL;
	return (0);
}

bool	check_double(char **file)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	found = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (ft_strchr("NSWE", file[i][j]))
				found++;
			j++;
		}
		i++;
	}
	return (found != 1);
}

bool	check_map(t_cub cub)
{
	int	x;

	x = 0;
	while (cub.map[x] != NULL)
	{
		if (x == 0 || x == cub.width - 1)
		{
			if (error_edge(cub.map, x))
				return (printf("Error map\n"), 1);
		}
		else if ((x > 0) && (x < cub.width - 1))
		{
			if (cub.map[x][0] != ' ' && cub.map[x][0] != '1')
				return (printf("Error map\n"), 1);
			if (cub.map[x][cub.height - 1] != ' '
					&& cub.map[x][cub.height - 1] != '1')
				return (printf("Error map\n"), 1);
			else if (error_map(cub.map, x))
				return (printf("Error map\n"), 1);
		}
		x++;
	}
	if (check_double(cub.map))
		return (printf("Error player\n"), 1);
	return (0);
}
