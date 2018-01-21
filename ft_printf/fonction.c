/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:54:53 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/27 16:48:27 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flag_hash(t_map *map, char c, int yes)
{
	if (yes == 0)
	{
		if (c == 'o')
			return (1);
		if (c == 'x' || c == 'X')
			return (2);
		return (0);
	}
	else
	{
		if ((c == 'o' || c == 'O') && ++map->count)
			write(1, "0", 1);
		else if (c == 'x')
			map->count += write(1, "0x", 2);
		else if (c == 'X')
			map->count += write(1, "0X", 2);
	}
	return (0);
}

static void	f_flag_pos_suite(char *str, t_map *map, long argv, char c)
{
	while (map->champ-- > 0 && ++map->count)
		ft_putchar(map->zero);
	if (argv != 0 && map->attributhash == 1 && map->zero == ' ')
		flag_hash(map, c, 1);
	if (map->attributplusok == 1 && map->zero == ' ' && c == 'i')
		map->count += write(1, "+", 1);
	if (map->displayespacewithprecision == 1 && map->zero == ' ')
		map->count += write(1, "-", 1);
	while (map->precision-- > 0)
		map->count += write(1, "0", 1);
	map->count += write(1, str, ft_strlen(str));
}

void		fonction_flag_pos(char *str, t_map *map, long argv, char c)
{
	int t;

	if (map->precisionzero == 1 && argv == 0
		&& (c == 'x' || c == 'X' || c == 'u'))
		ft_bzero(str, ft_strlen(str));
	if (map->precisionzero == 1 && argv == 0
		&& (c == 'o' || (c == 'O' && map->attributhash == 0))
		&& map->attributhash != 1)
		ft_bzero(str, ft_strlen(str));
	t = 0;
	if (argv != 0 && map->attributhash == 1)
		t = flag_hash(map, c, 0);
	fonction_counting_positive(map, ft_strlen(str), t);
	if (argv != 0 && map->attributhash == 1 && map->zero == '0')
		flag_hash(map, c, 1);
	if (map->attributplusok == 1 && map->zero == '0' && c == 'i')
		map->count += write(1, "+", 1);
	if (map->displayespacewithprecision == 1 && map->zero == '0')
		map->count += write(1, "-", 1);
	f_flag_pos_suite(str, map, argv, c);
}

void		fonction_flag_neg(char *str, t_map *map, long argv, char c)
{
	int t;

	t = 0;
	if (argv != 0 && map->attributhash == 1)
		t = flag_hash(map, c, 0);
	fonction_counting_negative(map, ft_strlen(str), t);
	if (argv != 0 && map->attributhash == 1)
		flag_hash(map, c, 1);
	if (map->attributplusok == 1)
		map->count += write(1, "+", 1);
	if (map->displayespacewithprecision == 1)
		map->count += write(1, "-", 1);
	while (map->precision-- > 0)
		map->count += write(1, "0", 1);
	map->count += write(1, str, ft_strlen(str));
	while (map->champ-- > 0)
		map->count += write(1, " ", 1);
}
