/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:23:39 by vferreir          #+#    #+#             */
/*   Updated: 2017/11/19 17:45:51 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	d;
	int		retour;

	d = ft_strlen(dest);
	retour = ft_min(n, d) + ft_strlen(src);
	i = 0;
	if (n == 0)
		return (retour);
	while ((d + i < n - 1) && src[i])
	{
		dest[i + d] = src[i];
		i++;
	}
	dest[d + i] = '\0';
	return (retour);
}
