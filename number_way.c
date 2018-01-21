/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nbway.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:46:14 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/21 15:46:16 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void  reset_gris(t_list *list)
{
	while (list)
	{
		list->gris = 0;
		list = list->next;
	}
}

int position_next_rec(t_map map, char *name)
{
	t_list *tab;

	tab = map.tab;
	while (ft_strcmp(tab->content, name) != 0)
		tab = tab->next;
	return (tab->position);
}

void recursive_nb_way(t_map map, char *name, int position)
{
	int position_next;
	t_list *tab;
	t_list *tab_co;

	tab = map.tab;
	while (ft_strcmp(tab->content, name) != 0)
		tab = tab->next;
	tab->nb_way++;
//	printf("Name recursive : %s\n", tab->content);
	tab_co = tab->co;
	while (tab_co)
	{
//		printf("Name recursive next : %s\n", tab_co->content);
		position_next = position_next_rec(map, tab_co->content);
//		printf("position_next : %d\n", position_next);
		if (position_next < position && position_next != 0)
			recursive_nb_way(map, tab_co->content, position - 1);
		tab_co = tab_co->next;
	}
}
/*
void  calcul_total_way(t_map map)
{
	t_list *tab;
	t_list *tab_co;

	tab = map.tab;
	while (tab->info_salle != 1)
		tab = tab->next;
}
*/
void 	add_nbway(t_map map)
{
	t_list *tab;
	t_list *tab_co;

	reset_gris(map.tab);
	tab = map.tab;
	while (tab->info_salle != 2)
		tab = tab->next;
	tab_co = tab->co;
	while (tab_co)
	{
		recursive_nb_way(map, tab_co->content, position_next_rec(map, tab->co->content));
		tab_co = tab_co->next;
	}
//	calcul_total_way(t_map);
}
