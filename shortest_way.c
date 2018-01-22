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

t_list	*best_way(t_map map, t_list *tab, int position)
{
	t_list *link;
	t_list *best;
	int nb_way;

//	printf("NAME : %s || POSITION : %d\n", tab->content, position);
	nb_way = tab->nb_way;
	link = tab->link;
	best = NULL;
	while (link)
	{
//		printf("NAME LINK: %s ||  link nb : %d || link %d\n", link->l_content->content, link->l_content->nb_way, nb_way);
		if (link->l_content->position <= position && link->l_content->gris == 0
			&& link->l_content->nb_way >= nb_way)
		{
			position = link->l_content->position;
			best = link->l_content;
		}
		link = link->next;
	}
	if (best && best->info_salle != 1)
		best->gris = 1;
	return (best);
}

t_list	*shortest_way_inverse(t_map map)
{
	t_list	*way_inverse;
	t_list	*next;
	t_list	*best;

	best = map.tab;
	while (best->info_salle != 2)
		best = best->next;
	way_inverse = ft_lstnew(best->content, 100);
	next = way_inverse;
	while (best && best->info_salle != 1)
	{
		if (best->info_salle == 2)
			best->position = 10000;
		best = best_way(map, best, best->position);
		if (best == NULL)
			return (NULL);
//		printf("best content : %s\n", best->content);
		next->next = ft_lstnew(best->content, 100);
		next = next->next;
//		printf("\n");
	}
	return (way_inverse);
}

t_list	*shortest_way(t_map *map)
{
	t_list	*way_inverse;
	t_list 	*way;
	t_list	*sauv;
	t_list	*next;
	int		nb;
	int		i;

	way_inverse = shortest_way_inverse(*map);
	if (way_inverse == NULL)
		return (NULL);
	return (way_inverse);
	/*
	sauv = way_inverse;
	nb = 0;
	while (way_inverse->next && ++nb)
		way_inverse = way_inverse->next;
	way = ft_lstnew(way_inverse->content, 1000);
	next = way;
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
	return (way); */
}
