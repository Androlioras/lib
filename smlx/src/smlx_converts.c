/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_converts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:42:50 by pribault          #+#    #+#             */
/*   Updated: 2017/02/03 22:21:52 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsmlx.h"

double	smlx_deg_to_rad(int deg)
{
	return (deg * 2 * PI / 360);
}

int		smlx_rad_to_deg(double rad)
{
	return (rad * 360 / (2 * PI));
}

t_pixel	smlx_create_pixel(int x, int y, t_uint c)
{
	t_pixel	p;

	p.x = x;
	p.y = y;
	p.c = c;
	return (p);
}

t_point	smlx_create_point(int x, int y)
{
	t_point	p;

	p.x = x;
	p.y = y;
	return (p);
}
