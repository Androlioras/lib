/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_draw_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:16:52 by pribault          #+#    #+#             */
/*   Updated: 2017/02/04 20:08:55 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsmlx.h"

static t_pixel	define_color(t_win *win, t_pixel a, t_pixel b, t_pixel i)
{
	double	r;
	double	ab;
	double	ib;

	if (!win->flags.c_slope)
		return (i);
	ab = ft_sqrt(ft_power(b.x - a.x, 2) + ft_power(b.y - a.y, 2));
	ib = ft_sqrt(ft_power(b.x - i.x, 2) + ft_power(b.y - i.y, 2));
	r = (ab != 0) ? ib / ab : 0;
	i.c = (t_uint)(r * (a.c & 0xFF000000) + (1.0 - r) * (b.c & 0xFF000000));
	i.c = i.c & 0xFF000000;
	i.c += (t_uint)(r * (a.c & 0xFF0000) + (1.0 - r) * (b.c & 0xFF0000));
	i.c = i.c & 0xFFFF0000;
	i.c += (t_uint)(r * (a.c & 0xFF00) + (1.0 - r) * (b.c & 0xFF00));
	i.c = i.c & 0xFFFFFF00;
	i.c += (t_uint)(r * (a.c & 0xFF) + (1.0 - r) * (b.c & 0xFF));
	return (i);
}

void			smlx_draw_line(t_image *img, t_pixel a, t_pixel b)
{
	t_point		center;
	t_pixel		i;
	double		c;
	int			d;
	int			y;

	center = smlx_create_point(img->w / 2, img->h / 2);
	i = a;
	c = (a.x != b.x) ? ((double)(a.y - b.y) / (a.x - b.x)) : 0;
	d = (a.y < b.y) ? a.y - a.x * c : b.y - b.x * c;
	i.y = c * i.x + d;
	if (a.x == b.x)
		d = (a.y < b.y) ? b.y : a.y;
	while ((a.x < b.x) ? i.x < b.x : i.x >= b.x)
	{
		y = (i.x < b.x) ? c * (i.x + 1) + d : c * (i.x - 1) + d;
		y = (i.x == b.x) ? c * b.x + d : y;
		smlx_pixel_put(img, define_color(img->win, a, b, i));
		if ((i.y < y) ? i.y < y - 1 : i.y > y + 1)
			i.y += (i.y < y) ? 1 : -1;
		else
			i.x += (a.x < b.x) ? 1 : -1;
	}
}
