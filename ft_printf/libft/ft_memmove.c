/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:18:47 by vferreir          #+#    #+#             */
/*   Updated: 2017/11/17 18:09:53 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *newdest;
	unsigned char *newsrc;

	newdest = (unsigned char *)dest;
	newsrc = (unsigned char *)src;
	if (newsrc < newdest)
	{
		while (n)
		{
			n--;
			newdest[n] = newsrc[n];
		}
	}
	else
	{
		ft_memcpy(newdest, newsrc, n);
	}
	return (dest);
}
