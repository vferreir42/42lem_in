/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_salle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:42:27 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/20 15:09:57 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	next_salle_is_not_gris(t_map map, char *name, char *namebefore)
{
	t_list	*tab;

	tab = map.tab;
	while (ft_strcmp(tab->content, name) != 0)
		tab = tab->next;
	tab->gris = 0;
}

int		next_salle_is_gris(t_map map, char *name)
{
	t_list	*tab;

	tab = map.tab;
	while (ft_strcmp(tab->content, name) != 0)
		tab = tab->next;
	if (tab->gris != 1)
		return (1);
	return (0);
}

void	next_salle(t_map map, char *name, int position)
{
	t_list	*tab;
	t_list	*sauv;

	tab = map.tab;
	while (ft_strcmp(tab->content, name) != 0)
		tab = tab->next;
	sauv = tab->co;
	if (tab->position > position)
		tab->position = position;
	tab->gris = 1;
	while (sauv)
	{
		if (next_salle_is_gris(map, sauv->content) == 1)
		{
			next_salle(map, sauv->content, position + 1);
			next_salle_is_not_gris(map, sauv->content, tab->content);
		}
		sauv = sauv->next;
	}
}

void	add_position(t_map map)
{
	t_list	*sauv;
	t_list	*tab;

	tab = map.tab;
	while (tab->info_salle != 1)
		tab = tab->next;
	sauv = tab->co;
	tab->gris = 1;
	tab->position = 0;
	while (sauv)
	{
		next_salle(map, sauv->content, 1);
		sauv = sauv->next;
	}
}
