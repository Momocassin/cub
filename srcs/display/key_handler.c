/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:32:08 by motaouss          #+#    #+#             */
/*   Updated: 2023/07/11 02:02:20 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	key_board2(int key, t_data *data)
{
	if (key == 119)
	{
		if (data->cub->map[(int)(data->plane->pos.x
				+ data->plane->dir.x * 0.05)][(int)data->plane->pos.y] == '0')
			data->plane->pos.x += data->plane->dir.x * 0.05;
		if (data->cub->map[(int)(data->plane->pos.x)][(int)(data->plane->pos.y
				+ data->plane->dir.y * 0.05)] == '0')
			data->plane->pos.y += data->plane->dir.y * 0.05;
	}
	if (key == 97)
	{
		if (data->cub->map[(int)(data->plane->pos.x - data->plane->plane.x
				* 0.05)][(int)(data->plane->pos.y)] == '0')
			data->plane->pos.x -= data->plane->plane.x * 0.05;
		if (data->cub->map[(int)(data->plane->pos.x)][(int)(data->plane->pos.y
				- data->plane->plane.y * 0.05)] == '0')
			data->plane->pos.y -= data->plane->plane.y * 0.05;
	}
}

void	key_board3(int key, t_data *data)
{
	if (key == 115)
	{
		if (data->cub->map[(int)(data->plane->pos.x
				- data->plane->dir.x * 0.05)][(int)(data->plane->pos.y)] == '0')
			data->plane->pos.x -= data->plane->dir.x * 0.05;
		if (data->cub->map[(int)(data->plane->pos.x)][(int)(data->plane->pos.y
				- data->plane->dir.y * 0.05)] == '0')
			data->plane->pos.y -= data->plane->dir.y * 0.05;
	}
	if (key == 100)
	{
		if (data->cub->map[(int)(data->plane->pos.x
				+ data->plane->plane.x * 0.05)][(int)data->plane->pos.y] == '0')
			data->plane->pos.x += data->plane->plane.x * 0.05;
		if (data->cub->map[(int)(data->plane->pos.x)][(int)(data->plane->pos.y
				+ data->plane->plane.y * 0.05)] == '0')
			data->plane->pos.y += data->plane->plane.y * 0.05;
	}
}

void	key_board4(t_data *data, double olddirx, double oldplanex)
{
	olddirx = data->plane->dir.x;
	data->plane->dir.x = data->plane->dir.x * cos(-0.02)
		- data->plane->dir.y * sin(-0.02);
	data->plane->dir.y = olddirx * sin(-0.02)
		+ data->plane->dir.y * cos(-0.02);
	oldplanex = data->plane->plane.x;
	data->plane->plane.x = data->plane->plane.x
		* cos(-0.02) - data->plane->plane.y * sin(-0.02);
	data->plane->plane.y = oldplanex * sin(-0.02)
		+ data->plane->plane.y * cos(-0.02);
}

int	key_board(int key, t_data *data)
{
	double	olddirx;
	double	oldplanex;

	if (key == XK_Escape)
		ft_void_exit(data);
	key_board2(key, data);
	key_board3(key, data);
	if (key == 65361)
	{
		olddirx = data->plane->dir.x;
		data->plane->dir.x = data->plane->dir.x * cos(0.02)
			- data->plane->dir.y * sin(0.02);
		data->plane->dir.y = olddirx * sin(0.02)
			+ data->plane->dir.y * cos(0.02);
		oldplanex = data->plane->plane.x;
		data->plane->plane.x = data->plane->plane.x * cos(0.02)
			- data->plane->plane.y * sin(0.02);
		data->plane->plane.y = oldplanex * sin(0.02)
			+ data->plane->plane.y * cos(0.02);
	}
	if (key == 65363)
		key_board4(data, olddirx, oldplanex);
	return (0);
}

int	no_events(t_data *data)
{
	draw_rayons_all(data, data->plane);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	if (data)
		return (1);
	return (1);
}
