/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestionattribut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 13:27:22 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/26 11:29:12 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flag_sign_negative(void *argv, char *line, t_map *map)
{
	if (line[map->i + 2] == '.')
		map->i++;
	else if (line[map->i + 2] == '#')
	{
		map->i += 2;
		map->attributhash = 1;
		map->attributmoins = 1;
	}
	else
	{
		map->i++;
		map->attributmoins = 1;
		counting_field(argv, line, map);
	}
}

static void	flag_hashtag(char *line, t_map *map)
{
	int	i;

	i = map->i + 2;
	while (line[i] && ((line[i] >= '0' && line[i] <= '9')
				|| line[i] == 'l'
				|| line[i] == 'h'
				|| line[i] == 'j'
				|| line[i] == 'z'
				|| line[i] == '.'
				|| line[i] == '-'))
		i++;
	if (line[i] == 'o'
			|| line[i] == 'x'
			|| line[i] == 'X'
			|| line[i] == 'O'
			|| line[i] == '-')
		map->attributhash = 1;
	map->i++;
}

void		flag_sign_positive(int argv, t_map *map, char *line)
{
	if (line[map->i + 2] == 'p')
		map->i++;
	else
	{
		map->attributplus = 1;
		if (argv >= 0)
			map->attributplusok = 1;
		map->i++;
	}
	while (line[map->i + 1] == ' ' || line[map->i + 1] == '+')
		map->i++;
}

static void	flag_space(t_map *map)
{
	ft_putchar(' ');
	map->attributespace = 1;
	map->count++;
}

void		flag_characters(void *argv, char *line, t_map *map)
{
	int	i;

	if (line[map->i + 1] == '#')
		flag_hashtag(line, map);
	if (line[map->i + 1] == '+')
		flag_sign_positive((int)argv, map, line);
	if (line[map->i + 1] == '-')
	{
		flag_sign_negative(argv, line, map);
		if (line[map->i + 1] == '+')
			flag_sign_positive((int)argv, map, line);
	}
	if (line[map->i] == ' ')
	{
		while (line[map->i + 1] == ' ')
			map->i++;
		i = map->i;
		while (line[i + 1] >= '0' && line[i + 1] <= '9')
			i++;
		if (line[i + 1] == '+' && ++map->i)
			flag_sign_positive((int)argv, map, line);
		else if ((line[i + 1] == 'd' || line[map->i + 1] == 'i')
				&& (int)argv >= 0 && map->attributplus == 0)
			flag_space(map);
	}
}
