/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:21:02 by vferreir          #+#    #+#             */
/*   Updated: 2017/11/16 13:36:08 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*newsrc;
	unsigned char	*newdest;

	newsrc = (unsigned char *)src;
	newdest = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		newdest[i] = newsrc[i];
		i++;
	}
	return (dest);
}
