/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 04:00:37 by edvicair          #+#    #+#             */
/*   Updated: 2023/07/24 19:55:30 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_cub(char **av)
{
	int	i;

	i = 0;
	while (av[1][i] != '\0')
		i++;
	if (av[1][i - 4] != '.' || av[1][i - 3] != 'c' || av[1][i - 2] != 'u'
		|| av[1][i - 1] != 'b')
	{
		printf("Error : File is not a .cub\n");
		return (1);
	}
	return (0);
}

bool	check_ndwe2(char **file, t_cub *cub, int i, int j)
{
	if (!ft_strncmp((file[i] + j), "NO", 2))
	{
		j += 2;
		while (file[i][j] == ' ' || file[i][j] == '\t')
			j++;
		if (cub->wall_n)
			cub->error++;
		else
			cub->wall_n = ft_substr(file[i], j, ft_strlen(file[i]), 1);
		return (1);
	}
	else if (!ft_strncmp((file[i] + j), "SO", 2))
	{
		j += 2;
		while (file[i][j] == ' ' || file[i][j] == '\t')
			j++;
		if (cub->wall_s)
			cub->error++;
		else
			cub->wall_s = ft_substr(file[i], j, ft_strlen(file[i]), 1);
		return (1);
	}
	return (0);
}

bool	check_ndwe(char **file, t_cub *cub, int i, int j)
{
	if (check_ndwe2(file, cub, i, j))
		return (1);
	else if (!ft_strncmp((file[i] + j), "WE", 2))
	{
		j += 2;
		while (file[i][j] == ' ' || file[i][j] == '\t')
			j++;
		if (cub->wall_w)
			cub->error++;
		else
			cub->wall_w = ft_substr(file[i], j, ft_strlen(file[i]), 1);
		return (1);
	}
	else if (!ft_strncmp((file[i] + j), "EA", 2))
	{
		j += 2;
		while (file[i][j] == ' ' || file[i][j] == '\t')
			j++;
		if (cub->wall_e)
			cub->error++;
		else
			cub->wall_e = ft_substr(file[i], j, ft_strlen(file[i]), 1);
		return (1);
	}
	return (0);
}

bool	check_val(t_cub *cub)
{
	if (cub->f == -1 || cub->c == -1)
	{
		printf("Error : 0 >= RGB <= 255\n");
	}
	if (!cub->wall_n || !cub->wall_s || !cub->wall_w || !cub->wall_e || !cub->f
		|| !cub->c)
		return (1);
	return (0);
}

bool	is_line(char *file)
{
	int	i;

	i = 0;
	if (file[0] == '\0')
		return (1);
	if (file[0] != ' ' && file[0] != '\t')
		return (0);
	while (file[i])
	{
		if (file[i] == ' ' || file[i] == '\t')
			i++;
		else if (file[i] != ' ' && file[i] != '\t' && file[i] != '\0')
			break ;
	}
	if (file[i] == '\0')
		return (1);
	return (0);
}
