/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 18:34:03 by motaouss          #+#    #+#             */
/*   Updated: 2023/07/18 18:53:48 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	init_draw(t_drawrays *draw)
{
	draw->pwall = 0;
	draw->lineh = 0;
	draw->texnum = 0;
	draw->tex = 0;
	draw->draw = 0;
	draw->texpos = 0;
	draw->color = 0;
	draw->y = 0;
	draw->step = 0;
	draw->wallx = 0;
}

void	draw(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->win_y)
	{
		x = 0;
		while (x < data->win_x)
		{
			data->addr[data->win_x * y + x] = data->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	texto(t_data *data, int i)
{
	if (data->text[i].path == NULL)
		return (0);
	data->text[i].img = mlx_xpm_file_to_image(data->mlx, data->text[i].path,
			& data->text[i].texwidth, & data->text[i].texheight);
	if (data->text[i].img == NULL)
		return (printf("Error texture\n"), 0);
	data->text[i].addr = (int *)mlx_get_data_addr(data->text[i].img,
			&data->text[i].bpp, &data->text[i].size_l, &data->text[i].endian);
	data->texture[i] = malloc(sizeof(int) * 4096);
	return (1);
}
