/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 08:39:12 by vferreir          #+#    #+#             */
/*   Updated: 2017/11/16 14:15:21 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*new;
	char	*s2;

	if (s == NULL || f == NULL)
		return (NULL);
	s2 = (char *)s;
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	i = 0;
	while (s[i])
	{
		new[i] = f(s2[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
