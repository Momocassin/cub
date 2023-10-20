/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:03:42 by motaouss          #+#    #+#             */
/*   Updated: 2023/07/07 00:17:48 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cast(t_plane *plane, int index)
{
	plane->camera.x = 2 * index / (double)WIDTH - 1;
	plane->raydir.x = plane->dir.x + plane->plane.x * plane->camera.x;
	plane->raydir.y = plane->dir.y + plane->plane.y * plane->camera.x;
	plane->map.x = (int)plane->pos.x;
	plane->map.y = (int)plane->pos.y;
	plane->deltadist.x = fabs(1 / plane->raydir.x);
	plane->deltadist.y = fabs(1 / plane->raydir.y);
	plane->hit = 0;
}

void	init_steps(t_plane *p)
{
	if (p->raydir.x < 0)
	{
		p->step.x = -1;
		p->sdist.x = (p->pos.x - p->map.x) * p->deltadist.x;
	}
	else
	{
		p->step.x = 1;
		p->sdist.x = (p->map.x + 1.0 - p->pos.x) * p->deltadist.x;
	}
	if (p->raydir.y < 0)
	{
		p->step.y = -1;
		p->sdist.y = (p->pos.y - p->map.y) * p->deltadist.y;
	}
	else
	{
		p->step.y = 1;
		p->sdist.y = (p->map.y + 1.0 - p->pos.y) * p->deltadist.y;
	}
}

void	dda(t_data *data, t_plane *p)
{
	while (p->hit == 0)
	{
		if (p->sdist.x < p->sdist.y)
		{
			p->sdist.x += p->deltadist.x;
			p->map.x += p->step.x;
			p->side = 0;
		}
		else
		{
			p->sdist.y += p->deltadist.y;
			p->map.y += p->step.y;
			p->side = 1;
		}
		if (data->cub->map[p->map.x][p->map.y] == '1')
			p->hit = 1;
	}
}

void	draw_rayons_all_2(t_data *data, t_drawrays *r, t_plane *p, int i)
{
	int	y;

	y = -1;
	r->step = 1.0 * 64 / r->lineh;
	r->texpos = (r->draw.x - HEIGHT / 2 + r->lineh / 2) * r->step;
	while (++y < HEIGHT)
	{
		if (y < r->draw.x)
			r->color = data->cub->c;
		else if (y > r->draw.y)
			r->color = data->cub->f;
		else
		{
			r->tex.y = (int)r->texpos & (64 - 1);
			r->color = data->texture[r->texnum][64 * r->tex.y + r->tex.x];
			r->texpos += r->step;
			wall_color(p, &r->color, r->tex, data);
		}
		data->buf[y][(int)i] = r->color;
		p->re_buf = 1;
	}
}

void	draw_rayons_all(t_data *data, t_plane *p)
{
	t_drawrays	r;
	int			i;

	init_draw(&r);
	i = -1;
	while (++i < WIDTH)
	{
		init_cast(p, i);
		init_steps(p);
		dda(data, p);
		r.pwall = sides(p);
		r.lineh = (int)(HEIGHT / r.pwall);
		r.draw = get_draw(r.lineh);
		r.texnum = data->cub->map[p->map.x][p->map.y] - '0' - 1;
		r.wallx = get_wall_x(p, r.pwall);
		r.tex.x = get_tex_x(p, r.wallx);
		draw_rayons_all_2(data, &r, p, i);
	}
}
