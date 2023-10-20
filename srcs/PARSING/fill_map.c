/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 03:38:03 by motaouss          #+#    #+#             */
/*   Updated: 2023/07/18 18:44:42 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_col(char **file)
{
	int	max;
	int	i;
	int	j;

	i = 0;
	max = 0;
	while (file[i])
	{
		j = 0;
		while (file[i][j])
			j++;
		if (max < j)
			max = j;
		i++;
	}
	return (max);
}

bool	malloc_cub(t_cub *cub)
{
	int	i;

	i = 0;
	cub->map = (char **)ft_calloc(sizeof(char *), (cub->width + 1));
	if (!cub->map)
		return (1);
	while (i < cub->width)
	{
		cub->map[i] = (char *)ft_calloc(sizeof(char), (cub->height + 1));
		if (!cub->map[i])
			return (1);
		i++;
	}
	return (0);
}

bool	check_nl_map(char **file, int j)
{
	while (file[j])
	{
		if (!is_line(file[j]))
		{
			printf("Error map : The map cannot be separated by nl\n");
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_sixline(char **file, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < i)
	{
		if (!is_line(file[x]))
			y++;
		x++;
	}
	if (y == 6)
		return (0);
	else
		return (1);
}

bool	init_map(char **file, t_cub *cub, int i)
{
	int	j;
	int	k;

	cub->height = 0;
	while (is_line(file[i]))
		i++;
	if (check_sixline(file, i))
		return (1);
	j = i;
	while (file[j] && !is_line(file[j]))
	{
		k = 0;
		while (file[j][k])
			k++;
		if (k > cub->width)
			cub->width = k;
		cub->height++;
		j++;
	}
	if (check_nl_map(file, j))
		return (1);
	return (fill_map(file, cub, i, j));
}
