/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 04:08:34 by motaouss          #+#    #+#             */
/*   Updated: 2023/07/24 20:07:28 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	color_trgb(int t, t_rgb rgb)
{
	return (t << 24 | rgb.r << 16 | rgb.g << 8 | rgb.b);
}

int	check_rgb2(char **file, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	y = j;
	if (file[i][1] == ',')
		return (1);
	while (file[i][y])
	{
		if (file[i][y] >= '0' && file[i][y] <= '9')
		{
			x++;
			while (file[i][y] >= '0' && file [i][y] <= '9' && file[i][y])
				y++;
		}
		else
			y++;
	}
	if (x != 3)
		return (1);
	else
		return (0);
}

int	check_rgb(char **file, int i, int j, int d)
{
	if (d != 0)
		return (1);
	if (check_rgb2(file, i, j))
		return (1);
	while (file[i][j])
	{
		if ((file[i][j] >= '0' && file[i][j] <= '9') || file[i][j] == ','
				|| file[i][j] == ' ' || file[i][j] == '\t' || !file[i][j])
			j++;
		else
			return (1);
	}
	return (0);
}

int	fill_color(char **file, int i, int j, int d)
{
	char	s[150];
	t_rgb	rgb;
	int		k;
	int		color;

	color = 1;
	k = 0;
	fill_rgb(&rgb, s, color, 0);
	if (check_rgb(file, i, j, d))
		return (printf("Error R,G,B\n"), -1);
	while (file[i][j])
	{
		if (file[i][j] >= 48 && file[i][j] <= 57)
			s[k++] = file[i][j];
		if (file[i][++j] == ',' || !file[i][j])
		{
			s[k] = 0;
			fill_rgb(&rgb, s, color++, 1);
			k = 0;
		}
	}
	if (check_color(rgb.r, rgb.g, rgb.b))
		return (-1);
	return (color_trgb(0, rgb));
}

bool	split_file(char **file, t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (file[++i] && check_val(cub))
	{
		j = 0;
		while (is_line(file[i]))
			i++;
		while (file[i][j] == ' ' || file[i][j] == '\t')
			j++;
		check_ndwe(file, cub, i, j);
		if ((file[i][j] == 'F' || file[i][j] == 'C'))
		{
			if (file[i][j] == 'F')
				cub->f = fill_color(file, i, (j + 1), cub->f);
			else
				cub->c = fill_color(file, i, (j + 1), cub->c);
			if (cub->f == -1 || cub->c == -1)
				return (1);
		}
	}
	if (!file[i] || cub->error)
		return (printf(ERRORMGL), 1);
	return (init_map(file, cub, i));
}
