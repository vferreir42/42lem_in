/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   created_graph.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:15:39 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/16 18:10:23 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*renvoie_list(t_map map, char *name)
{
	t_list	*tab;

	tab = map.tab;
	while (tab && ft_strcmp(tab->content, name) != 0)
		tab = tab->next;
	if (tab == NULL)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	return (tab);
}

void	graph(t_map map, t_list *link, t_list *next, t_list *tab)
{
	t_list	*t;

	while (tab)
	{
		t = tab->co;
		while (t)
		{
			if (link == NULL)
			{
				link = ft_lstnew(t->content, ft_strlen(t->content) * 120);
				link->l_content = renvoie_list(map, t->content);
				next = link;
			}
			else
			{
				next->next = ft_lstnew(t->content, ft_strlen(t->content) * 120);
				next = next->next;
				next->l_content = renvoie_list(map, t->content);
			}
			t = t->next;
		}
		tab->link = link;
		link = NULL;
		tab = tab->next;
	}
}
