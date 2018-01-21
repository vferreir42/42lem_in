/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestiontype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:28:42 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/26 11:20:55 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_specifier(void *argv, char *line, t_map *map)
{
	if (line[map->i + 1] == 'd' || line[map->i + 1] == 'i')
		conversion_int((int)argv, map);
	else if (line[map->i + 1] == 'D')
		conversion_long((long long)argv, map);
	else if (line[map->i + 1] == 'c')
		conversion_char((char)argv, map, line[map->i + 1]);
	else if (line[map->i + 1] == '%')
		conversion_modulo(map);
	else if (line[map->i + 1] == 'C')
		conversion_wchar((wchar_t)argv, map, 0);
	else if (line[map->i + 1] == 's')
		conversion_str((char*)argv, map);
	else if (line[map->i + 1] == 'S')
		conversion_wstr((wchar_t*)argv, map);
	else if (line[map->i + 1] == 'p')
		conversion_pointer((unsigned long)argv, map);
	else if (line[map->i + 1] == 'o' || line[map->i + 1] == 'u'
			|| line[map->i + 1] == 'x' || line[map->i + 1] == 'X')
		conversion_unsigned_int((unsigned int)argv, map, line[map->i + 1]);
	else if (line[map->i + 1] == 'U' || line[map->i + 1] == 'O')
		conversion_unsign_long((unsigned long)argv, map, line[map->i + 1]);
}
