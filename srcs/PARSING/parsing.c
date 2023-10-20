/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 04:03:02 by edvicair          #+#    #+#             */
/*   Updated: 2023/07/11 05:48:42 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	count_line(char **av)
{
	int		fd;
	int		i;
	char	*str;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Can't open %s\n", av[1]);
		return (0);
	}
	while (1)
	{
		str = get_next_line(fd, 0);
		if (!str)
			break ;
		i++;
		free(str);
	}
	close(fd);
	return (i);
}

void	fill_rgb(t_rgb *rgb, char *s, int color, int x)
{
	if (x == 0)
	{
		rgb->r = -1;
		rgb->g = -1;
		rgb->b = -1;
	}
	else
	{
		if (color == 1)
			rgb->r = ft_atoi(s);
		else if (color == 2)
			rgb->g = ft_atoi(s);
		else if (color == 3)
			rgb->b = ft_atoi(s);
	}
}

bool	fill_cub(t_cub *cub, char **av)
{
	char	**file;
	int		i;
	int		fd;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (printf("Can't open %s\n", av[1]), 1);
	file = (char **)ft_calloc(sizeof(char *), (count_line(av) + 2));
	if (!file)
		return (close(fd), 1);
	while (1)
	{
		file[i] = get_next_line(fd, 0);
		if (!file[i])
			break ;
		i++;
	}
	close(fd);
	file[i] = 0;
	if (split_file(file, cub))
		return (free_double(file), 1);
	return (free_double(file), 0);
}

bool	parser(t_cub *cub, char **av)
{
	int	i;

	i = 0;
	if (check_cub(av))
		return (1);
	if (fill_cub(cub, av))
		return (1);
	if (check_map(*cub))
		return (1);
	return (0);
}
