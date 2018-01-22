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

void recursive_nb_way(t_map map, t_list *tab, int position)
{
	int position_next;
	int i;
	t_list *link;

	i = 0;
	link = tab->link;
	while (link)
	{
		position_next = link->l_content->position;
		if (position_next < position && link->l_content->info_salle != 2)
		{
			if (i == 0)
			{
				tab->nb_way++;
				i = 1;
			}
			recursive_nb_way(map, link->l_content, link->l_content->position);
		}
		link = link->next;
	}
}

void 	add_nbway(t_map map)
{
	t_list *tab;
	t_list *link;

	reset_gris(map.tab);
	tab = map.tab;
	while (tab->info_salle != 2)
		tab = tab->next;
	link = tab->link;
	while (link)
	{
		recursive_nb_way(map, link->l_content, link->l_content->position);
		link = link->next;
	}
	tab = map.tab;
	while (tab->info_salle != 1)
		tab = tab->next;
	tab->nb_way = 10000;
}
