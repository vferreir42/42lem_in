/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:25:44 by vferreir          #+#    #+#             */
/*   Updated: 2017/11/17 16:00:48 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *aig, size_t n)
{
	size_t	i;
	int		j;
	int		count;

	if (ft_strlen(str) == 0)
		return (0);
	i = 0;
	j = 0;
	count = 0;
	count = ft_strlen(aig);
	if (count == 0)
		return ((char *)str);
	while (str[i] && i < n)
	{
		while (str[i] == aig[j] && i < n)
		{
			j++;
			if (count == j)
				return ((char *)str + i + 1 - count);
			i++;
		}
		i = i - j + 1;
		j = 0;
	}
	return (0);
}
