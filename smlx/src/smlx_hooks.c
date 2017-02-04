/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 17:26:23 by pribault          #+#    #+#             */
/*   Updated: 2017/02/04 23:19:18 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsmlx.h"

int		smlx_hook_key_press(int k, t_win *win)
{
	if (k >= TAB_SIZE)
		return (0);
	win->keys.tab[k] = 1;
	return (1);
}

int		smlx_hook_key_release(int k, t_win *win)
{
	if (k >= TAB_SIZE)
		return (0);
	win->keys.tab[k] = 0;
	return (1);
}

int		smlx_hook_mouse_notify(int x, int y, t_win *win)
{
	win->keys.mouse[0] = x;
	win->keys.mouse[1] = y;
	return (1);
}

int		smlx_hook_button_press(int k, int x, int y, t_win *win)
{
	win->keys.mouse[0] = x;
	win->keys.mouse[1] = y;
	if (k >= TAB_SIZE)
		return (0);
	win->keys.tab[k] = 1;
	return (1);
}

int		smlx_hook_button_release(int k, int x, int y, t_win *win)
{
	win->keys.mouse[0] = x;
	win->keys.mouse[1] = y;
	if (k >= TAB_SIZE)
		return (0);
	win->keys.tab[k] = 0;
	return (1);
}
