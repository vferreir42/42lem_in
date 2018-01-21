/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestionlongeur1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 16:26:20 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/26 13:14:17 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	length_modifier_h(void *ar, char *line, t_map *map)
{
	map->i++;
	map->gestionlongeur = 1;
	if (line[map->i + 1] == 'd' || line[map->i + 1] == 'i')
		conversion_int((short int)ar, map);
	else if (line[map->i + 1] == 'u' || line[map->i + 1] == 'x'
			|| line[map->i + 1] == 'X' || line[map->i + 1] == 'o')
		conversion_unsigned_int((unsigned short int)ar, map, line[map->i + 1]);
	else
		map->gestionlongeur = 0;
}

static void	length_modifier_hh(void *argv, char *line, t_map *map)
{
	map->i += 2;
	map->gestionlongeur = 1;
	if (line[map->i + 1] == 'd' || line[map->i + 1] == 'i')
		conversion_int((char)argv, map);
	else if (line[map->i + 1] == 'u' || line[map->i + 1] == 'x'
			|| line[map->i + 1] == 'X' || line[map->i + 1] == 'o')
		conversion_unsigned_int((unsigned char)argv, map, line[map->i + 1]);
	else
		map->gestionlongeur = 0;
}

static void	length_modifier_long(void *argv, char *line, t_map *map)
{
	map->i++;
	if (line[map->i + 1] == 'd' || line[map->i + 1] == 'i')
	{
		conversion_long((unsigned long)argv, map);
		map->gestionlongeur = 1;
	}
	if (line[map->i + 1] == 'u' || line[map->i + 1] == 'x'
			|| line[map->i + 1] == 'X' || line[map->i + 1] == 'o')
	{
		conversion_unsign_long((unsigned long)argv, map, line[map->i + 1]);
		map->gestionlongeur = 1;
	}
}

void		length_modifier(void *argv, char *line, t_map *map)
{
	if (line[map->i + 1] == 'h' && line[map->i + 2] != 'h')
		length_modifier_h(argv, line, map);
	if (line[map->i + 1] == 'l' && line[map->i + 2] == 'c')
	{
		map->gestionlongeur = 1;
		conversion_wchar((wchar_t)argv, map, 0);
	}
	if (line[map->i + 1] == 'l' && line[map->i + 2] == 's')
	{
		map->gestionlongeur = 1;
		conversion_wstr((wchar_t *)argv, map);
	}
	if (line[map->i + 1] == 'h' && line[map->i + 2] == 'h')
		length_modifier_hh(argv, line, map);
	if (line[map->i + 1] == 'l' && line[map->i + 2] == 'l')
		length_modifier_long(argv, line, map);
	if (line[map->i + 1] == 'l' && line[map->i + 2] != 'l')
		length_modifier_long(argv, line, map);
	if (line[map->i + 1] == 'j' || line[map->i + 1] == 'z')
		length_modifier_long(argv, line, map);
}
