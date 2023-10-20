/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:12:53 by edvicair          #+#    #+#             */
/*   Updated: 2023/07/09 21:28:44 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_double(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	if (!*str)
	{
		free(str);
		return ;
	}
	while (str && str[i])
	{
		if (str[i])
			free(str[i]);
		i++;
	}
	free(str);
}

void	free_walls(t_cub *cub)
{
	free(cub->wall_n);
	free(cub->wall_s);
	free(cub->wall_w);
	free(cub->wall_e);
}

int	ft_void_exit(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}
