/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_salle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:42:27 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/22 16:47:41 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	next_salle(t_map map, t_list *tab, int position)
{
	t_list	*link;

	if (tab->position == -1)
		tab->position = position;
	else if (position < tab->position)
		tab->position = position;
	link = tab->link;
	while (link)
	{
		if (link->l_content->position == -1)
			next_salle(map, link->l_content, position + 1);
		else if (link->l_content->position > position + 1)
			next_salle(map, link->l_content, position + 1);
		link = link->next;
	}
}

void	add_position(t_map map)
{
	t_list	*link;
	t_list	*tab;

	tab = map.tab;
	while (tab->info_salle != 1)
		tab = tab->next;
	link = tab->link;
	tab->position = 0;
	while (link)
	{
		next_salle(map, link->l_content, 1);
		link = link->next;
	}
}
