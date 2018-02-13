/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   created_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:15:39 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/22 16:15:40 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list *renvoie_list(t_map map, char *name)
{
	t_list	*tab;

	tab = map.tab;
	while (ft_strcmp(tab->content, name) != 0)
		tab = tab->next;
	return (tab);
}

void create_graph(t_map map)
{
	t_list *link;
	t_list *next;
	t_list *tab;
	t_list *tab_co;

	link = NULL;
	tab = map.tab;
	while (tab)
	{
		tab_co = tab->co;
		while (tab_co)
		{
			if (link == NULL)
			{
				link = ft_lstnew(tab_co->content, ft_strlen(tab_co->content) * 120);
				link->l_content = renvoie_list(map, tab_co->content);
				next = link;
			}
			else
			{
				next->next = ft_lstnew(tab_co->content, ft_strlen(tab_co->content) * 120);
				next = next->next;
				next->l_content = renvoie_list(map, tab_co->content);
			}
			tab_co = tab_co->next;
		}
		tab->link = link;
		link = NULL;
		tab = tab->next;
	}
}
