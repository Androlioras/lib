/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libsmlx.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:41:25 by pribault          #+#    #+#             */
/*   Updated: 2017/02/09 15:59:58 by pribault         ###   ########.fr       */
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
	int				personnal[100];
}					t_keys;

typedef struct		s_args
{
	double			**mat;
	t_point			vec;
	double			z;
}					t_args;

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
	t_list			*buttons;
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
}					t_image;

typedef struct		s_obj
{
	t_args			args;
	t_image			*texture;
	void			(*draw)(t_image*, t_args*);
	void			(*translate)(struct s_obj*, int, int);
	void			(*zoom)(struct s_obj*, double);
	void			(*rotate)(struct s_obj*, int);
}					t_obj;

typedef struct		s_button
{
	t_args			args;
	t_image			*texture;
	void			(*draw)(t_image*, t_args*);
	void			(*translate)(t_obj*, int, int);
	void			(*zoom)(t_obj*, double);
	void			(*rotate)(t_obj*, int);
	int				(*event)(struct s_button*, int, int);
	t_point			*p_a;
	t_point			*p_b;
	int				*k;
}					t_button;

/*
**	prototypes
*/

void				smlx_init(t_win *win, int w, int h, char *title);
void				smlx_set_flags(t_win *win, int flags);

t_image				*smlx_new_image(t_win *win, int w, int h);
t_image				*smlx_new_image_xpm(t_win *win, char *file);
void				smlx_put_img_to_img(t_image *i, t_image *t, t_args *args);
void				smlx_put_img_to_win(t_win *w, t_image *i, t_args *args);

void				smlx_destroy_image(t_win *win, t_image **img);
void				smlx_destroy_window(t_win *win);

void				smlx_clear_image(t_image *img);

void				smlx_key_hook(t_win *win);
int					smlx_hook_key_press(int k, t_win *win);
int					smlx_hook_key_release(int k, t_win *win);
int					smlx_hook_mouse_notify(int x, int y, t_win *win);
int					smlx_hook_button_press(int k, int x, int y, t_win *win);
int					smlx_hook_button_release(int k, int x, int y, t_win *win);

void				smlx_draw_line(t_image *img, t_pixel a, t_pixel b);
void				smlx_pixel_put(t_image *img, t_pixel p);

/*
**	buttons
*/

t_button			*smlx_new_button(t_image *img, t_point a, t_point b, int k);
void				smlx_destroy_button(t_button **button);

/*
**	rotate functions
*/

t_point				smlx_rotate_point(double **rot, t_point c, t_point p);
t_pixel				smlx_rotate_pixel(double **rot, t_point c, t_pixel p);

/*
**	create functions
*/

t_args				smlx_create_arg(int angle, int x, int y, double zoom);
t_pixel				smlx_create_pixel(int x, int y, t_uint c);
t_point				smlx_create_point(int x, int y);

/*
**	matrix functions
*/

void				smlx_rotate_matrix(double **mat, int angle);
void				smlx_invert_matrix(double **mat);
double				**smlx_create_matrix(int angle);
void				smlx_destroy_matrix(double **mat);
double				**smlx_copy_matrix(double **mat);

/*
**	translate functions
*/

t_pixel				smlx_translate(t_pixel p, t_point v);
void				smlx_translate_point(t_point *p, t_point *v);
void				smlx_translate_pixel(t_pixel *p, t_point *v);

/*
**	others
*/

t_pixel				smlx_mix_color(t_pixel a, t_uint b);

int					smlx_rad_to_deg(double rad);
double				smlx_deg_to_rad(int deg);

#endif
