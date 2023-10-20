/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 06:05:36 by edvicair          #+#    #+#             */
/*   Updated: 2023/07/18 17:41:14 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(667);
	data->color = 2667619;
	data->win_x = 640;
	data->win_y = 480;
	data->mlx_win = NULL;
	data->mlx_win = mlx_new_window(data->mlx,
			data->win_x, data->win_y, "ZB0UB3D");
	if (data->mlx_win == NULL)
		exit(667);
	data->img = mlx_new_image(data->mlx, data->win_x, data->win_y);
	data->addr = (int *)mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	return (1);
}

void	init_plane(t_plane *plane, t_data *data)
{
	plane->movespeed = 0.09;
	plane->rotspeed = 0.09;
	player_data(data);
}

void	finito(t_data *data)
{
	int	i;

	i = -1;
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->mlx_win);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	while (data->cub->map[++i])
		free(data->cub->map[i]);
	free(data->cub->map);
	free_walls(data->cub);
	i = -1;
	while (++i < 4)
		free(data->texture[i]);
}

void	frifri(t_cub *cub)
{
	get_next_line(1, 1);
	free_double(cub->map);
	free_walls(cub);
}

int	main(int ac, char **av)
{
	static t_cub	cub = {0};
	static t_data	data = {0};
	static t_plane	plane = {0};

	if (ac != 2)
		return (printf("./cub3D [*.cub]\n"));
	if (parser(&cub, av))
		return (frifri(& cub), printf("Error parsing\n"));
	data.plane = &plane;
	data.cub = &cub;
	if (!(init_mlx(&data)))
		return (printf("mlx error\n"), 0);
	if (!(fill_text(&data)))
		return (finito(&data), 0);
	init_plane(&plane, &data);
	mlx_hook(data.mlx_win, 33, 1L << 17, ft_void_exit, &data);
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, key_board, &data);
	mlx_loop_hook(data.mlx, no_events, &data);
	mlx_hook(data.mlx_win, KeyRelease, KeyReleaseMask, key_board, &data);
	mlx_loop(data.mlx);
	finito(&data);
}
