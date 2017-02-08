/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 12:53:39 by pribault          #+#    #+#             */
/*   Updated: 2017/02/08 15:26:52 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsmlx.h"

t_args	smlx_create_arg(int angle, int x, int y, double zoom)
{
	t_args	arg;

	arg.mat = smlx_create_matrix(angle);
	arg.vec = smlx_create_point(x, y);
	arg.z = zoom;
	return (arg);
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
