/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 19:16:49 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/26 13:09:50 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putwchar_bigvalue(int put, int value)
{
	put = (240 | value >> 16);
	write(1, &put, 1);
	put = (128 | (63 & value >> 12));
	write(1, &put, 1);
	put = (128 | (63 & value >> 6));
	write(1, &put, 1);
	put = (128 | (63 & value));
	write(1, &put, 1);
	return (4);
}

static int	ft_putwchar_mediumvalue(int put, int value)
{
	put = (224 | value >> 12);
	write(1, &put, 1);
	put = (128 | (63 & value >> 6));
	write(1, &put, 1);
	put = (128 | (63 & value));
	write(1, &put, 1);
	return (3);
}

int			ft_putwchar(int value)
{
	int put;

	put = 0;
	if (value < 128)
	{
		write(1, &value, 1);
		return (1);
	}
	else if (value < 2048)
	{
		put = (192 | value >> 6);
		write(1, &put, 1);
		put = 128 | (63 & value);
		write(1, &put, 1);
		return (2);
	}
	else if (value < 65536)
		return (ft_putwchar_mediumvalue(put, value));
	else if (value < 2097152)
		return (ft_putwchar_bigvalue(put, value));
	return (0);
}
