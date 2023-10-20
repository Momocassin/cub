/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motaouss <motaouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:26:35 by edvicair          #+#    #+#             */
/*   Updated: 2023/07/18 19:00:57 by motaouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define PI 3.14159265359
# define WIDTH 640
# define HEIGHT 480
# define ERRORMGL "Error : Need NO, SO, WE, EA, F, C and a map in .cub\n"

typedef double	t_luno2f	__attribute__((ext_vector_type(2)));
typedef int		t_luno2i	__attribute__((ext_vector_type(2)));

typedef struct t_drawrays
{
	double				pwall;
	int					lineh;
	int					texnum;
	t_luno2i			tex;
	t_luno2i			draw;
	double				texpos;
	int					color;
	int					y;
	double				step;
	double				wallx;

}						t_drawrays;

typedef struct s_plane
{
	t_luno2f			camera;
	t_luno2i			map;
	t_luno2f			pos;
	t_luno2f			raydir;
	t_luno2f			dir;
	t_luno2f			plane;
	t_luno2f			deltadist;
	int					side;
	t_luno2f			step;
	t_luno2f			sdist;
	int					hit;
	double				movespeed;
	double				rotspeed;
	int					buff[540][960];
	int					**texture;
	int					re_buf;
}						t_plane;

typedef struct s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

typedef struct s_cub
{
	char				*wall_n;
	char				*wall_s;
	char				*wall_w;
	char				*wall_e;
	int					f;
	int					c;
	int					height;
	int					width;
	char				**map;
	int					error;
}						t_cub;

typedef struct s_text
{
	void				*img;
	char				*path;
	int					*addr;
	int					texx;
	int					texy;
	int					texwidth;
	int					texheight;
	char				*textu;
	double				texpos;
	int					charint;
	int					texnum;
	double				step;
	int					pitch;
	int					bpp;
	int					size_l;
	int					endian;
}						t_text;

typedef struct s_data
{
	int					rebuf;
	int					*addr;
	void				*mlx;
	void				*mlx_win;
	void				*img;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
	int					color;
	int					win_x;
	int					win_y;
	float				px;
	float				py;
	int					squarex;
	int					squarey;
	t_cub				*cub;
	t_text				text[4];
	int					*texture[4];
	int					buf[1000][1000];
	t_plane				*plane;
}						t_data;

// LIB //
char					*get_next_line(int fd, int val);
char					*ft_strjoin(char *s1, const char *s2);
char					*ft_strchr(const char *s, int c);
char					*ft_substr(const char *s, unsigned int start,
							size_t len, bool ret);
int						ft_strncmp(const char *s1, const char *s2, size_t n);

char					*ft_strdup(const char *s);
size_t					ft_strlen(const char *s);
void					free_double(char **str);
int						ft_atoi(const char *nptr);
void					*ft_calloc(size_t nmemb, size_t size);

// PARSING //
bool					parser(t_cub *cub, char **av);
bool					is_line(char *file);
bool					check_val(t_cub *cub);
bool					check_ndwe(char **file, t_cub *cub, int i, int j);
int						check_cub(char **av);
bool					init_map(char **file, t_cub *cub, int i);
bool					check_map(t_cub cub);
bool					error_map(char **map, int x);
bool					error_map2(char **map, int x, int y);
bool					error_edge(char **map, int x);
bool					check_color(int r, int g, int b);
bool					malloc_cub(t_cub *cub);
int						fill_map(char **file, t_cub *cub, int min, int max);
bool					split_file(char **file, t_cub *cub);
void					fill_rgb(t_rgb *rgb, char *s, int color, int x);

// MLX //
int						init_mlx(t_data *data);
void					my_mlx_pixel_put(t_data *data, int x, int y, int color);
void					player_pos(t_data *data, int color);
void					colored(t_data *data);
void					find_player(t_data *data);
void					player_data(t_data *data);
void					init_text(t_text *text[4]);
void					textorder(t_text text[4], t_cub *cub);
int						fill_text(t_data *data);
double					sides(t_plane *p);
t_luno2i				get_draw(int lineh);
double					get_wall_x(t_plane *p, double pwall);
int						get_tex_x(t_plane *p, double wallx);
void					init_cast(t_plane *plane, int index);
void					init_steps(t_plane *p);
void					init_draw(t_drawrays *r);
void					draw_rayons_all_2(t_data *data, t_drawrays *r,
							t_plane *p, int i);
void					draw_rayons_all(t_data *data, t_plane *p);
void					dda(t_data *data, t_plane *p);
void					wall_color(t_plane *p, int *color, t_luno2i tex,
							t_data *data);
void					draw(t_data *data);
int						texto(t_data *data, int i);
void					free_walls(t_cub *cub);
int						ft_void_exit(t_data *data);

// KEY //
int						key_board(int key, t_data *data);
int						no_events(t_data *data);
int						ft_void_exit(t_data *data);
void					map_display(t_data *data);

#endif
