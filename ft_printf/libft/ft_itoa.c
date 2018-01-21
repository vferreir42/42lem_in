/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:13:37 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/26 13:12:20 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		negatif(long long n)
{
	int		neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	return (neg);
}

static int		calsize(long long n)
{
	int		t;

	t = 1;
	while (n > 9)
	{
		n /= 10;
		t++;
	}
	return (t);
}

char			*ft_itoa(long long n)
{
	char	*str;
	int		i;
	int		size;
	int		neg;

	if ((neg = negatif(n)) == 1)
		n = -n;
	size = calsize(n);
	if ((str = ft_strnew(size + neg)) == 0)
		return (0);
	i = 0;
	if (neg == 1)
		str[0] = '-';
	while (i + neg < calsize(n) + neg)
	{
		str[i + neg] = (n / ft_puissancedix(size - 1)) % 10 + '0';
		i++;
		size--;
	}
	return (str);
}
