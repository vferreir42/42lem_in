/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:26:43 by vferreir          #+#    #+#             */
/*   Updated: 2017/11/19 19:13:50 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sizebefore(const char *s, int start, char c)
{
	int		i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		i++;
	}
	return (i);
}

static int		nbworld(const char *cast, char c)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (cast[i])
	{
		while (cast[i] == c && cast[i])
			i++;
		if (cast[i] != c && cast[i])
			nb++;
		while (cast[i] != c && cast[i])
			i++;
	}
	return (nb);
}

static char		**nocaractere(const char *s)
{
	char	**new;

	if (!(new = malloc(sizeof(char *) * 2)))
		return (0);
	if (!(new[0] = malloc(sizeof(char *) * ft_strlen(s) + 1)))
		return (0);
	new[0] = ft_strcpy(new[0], s);
	new[1] = NULL;
	return (new);
}

static char		**nos(void)
{
	char	**new;

	if (!(new = malloc(sizeof(char *) * 1)))
		return (0);
	new = NULL;
	return (new);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	int		i;
	int		etage;

	if (s == NULL)
		return (nos());
	if (ft_strchr(s, c) == NULL && s[0] != '\0')
		return (nocaractere(s));
	if (!(new = malloc(sizeof(char *) * (nbworld(s, c) + 1))))
		return (0);
	i = 0;
	etage = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			if (!(new[etage++] = ft_strsub(s, i, sizebefore(s, i, c))))
				return (0);
			i = sizebefore(s, i, c) + i;
		}
	}
	new[etage] = NULL;
	return (new);
}
