/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:03:32 by motaouss          #+#    #+#             */
/*   Updated: 2023/07/07 00:17:06 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_color(t_plane *p, int *color, t_luno2i tex, t_data *data)
{
	if (p->side == 1)
	{
		if (p->raydir.y > 0)
			*color = data->texture[0][64 * tex.y + tex.x];
		else
			*color = data->texture[1][64 * tex.y + tex.x];
	}
	else
	{
		if (p->raydir.x > 0)
			*color = data->texture[3][64 * tex.y + tex.x];
		else
			*color = data->texture[2][64 * tex.y + tex.x];
	}
}

double	sides(t_plane *p)
{
	double	pwall;

	if (p->side == 0)
		pwall = (p->map.x - p->pos.x + (1 - p->step.x) / 2) / p->raydir.x;
	else
		pwall = (p->map.y - p->pos.y + (1 - p->step.y) / 2) / p->raydir.y;
	return (pwall);
}

t_luno2i	get_draw(int lineh)
{
	t_luno2i	draw;

	draw.x = -lineh / 2 + HEIGHT / 2;
	if (draw.x < 0)
		draw.x = 0;
	draw.y = lineh / 2 + HEIGHT / 2;
	if (draw.y >= HEIGHT)
		draw.y = HEIGHT - 1;
	return (draw);
}

double	get_wall_x(t_plane *p, double pwall)
{
	double	wallx;

	if (p->side == 0)
		wallx = p->pos.y + pwall * p->raydir.y;
	else
		wallx = p->pos.x + pwall * p->raydir.x;
	wallx -= floor(wallx);
	return (wallx);
}

int	get_tex_x(t_plane *p, double wallx)
{
	int	val;

	val = (int)(wallx * (double)(64));
	if (p->side == 0 && p->raydir.x > 0)
		val = 64 - val - 1;
	if (p->side == 1 && p->raydir.y < 0)
		val = 64 - val - 1;
	return (val);
}
