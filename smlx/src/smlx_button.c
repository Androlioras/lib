/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:06:48 by pribault          #+#    #+#             */
/*   Updated: 2017/02/08 16:56:32 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsmlx.h"

static int	smlx_button_event(t_button *button, int x, int y)
{
	double	**mat;
	t_point	p;
	t_point	c;

	if (!button)
		return (0);
	c.x = button->p_a->x + ft_abs(button->p_b->x - button->p_a->x) / 2;
	c.y = button->p_a->y + ft_abs(button->p_b->y - button->p_a->y) / 2;
	p = smlx_create_point(x + button->args.vec.x, y + button->args.vec.y);
	smlx_translate_point(&p, &(button->args.vec));
	mat = smlx_copy_matrix(button->args.mat);
	smlx_invert_matrix(mat);
	p = smlx_rotate_point(mat, c, p);
	smlx_delete_matrix(mat);
	if (p.x < button->p_a->x || p.x > button->p_b->x)
		return (0);
	if (p.y < button->p_a->y || p.y > button->p_b->y)
		return (0);
	return (1);
}

t_button	*smlx_new_button(t_image *img, t_point a, t_point b, int k)
{
	t_button	*button;

	if (k >= 100)
		return (NULL);
	if (!(button = (t_button*)malloc(sizeof(t_button))))
		return (NULL);
	button->args = smlx_create_arg(0, a.x, a.y, 0);
	button->texture = img;
	button->p_a = (t_point*)malloc(sizeof(t_point));
	button->p_b = (t_point*)malloc(sizeof(t_point));
	*(button->p_a) = a;
	*(button->p_b) = b;
	button->k = img->win->keys.personnal + k;
	button->event = &smlx_button_event;
	return (button);
}

// void		smlx_destroy_button(t_button **button)
// {
// }
