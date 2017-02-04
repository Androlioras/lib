/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pribault <pribault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:20:49 by pribault          #+#    #+#             */
/*   Updated: 2017/01/23 22:41:52 by pribault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s);
	len = (n < len) ? n : len;
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	ft_memcpy(s2, s, len);
	s2[len] = '\0';
	return (s2);
}
