/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:22:52 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/26 11:24:24 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_int(long long argv, t_map *map)
{
	char	*str;

	str = ft_itoa(argv);
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

void	conversion_long(long long argv, t_map *map)
{
	char	*str;

	if (argv >= 0)
		str = ft_itoabase(argv, 10);
	else
	{
		map->temp = ft_itoabase(-argv, 10);
		str = ft_strjoin("-", map->temp);
		free(map->temp);
	}
	map->temp = str;
	if (map->precisionzero == 1 && argv == 0)
		ft_bzero(str, ft_strlen(str));
	if (str[0] == '-' && (map->zero == '0' || map->precision > 0))
	{
		map->count += write(1, "-", 1);
		str = str + 1;
		map->champ--;
	}
	if (map->attributmoins == 0)
		fonction_flag_pos(str, map, 0, 'i');
	else
		fonction_flag_neg(str, map, 0, 'i');
	free(map->temp);
}

void	conversion_unsign_long(unsigned long argv, t_map *map, char c)
{
	char	*str;

	if (c == 'O' || c == 'o')
		str = ft_itoabase(argv, 8);
	else if (c == 'U')
	{
		if (argv / 2 == 9223372036854775807 && argv % 2 == 1)
			str = ft_strdup("18446744073709551615");
		else
			str = ft_itoabase(argv, 10);
	}
	else if (c == 'u')
		str = ft_itoabase(argv, 10);
	else if (c == 'x' || c == 'X')
		str = ft_itoabase(argv, 16);
	if (c == 'x')
		str = ft_strisminimalize(str);
	if (map->attributmoins == 0)
		fonction_flag_pos(str, map, argv, c);
	else
		fonction_flag_neg(str, map, argv, c);
	free(str);
}

void	conversion_unsigned_int(unsigned int argv, t_map *map, char c)
{
	char	*str;

	if (c == 'o')
	{
		if (map->attributhash == 1 && map->precision > 0)
			map->attributhash = 0;
		str = ft_itoabase(argv, 8);
	}
	else if (c == 'u')
		str = ft_itoabase(argv, 10);
	else if (c == 'x' || c == 'X')
		str = ft_itoabase(argv, 16);
	if (c == 'x')
		str = ft_strisminimalize(str);
	if (map->attributmoins == 0)
		fonction_flag_pos(str, map, argv, c);
	else
		fonction_flag_neg(str, map, argv, c);
	free(str);
}
