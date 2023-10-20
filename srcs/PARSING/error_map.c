/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:04:22 by edvicair          #+#    #+#             */
/*   Updated: 2023/07/07 03:32:03 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	error_map3(char **map, int x, int y)
{
	if (map[x][y] == '0' && (map[x - 1][y] == ' '
			|| map[x][y - 1] == ' '))
		return (1);
	else if (map[x][y] == 'N' && (map[x - 1][y] == ' '
			|| map[x][y - 1] == ' '))
		return (1);
	else if (map[x][y] == 'S' && (map[x - 1][y] == ' '
			|| map[x][y - 1] == ' '))
		return (1);
	else if (map[x][y] == 'W' && (map[x - 1][y] == ' '
			|| map[x][y - 1] == ' '))
		return (1);
	else if (map[x][y] == 'E' && (map[x - 1][y] == ' '
			|| map[x][y - 1] == ' '))
		return (1);
	return (0);
}

bool	error_map(char **map, int x)
{
	int	y;

	y = 0;
	while (map[x][y])
	{
		if (error_map3(map, x, y))
			return (1);
		else if (map[x][y] == ' ')
		{
			if (error_map2(map, x, y))
				return (1);
		}
		y++;
	}
	return (0);
}

bool	error_map2(char **map, int x, int y)
{
	if (y == 0 && (map[x][y] == ' ' || map[x][y] == '1'))
		return (0);
	if (map[x][y] == ' ' && (map[x - 1][y] != ' ' && map[x - 1][y] != '1'))
		return (1);
	else if (map[x][y] == ' ' && (map[x][y - 1] != ' ' && map[x][y - 1] != '1'))
		return (1);
	return (0);
}

bool	error_edge(char **map, int x)
{
	int	y;

	y = 0;
	while (map[x][y])
	{
		if (map[x][y] != '1' && map[x][y] != ' ')
			return (1);
		y++;
	}
	return (0);
}
