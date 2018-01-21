/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 17:07:53 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/26 13:01:54 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strwlen(wchar_t *str)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (str[++i])
		count += ft_not_putwchar(str[i]);
	return (count);
}
