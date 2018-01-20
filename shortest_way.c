/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:30:02 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/20 16:32:12 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		tab_co_position(t_map map, char *name)
{
	t_list	*tab;

	tab = map.tab;
	while (ft_strcmp(tab->content, name) != 0)
		tab = tab->next;
	return (tab->position);
}

char	*best_way(t_map map, t_list *tab)
{
	t_list	*tab_co;
	int position;
	char *name;

	tab_co = tab->co;
	position = 1000;
	name = NULL;
	while (tab_co)
	{
		if (tab_co_position(map, tab_co->content) < position)
		{
			position = tab_co_position(map, tab_co->content);
			name = ft_strdup(tab_co->content);
		}
		tab_co = tab_co->next;
	}
	return (name);
}

t_list	*shortest_way_inverse(t_map map)
{
	t_list	*tab;
	t_list	*way_inverse;
	t_list	*next;
	char	*name;

	tab = map.tab;
	while (tab->info_salle != 2)
		tab = tab->next;
	way_inverse = ft_lstnew(tab->content, 100);
	next = way_inverse;
	while (tab->info_salle != 1)
	{
		name = best_way(map, tab);
		next->next = ft_lstnew(name, 100);
		next = next->next;
		tab = map.tab;
		while (ft_strcmp(tab->content, name) != 0)
			tab = tab->next;
	}
	return (way_inverse);
}

void	shortest_way(t_map *map)
{
	t_list	*way_inverse;
	t_list	*sauv;
	t_list	*next;
	int		nb;
	int		i;

	way_inverse = shortest_way_inverse(*map);
	sauv = way_inverse;
	nb = 0;
	while (way_inverse->next && ++nb)
		way_inverse = way_inverse->next;
	map->way = ft_lstnew(way_inverse->content, 1000);
	next = map->way;
	while (nb-- > 0)
	{
		i = -1;
		way_inverse = sauv;
		while (++i < nb)
			way_inverse = way_inverse->next;
		next->next = ft_lstnew(way_inverse->content, 1000);
		next = next->next;
		next->nb_ant = 0;
		next->name_ant = 0;
	}
}
