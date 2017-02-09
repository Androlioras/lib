/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:27:30 by pribault          #+#    #+#             */
/*   Updated: 2017/02/09 15:59:41 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsmlx.h"

void	smlx_translate_point(t_point *p, t_point *v)
{
	p->x += v->x;
	p->y += v->y;
}

void	smlx_translate_pixel(t_pixel *p, t_point *v)
{
	p->x += v->x;
	p->y += v->y;
}
