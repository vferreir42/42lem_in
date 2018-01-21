/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestionchamp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 15:33:16 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/26 11:27:24 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fonction_counting_positive(t_map *map, int i, int t)
{
	if (map->attributespace == 1)
		map->champ--;
	if (map->zero == '0' && map->champ > map->precision && map->precision > i)
	{
		map->zero = ' ';
		map->precision -= i;
		map->champ -= (map->precision + i);
	}
	else
	{
		if (i > map->precision)
		{
			map->precision = 0;
			map->champ = map->champ - i - t;
		}
		else
		{
			map->champ = map->champ - map->precision - t;
			map->precision -= i;
		}
	}
}

void	fonction_counting_negative(t_map *map, int i, int t)
{
	if (map->precision >= map->champ)
	{
		map->champ = 0;
		map->precision -= i;
	}
	else
	{
		if (map->precision > i)
			map->precision -= i;
		map->champ -= (map->precision + i + t);
	}
}

void	counting_field(void *argv, char *line, t_map *map)
{
	if (line[map->i + 1] == '0')
	{
		map->zero = '0';
		map->i++;
		if (line[map->i + 1] == '-')
			flag_sign_negative(argv, line, map);
		if (line[map->i + 1] == '+')
			flag_sign_positive((int)argv, map, line);
	}
	while (line[map->i + 1] == '0')
		map->i++;
	if (line[map->i + 1] >= '1' && line[map->i + 1] <= '9')
		while (line[map->i + 1] >= '0' && line[map->i + 1] <= '9')
			map->champ = map->champ * 10 + (line[map->i++ + 1] - '0');
	if (map->attributplus == 1 && (int)argv >= 0)
		map->champ--;
}

void	counting_precision(char *line, t_map *map)
{
	if (line[map->i + 1] == '.')
	{
		map->precision = 0;
		map->i++;
		while (line[map->i + 1] >= '0' && line[map->i + 1] <= '9')
			map->precision = map->precision * 10 + (line[map->i++ + 1] - '0');
		map->precisionzero = 2;
		if (map->precision == 0)
			map->precisionzero = 1;
		map->precisionzeroput = 1;
	}
}
