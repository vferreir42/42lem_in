/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:12:52 by vferreir          #+#    #+#             */
/*   Updated: 2017/11/17 15:50:03 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sizestr(char const *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i])
	{
		i++;
		count++;
	}
	i--;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
	{
		i--;
		if (count > 0)
			count--;
	}
	return (count);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		t;
	int		len;
	char	*cast;
	char	*new;

	if (s == NULL)
		return (NULL);
	cast = (char *)s;
	if (!(new = (char *)malloc(sizeof(char) * (sizestr(s) + 1))))
		return (0);
	t = 0;
	while (s[t] == ' ' || s[t] == '\t' || s[t] == '\n')
		t++;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len - 1] == '\n')
		len--;
	i = 0;
	while (t < len)
		new[i++] = s[t++];
	new[i] = '\0';
	return (new);
}
