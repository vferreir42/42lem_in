/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:25:44 by vferreir          #+#    #+#             */
/*   Updated: 2017/11/15 16:50:28 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str, const char *aiguille)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (aiguille[count])
		count++;
	if (count == 0)
		return ((char *)str);
	while (str[i])
	{
		while (str[i] == aiguille[j])
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
