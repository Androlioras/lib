/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsmlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:41:25 by pribault          #+#    #+#             */
/*   Updated: 2017/02/04 23:36:42 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	The smlx lib require mlx and libft, please compile with:
**	-framework OpenGL -gramework Appkit -lmlx -lft
*/

#ifndef LIBSMLX_H
# define LIBSMLX_H

/*
**	includes
*/

# include "ft_printf.h"
# include <mlx.h>
# include <math.h>

# define SMLX_ROTATION		0x1
# define SMLX_C_SLOPE		0x10
# define SMLX_MOTION		0x100

# define PI					3.1415926535

# define TAB_SIZE			300

typedef unsigned int		t_uint;

/*
**	structures
*/

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_pixel
{
	int				x;
	int				y;
	t_uint			c;
}					t_pixel;

typedef struct		s_keys
{
	int				tab[TAB_SIZE];
	int				mouse[2];
}					t_keys;

typedef struct		s_camera
{
	t_point			pos;
	int				h;
	int				w;
}					t_camera;

typedef struct		s_win_flags
{
	unsigned char	rotation;
	unsigned char	c_slope;
	unsigned char	motion;
}					t_win_flags;

typedef struct		s_win
{
	void			*win;
	void			*mlx;
	char			*title;
	t_win_flags		flags;
	t_keys			keys;
	int				w;
	int				h;
}					t_win;

typedef struct		s_image
{
	t_win			*win;
	int				h;
	int				w;
	void			*img;
	t_uint			*l;
	int				depth;
	int				bits;
	int				size_l;
	int				endian;
	double			rot[2][2];
	t_point			pos;
}					t_image;

/*
**	prototypes
*/

void				smlx_init(t_win *win, int w, int h, char *title);
void				smlx_set_flags(t_win *win, int flags);

t_image				*smlx_new_image(t_win *win, int w, int h);
t_image				*smlx_new_image_xpm(t_win *win, char *file);
void				smlx_put_image_to_image(t_image *i, t_image *to, double z);
void				smlx_put_image_to_window(t_win *win, t_image *i, double z);

void				smlx_destroy_image(t_win *win, t_image **img);
void				smlx_destroy_window(t_win *win);

void				smlx_clear_image(t_image *img);

void				smlx_key_hook(t_win *win);
int					smlx_hook_key_press(int k, t_win *win);
int					smlx_hook_key_release(int k, t_win *win);
int					smlx_hook_mouse_notify(int x, int y, t_win *win);
int					smlx_hook_button_press(int k, int x, int y, t_win *win);
int					smlx_hook_button_release(int k, int x, int y, t_win *win);

void				smlx_rotate_image(t_image *img, int angle);
t_pixel				smlx_rotate_pixel(double rot[2][2], t_point c, t_pixel p);

void				smlx_draw_line(t_image *img, t_pixel a, t_pixel b);
void				smlx_pixel_put(t_image *img, t_pixel p);

t_pixel				smlx_create_pixel(int x, int y, t_uint c);
t_point				smlx_create_point(int x, int y);

int					smlx_rad_to_deg(double rad);
double				smlx_deg_to_rad(int deg);

#endif
