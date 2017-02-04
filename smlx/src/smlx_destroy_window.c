/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_destroy_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:50:31 by pribault          #+#    #+#             */
/*   Updated: 2017/02/03 16:14:09 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libsmlx.h"

void	smlx_destroy_window(t_win *win)
{
	if (!win)
		return ;
	free(win->title);
	mlx_destroy_window(win->mlx, win->win);
}
