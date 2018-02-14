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
	while (tab && ft_strcmp(tab->content, name) != 0)
		tab = tab->next;
	if (tab == NULL)
		exit (0);
	return (tab);
}

void create_graph(t_map map)
{
	t_list *link;
	t_list *next;
	t_list *tab;
	t_list *sauv;

	link = NULL;
	tab = map.tab;
	while (tab)
	{
		while (tab->co)
		{
			if (link == NULL)
			{
				link = ft_lstnew(tab->co->content, ft_strlen(tab->co->content) * 120);
				link->l_content = renvoie_list(map, tab->co->content);
				next = link;
			}
			else
			{
				next->next = ft_lstnew(tab->co->content, ft_strlen(tab->co->content) * 120);
				next = next->next;
				next->l_content = renvoie_list(map, tab->co->content);
			}
			sauv = tab->co;
			free(tab->co->content);
			tab->co = tab->co->next;
			free(sauv);
		}
		tab->link = link;
		link = NULL;
		tab = tab->next;
	}
}
