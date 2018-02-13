/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 15:01:46 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/27 15:01:47 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int create_tab(t_list *way, int *tab, int nb_ant)
{
	int i;

	tab[0] = nb_ant;
	i = 1;
	while (way)
	{
		tab[i] = 0;
		way = way->next;
		i++;
	}
	return (i);
}

void test_tab(t_map *map, t_list *way, int *tab, int sauv_i, int name)
{
	int i;

	i = 0;
	while (++i < sauv_i)
	{
		if (tab[i] > 0)
		{
			map->print->content = ft_strjoin(map->print->content, " L");
			map->print->content = ft_strjoin(map->print->content, ft_itoa(name));
			map->print->content = ft_strjoin(map->print->content, "-");
			map->print->content = ft_strjoin(map->print->content, way->content);
			name--;
		}
		way = way->next;
	}
	map->print = map->print->next;
}

void display_way(t_map *map, t_list *way, int nb_ant, int name)
{
	int tab[10000];
	int i;
	int sauv_i;

	sauv_i = create_tab(way, tab, nb_ant);
	while (tab[sauv_i - 1] != nb_ant)
	{
		i = sauv_i;
		while (--i > 0)
		{
			if (tab[i - 1] > 0 && i != sauv_i)
			{
				tab[i] += 1;
				tab[i - 1] -= 1;
			}
		}
		test_tab(map, way, tab, sauv_i, name + 1);
		if (name + 1 < nb_ant + map->name_ant)
			name++;
	}
}
