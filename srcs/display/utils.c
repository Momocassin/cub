/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:05:47 by motaouss          #+#    #+#             */
/*   Updated: 2023/07/11 01:54:58 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	textorder(t_text text[4], t_cub *cub)
{
	text[1].path = cub->wall_n;
	text[0].path = cub->wall_s;
	text[3].path = cub->wall_w;
	text[2].path = cub->wall_e;
	text[0].img = NULL;
	text[1].img = NULL;
	text[2].img = NULL;
	text[3].img = NULL;
}

int	fill_text(t_data *data)
{
	int		i;
	int		y;
	int		x;
	t_text	*tmp;

	i = 0;
	tmp = data->text;
	textorder(tmp, data->cub);
	while (i < 4)
	{
		if (!texto(data, i))
			return (0);
		y = 0;
		while (y < data->text[i].texheight)
		{
			x = -1;
			while (++x < data->text[i].texwidth)
				data->texture[i][data->text[i].texwidth * y + x]
					= data->text[i].addr[data->text[i].texwidth * y + x];
			y++;
		}
		mlx_destroy_image(data->mlx, data->text[i].img);
		i++;
	}
	return (1);
}

void	player_dir2(t_plane *plane, char c)
{
	if (c == 'E')
	{
		plane->dir.x = -1.0;
		plane->dir.y = 0.0;
		plane->plane.x = 0.0;
		plane->plane.y = 0.66;
	}
	if (c == 'S')
	{
		plane->dir.x = 0.0;
		plane->dir.y = 1.0;
		plane->plane.x = 0.66;
		plane->plane.y = 0.0;
	}
}

void	player_dir(t_plane *plane, char c)
{
	player_dir2(plane, c);
	if (c == 'N')
	{
		plane->dir.x = 0.0;
		plane->dir.y = -1.0;
		plane->plane.x = -0.66;
		plane->plane.y = 0.0;
	}
	if (c == 'W')
	{
		plane->dir.x = 1.0;
		plane->dir.y = 0.0;
		plane->plane.x = 0.0;
		plane->plane.y = -0.66;
	}
}

void	player_data(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (data->cub->map[x])
	{
		y = 0;
		while (data->cub->map[x][y])
		{
			if (data->cub->map[x][y] == 'N' || data->cub->map[x][y] == 'E'
			|| data->cub->map[x][y] == 'W' || data->cub->map[x][y] == 'S')
			{
				player_dir(data->plane, data->cub->map[x][y]);
				data->plane->pos.x = x;
				data->plane->pos.y = y;
				data->cub->map[x][y] = '0';
			}
			y++;
		}
		x++;
	}
}
