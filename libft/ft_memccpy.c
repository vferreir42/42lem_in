/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:21:02 by vferreir          #+#    #+#             */
/*   Updated: 2017/11/16 13:47:10 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*newsrc;
	unsigned char	*newdest;
	unsigned char	c2;

	newsrc = (unsigned char *)src;
	newdest = (unsigned char *)dest;
	c2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		newdest[i] = newsrc[i];
		if (newsrc[i] == c2)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
