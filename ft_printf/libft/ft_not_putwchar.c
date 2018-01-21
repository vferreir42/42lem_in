/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_not_putwchar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:35:52 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/26 13:10:21 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_not_putwchar(int value)
{
	if (value < 128)
		return (1);
	else if (value < 2048)
		return (2);
	else if (value < 65536)
		return (3);
	else if (value < 2097152)
		return (4);
	return (0);
}
