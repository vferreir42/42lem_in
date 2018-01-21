/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:22:21 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/27 16:49:07 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_modulo(t_map *map)
{
	int		t;

	map->argvnext = 1;
	if (map->champ < 0)
		map->champ = 0;
	if (map->attributmoins == 0 && ++map->count)
	{
		t = 0;
		while (++t < map->champ && ++map->count)
			ft_putchar(map->zero);
		ft_putchar('%');
	}
	else
		fonction_flag_neg("%", map, 0, 0);
}

void	conversion_char(char argv, t_map *map, char c)
{
	int		t;
	char	str[2];

	if (map->champ < 0)
		map->champ = 0;
	if (c == 'c')
		str[0] = argv;
	str[1] = '\0';
	if (map->attributmoins == 0 && ++map->count)
	{
		t = 0;
		while (++t < map->champ && ++map->count)
			ft_putchar(map->zero);
		ft_putchar(argv);
	}
	else
		fonction_flag_neg(str, map, 0, 0);
}

void	conversion_wchar(wchar_t argv, t_map *map, int t)
{
	if (map->champ < 0)
		map->champ = 0;
	if (map->attributmoins == 0)
	{
		t = 0;
		while (++t < map->champ && ++map->count)
			ft_putchar(map->zero);
		map->count += ft_putwchar(argv);
	}
	else
	{
		if (argv != 0 && map->attributhash == 1)
			t = flag_hash(map, 'c', 0);
		fonction_counting_negative(map, 1, t);
		if (argv != 0 && map->attributhash == 1)
			flag_hash(map, 'c', 1);
		if (map->attributplusok == 1)
			map->count += write(1, "+", 1);
		while (map->precision-- > 0)
			map->count += write(1, "0", 1);
		map->count++;
		ft_putwchar(argv);
		while (map->champ-- > 0)
			map->count += write(1, " ", 1);
	}
}
