/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 15:37:47 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/26 12:17:07 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	settozero(t_map *map, int i)
{
	if (i == 0)
	{
		map->count = 0;
		map->i = 0;
	}
	map->argvnext = 0;
	map->displayespacewithprecision = 0;
	map->precisionzeroput = 0;
	map->attributespace = 0;
	map->strisnul = 0;
	map->attributplusok = 0;
	map->attributplus = 0;
	map->longeur = 0;
	map->precisionzero = 0;
	map->precisionoux = 0;
	map->attributmoins = 0;
	map->attributhash = 0;
	map->gestionlongeur = 0;
	map->precision = 0;
	map->champ = 0;
	map->zero = ' ';
}

static int	casparticulier(t_map *map, char *l, int i)
{
	while (l[++i + 1] != '\0')
		if ((l[i] == '%' || l[i] == '-' || l[i] == '+' || l[i] == '#'
		|| l[i] == '.' || l[i] == 'h' || l[i] == 'l' || l[i] == 'z'
		|| l[i] == ' ' || l[i] == 'j' || (l[i] >= '0' && l[i] <= '9'))
		&& (l[i + 1] == 'd' || l[i + 1] == 'i' || l[i + 1] == '%'
					|| l[i + 1] == 'u' || l[i + 1] == 'o' || l[i + 1] == 'x'
					|| l[i + 1] == 'X' || l[i + 1] == 'U' || l[i + 1] == 'O'
					|| l[i + 1] == 's' || l[i + 1] == 'S' || l[i + 1] == 'C'
					|| l[i + 1] == 'D' || l[i + 1] == 'c' || l[i + 1] == 'p'))
			return (0);
	if (map->champ > 0 && map->attributmoins == 0)
		while (--map->champ > 0 && map->count++)
			ft_putchar(map->zero);
	else if (map->champ > 0)
	{
		write(1, l + map->i + 1, 1);
		while (--map->champ > 0 && map->count++)
			ft_putchar(' ');
		map->count += write(1, l + map->i + 2, ft_strlen(l + map->i + 1));
		return (1);
	}
	map->count += write(1, l + map->i + 1, ft_strlen(l + map->i + 1));
	return (1);
}

static int	fonctions(t_map *map, char *line, void *argv)
{
	if (line[map->i] == '\0' || line[map->i + 1] == '\0')
		return (map->count);
	while (line[map->i + 1] == ' ')
		map->i++;
	settozero(map, 1);
	flag_characters(argv, line, map);
	counting_field(argv, line, map);
	counting_precision(line, map);
	length_modifier(argv, line, map);
	if (map->gestionlongeur == 0)
		conversion_specifier(argv, line, map);
	if (casparticulier(map, (char*)line, map->i - 1) == 1)
		return (map->count);
	map->i += 2;
	return (-1);
}

int			ft_printf(const char *line, ...)
{
	void	*argv;
	t_map	map;

	va_list(ap);
	va_start(ap, line);
	settozero(&map, 0);
	while (line[map.i])
	{
		if (map.argvnext == 0)
			argv = va_arg(ap, void*);
		while (line[map.i] && line[map.i] != '%' && ++map.count)
		{
			if (line[map.i] != '%' && line[map.i] != '\0')
				ft_putchar(line[map.i]);
			map.i++;
		}
		if (fonctions(&map, (char*)line, argv) != -1)
			return (map.count);
	}
	va_end(ap);
	return (map.count);
}
