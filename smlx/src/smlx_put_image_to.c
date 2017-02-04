/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_put_image_to.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:12:06 by pribault          #+#    #+#             */
/*   Updated: 2017/02/04 23:36:14 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsmlx.h"

static t_uint	smlx_def_color(t_image *i, t_pixel p, double r[2][2], double z)
{
	t_point	center;

	p.x = p.x / z - i->pos.x;
	p.y = p.y / z - i->pos.y;
	center = smlx_create_point(i->w / 2, i->h / 2);
	p = smlx_rotate_pixel(r, center, p);
	if (p.x < 0 || p.y < 0 || p.x >= i->w || p.y >= i->h)
		return (0xFF000000);
	return (i->l[p.y * i->size_l / 4 + p.x * i->bits / 32]);
}

void			smlx_put_image_to_image(t_image *img, t_image *to, double z)
{
	double	rot[2][2];
	t_pixel	p;
	t_uint	c;

	if (!z)
		return ;
	rot[0][0] = img->rot[0][0];
	rot[0][1] = -img->rot[0][1];
	rot[1][0] = -rot[0][1];
	rot[1][1] = rot[0][0];
	p = smlx_create_pixel(0, 0, 0);
	while (p.y < to->h)
	{
		p.x = 0;
		while (p.x < to->w)
		{
			c = to->l[p.y * to->size_l / 4 + p.x * to->bits / 32];
			p.c = smlx_def_color(img, p, rot, z);
			smlx_pixel_put(to, p);
			p.x++;
		}
		p.y++;
	}
}

void			smlx_put_image_to_window(t_win *win, t_image *img, double z)
{
	t_image	*tmp;

	if (!z)
		return ;
	tmp = smlx_new_image(win, win->w, win->h);
	smlx_put_image_to_image(img, tmp, z);
	mlx_put_image_to_window(win->mlx, win->win, tmp->img, 0, 0);
	smlx_destroy_image(win, &tmp);
}
