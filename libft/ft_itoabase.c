/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 20:40:10 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/27 15:21:42 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long	ft_puissance(unsigned long long nb, int pui)
{
	int				i;
	unsigned long	sauvnb;

	if (pui == 0)
		return (1);
	i = 1;
	sauvnb = nb;
	while (i < pui)
	{
		nb *= sauvnb;
		i++;
	}
	return (nb);
}

char					*ft_itoabase(unsigned long long value, int base)
{
	int				i;
	char			*nbr;
	unsigned long	yo;

	yo = 1000000000000000000;
	i = 1;
	while (ft_puissance(base, i) - 1 < value)
	{
		if (ft_puissance(base, i) == 0)
			break ;
		i++;
	}
	if (value >= (8446744073709551610 + 10 * yo) && base == 10)
		i = 20;
	nbr = (char*)malloc(sizeof(nbr) * i + 1);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (value % base) + (value % base > 9 ? 'A' - 10 : '0');
		value = value / base;
	}
	return (nbr);
}
