/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:52:45 by pribault          #+#    #+#             */
/*   Updated: 2017/02/08 13:55:49 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsmlx.h"

typedef struct	s_main
{
	t_win		*win;
	t_image		*img1;
	t_image		*img2;
}				t_main;

int		hook_loop(t_main *main)
{
	t_pixel	a;
	t_pixel	b;
	t_pixel	c;
	t_pixel	d;
	t_pixel	bord[4];
	static t_args	arg;

	if (!arg.mat)
		arg = smlx_create_arg(0, 0, 0, 1);
	if (main->win->keys.tab[53])
	{
		smlx_destroy_image(main->win, &(main->img1));
		smlx_destroy_window(main->win);
		ft_free_array((void**)arg.mat, 2);
		exit(0);
	}
	if (main->win->keys.tab[123])
		smlx_rotate_matrix(arg.mat, -5);
	if (main->win->keys.tab[124])
		smlx_rotate_matrix(arg.mat, 5);
	if (main->win->keys.tab[126])
		arg.z *= 1.1;
	if (main->win->keys.tab[125])
		arg.z /= 1.1;
	// printf("[%f][%f]\n[%f][%f]\n\n", m[0][0], m[0][1], m[1][0], m[1][1]);
	// ft_printf("w: %d | h: %d\n", main->img2->w, main->img2->h);
	mlx_clear_window(main->win->mlx, main->win->win);
	smlx_clear_image(main->img1);
	// a = smlx_create_pixel(100, 100, 0xFF00FF);
	// b = smlx_create_pixel(320, 100, 0xFFFF);
	// c = smlx_create_pixel(320, 320, 0xFF00FF);
	// d = smlx_create_pixel(100, 320, 0xFFFF00);
	bord[0] = smlx_create_pixel(0, 0, 0xFF);
	bord[1] = smlx_create_pixel(main->img2->w - 1, 0, 0xFF);
	bord[2] = smlx_create_pixel(main->img2->w - 1, main->img2->h - 1, 0xFF);
	bord[3] = smlx_create_pixel(0, main->img2->h - 1, 0xFF);
	// smlx_clear_image(main->img2);
	// smlx_draw_line(main->img2, b, c);
	// smlx_draw_line(main->img2, c, d);
	// smlx_draw_line(main->img2, d, a);
	smlx_draw_line(main->img2, bord[0], bord[1]);
	smlx_draw_line(main->img2, bord[1], bord[2]);
	smlx_draw_line(main->img2, bord[2], bord[3]);
	smlx_draw_line(main->img2, bord[3], bord[0]);
	// smlx_put_img_to_img(main->img2, main->img1, m, smlx_create_point(0, 0), zoom);
	// smlx_put_img_to_img(main->img2, main->img1, smlx_create_point(50, 50), zoom);
	// smlx_put_img_to_img(main->img2, main->img1, smlx_create_point(200, 200), zoom);
	// smlx_put_img_to_img(main->img2, main->img1, smlx_create_point(300, 300), zoom);
	smlx_put_img_to_win(main->win, main->img2, &arg);
	// mlx_put_image_to_window(main->win->mlx, main->win->win, main->img1->img, 0, 0);
	return (1);
}

int		main(int argc, char **argv)
{
	t_main	main;
	t_win	win;
	t_image	*img;
	t_image	*img2;

	smlx_init(&win, 640, 480, "test");
	smlx_set_flags(&win, SMLX_ROTATION | SMLX_C_SLOPE | SMLX_MOTION);
	img = smlx_new_image(&win, 640, 480);
	img2 = smlx_new_image_xpm(&win, "unicorn_2.xpm");
	main.win = &win;
	main.img1 = img;
	main.img2 = img2;
	smlx_key_hook(&win);
	mlx_loop_hook(win.mlx, &hook_loop, &main);
	mlx_loop(win.mlx);
	return (0);
}
