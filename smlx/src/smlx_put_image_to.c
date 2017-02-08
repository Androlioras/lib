/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_put_image_to.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:12:06 by pribault          #+#    #+#             */
/*   Updated: 2017/02/08 13:53:44 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsmlx.h"

static t_uint	smlx_def_color(t_image *i, t_pixel p, double **r, double z)
{
	t_point	center;

	p.x = p.x / z;
	p.y = p.y / z;
	center = smlx_create_point(i->w / 2, i->h / 2);
	p = smlx_rotate_pixel(r, center, p);
	if (p.x < 0 || p.y < 0 || p.x >= i->w || p.y >= i->h)
		return (0xFF000000);
	return (i->l[p.y * i->size_l / 4 + p.x * i->bits / 32]);
}

static t_point	set_min(t_image *i, t_point p, double z)
{
	t_point	center;
	t_point	m;

	center = smlx_create_point(i->w / 2, i->h / 2);
	m.x = center.x - (ft_sqrt(ft_power(center.x, 2) + ft_power(center.y, 2)));
	m.y = center.y - (ft_sqrt(ft_power(center.x, 2) + ft_power(center.y, 2)));
	m.x = m.x * z + p.x;
	m.y = m.y * z + p.y;
	m.x = (m.x < 0) ? 0 : m.x;
	m.y = (m.y < 0) ? 0 : m.y;
	return (m);
}

static t_point	set_max(t_image *i, t_point p, double z)
{
	t_point	center;
	t_point	m;

	center = smlx_create_point(i->w / 2, i->h / 2);
	m.x = center.x + (ft_sqrt(ft_power(center.x, 2) + ft_power(center.y, 2)));
	m.y = center.y + (ft_sqrt(ft_power(center.x, 2) + ft_power(center.y, 2)));
	m.x = m.x * z + p.x;
	m.y = m.y * z + p.y;
	return (m);
}

void			smlx_put_img_to_img(t_image *i, t_image *t, t_args *a)
{
	t_pixel	px;
	t_point	max[2];
	t_uint	c;
	double	**m;

	if (a->mat[0][1] < 0)
		m = smlx_create_matrix(acos(a->mat[0][0]));
	else
		m = smlx_create_matrix(-acos(a->mat[0][0]));
	max[0] = set_min(i, a->vec, a->z);
	max[1] = set_max(i, a->vec, a->z);
	px = smlx_create_pixel(max[0].x, max[0].y, 0);
	while (px.y < max[1].y && px.y < t->h)
	{
		px.x = 0;
		while (px.x < max[1].x && px.x < t->w)
		{
			c = t->l[px.y * t->size_l / 4 + px.x * t->bits / 32];
			px.c = smlx_def_color(i, smlx_translate(px, a->vec), a->mat, a->z);
			smlx_pixel_put(t, smlx_mix_color(px, c));
			px.x++;
		}
		px.y++;
	}
	ft_free_array((void**)m, 2);
}

void			smlx_put_img_to_win(t_win *w, t_image *i, t_args *a)
{
	t_image	*tmp;

	if (!a->z)
		return ;
	tmp = smlx_new_image(w, w->w, w->h);
	smlx_put_img_to_img(i, tmp, a);
	mlx_put_image_to_window(w->mlx, w->win, tmp->img, 0, 0);
	smlx_destroy_image(w, &tmp);
}
