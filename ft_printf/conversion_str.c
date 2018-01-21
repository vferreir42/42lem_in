/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 12:43:38 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/26 12:43:40 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conversion_str_suite(char *str, t_map *map)
{
	int	i;

	if (map->attributmoins == 0)
	{
		if (map->precisionzero != 0 && (map->precision < (int)ft_strlen(str)))
			map->champ -= map->precision;
		else if (map->precisionzero != 0)
			map->champ -= ft_strlen(str);
		if (map->precisionzero == 0)
			map->champ -= ft_strlen(str);
		i = -1;
		while (map->champ-- > 0 && ++map->count)
			ft_putchar(map->zero);
		while (map->precision-- > 0 && str[++i] && ++map->count)
			ft_putchar(str[i]);
		if (map->precisionzero == 0)
			map->count += write(1, str, ft_strlen(str));
	}
}

void		conversion_str(char *str, t_map *map)
{
	int	i;

	if (str == NULL && ++map->strisnul)
		str = ft_strdup("(null)");
	conversion_str_suite(str, map);
	if (map->attributmoins != 0)
	{
		if (map->champ > map->precision && map->precision != 0
			&& (int)ft_strlen(str) > map->precision)
			map->champ -= map->precision;
		else
			map->champ -= ft_strlen(str);
		i = -1;
		while (map->precisionzero == 2 && map->precision-- > 0
			&& str[++i] && ++map->count)
			ft_putchar(str[i]);
		if (map->precisionzero != 2)
			map->count += write(1, str, ft_strlen(str));
		while (map->champ-- > 0 && ++map->count)
			ft_putchar(map->zero);
	}
	if (map->strisnul == 1)
		free(str);
}

static void	conversion_wstr_suite_suite(wchar_t *str, t_map *map, int i)
{
	int	sauv;

	if (map->precision < ft_strwlen(str))
	{
		sauv = map->precision;
		while (sauv > 0 && ft_not_putwchar(str[++i]) <= sauv && str[i])
		{
			map->champ -= ft_not_putwchar(str[i]);
			sauv -= ft_not_putwchar(str[i]);
		}
	}
	else
		map->champ -= ft_strwlen(str);
}

static void	conversion_wstr_suite(wchar_t *str, t_map *map, int i)
{
	if (map->precisionzero != 0)
		conversion_wstr_suite_suite(str, map, i);
	else
		map->champ -= ft_strwlen(str);
	i = -1;
	while (map->champ-- > 0 && ++map->count)
		ft_putchar(map->zero);
	while (map->precision > 0
		&& ft_not_putwchar(str[++i]) <= map->precision && str[i])
	{
		map->count += ft_putwchar(str[i]);
		map->precision -= ft_not_putwchar(str[i]);
	}
	if (map->precisionzero == 0)
		map->count += ft_putwstr(str);
}

void		conversion_wstr(wchar_t *str, t_map *map)
{
	int	i;

	i = -1;
	if (str == NULL)
		map->count += write(1, "(null)", 6);
	else
	{
		if (map->attributmoins == 0)
			conversion_wstr_suite(str, map, i);
		else
		{
			if (map->champ > map->precision
				&& map->precision != 0 && ft_strwlen(str) > map->precision)
				map->champ -= map->precision;
			else
				map->champ -= ft_strwlen(str);
			while (map->precisionzero == 2
				&& map->precision-- > 0 && str[++i] && ++map->count)
				ft_putwchar(str[i]);
			if (map->precision != 2)
				map->count += ft_putwstr(str);
			while (map->champ-- > 0 && ++map->count)
				ft_putchar(map->zero);
		}
	}
}
