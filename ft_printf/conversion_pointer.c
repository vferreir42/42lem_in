/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:24:43 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/26 11:25:39 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_delstrjoin(char *one, char *two)
{
	char *temp;

	temp = ft_strjoin(one, two);
	free(two);
	return (temp);
}

static void	c_pointer_else(unsigned long argv, t_map *map, char *str, int t)
{
	if (map->precision > 0 && map->precision >= map->champ)
		while (map->precision-- - t > 0)
			str = ft_delstrjoin("0", str);
	if (map->zero == '0' && map->champ > 0)
		while (map->champ-- - t - 2 > 0 && map->champ > t)
			str = ft_delstrjoin("0", str);
	str = ft_delstrjoin("0x", str);
	map->temp = str;
	if (map->precisionzero == 1 && argv == 0)
		ft_bzero(str, ft_strlen(str));
	if (str[0] == '-' && (map->zero == '0' || map->precision > 0))
	{
		map->displayespacewithprecision = 1;
		str = str + 1;
		map->champ--;
	}
	if (map->attributmoins == 0)
		fonction_flag_pos(str, map, 0, 'i');
	else
		fonction_flag_neg(str, map, 0, 'i');
	free(map->temp);
}

void		conversion_pointer(unsigned long argv, t_map *map)
{
	char	*str;

	if (map->precisionzeroput == 1 && map->precision == 0)
	{
		map->count += write(1, "0x", 2);
		if (argv != 0)
		{
			str = ft_itoabase(argv, 16);
			map->count += write(1, str, ft_strlen(str));
			free(str);
		}
	}
	else
	{
		str = ft_strisminimalize(ft_itoabase(argv, 16));
		c_pointer_else(argv, map, str, ft_strlen(str));
	}
}
