/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 21:19:24 by pribault          #+#    #+#             */
/*   Updated: 2017/02/04 10:40:49 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsmlx.h"

void	smlx_rotate_image(t_image *img, int angle)
{
	double	rad;

	rad = (img->rot[0][1] < 0) ? acos(img->rot[0][0]) : -acos(img->rot[0][0]);
	rad = fmod(rad + smlx_deg_to_rad(angle), 2 * PI);
	img->rot[0][0] = cos(rad);
	img->rot[0][1] = -sin(rad);
	img->rot[1][0] = -img->rot[0][1];
	img->rot[1][1] = img->rot[0][0];
}

t_pixel	smlx_rotate_pixel(double rot[2][2], t_point c, t_pixel p)
{
	t_pixel	r;

	r.c = p.c;
	r.x = (p.x - c.x) * rot[0][0] + (p.y - c.y) * rot[0][1] + c.x;
	r.y = (p.x - c.x) * rot[1][0] + (p.y - c.y) * rot[1][1] + c.y;
	return (r);
}
