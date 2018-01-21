/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:55:39 by vferreir          #+#    #+#             */
/*   Updated: 2017/11/15 16:14:53 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*newstr;
	unsigned char	c2;

	newstr = (unsigned char *)s;
	c2 = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (newstr[i] == c2)
			return ((void *)s + i);
		i++;
	}
	return (0);
}
