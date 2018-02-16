/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:30:02 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/16 18:07:29 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*best_way(t_list *tab, int position)
{
	t_list	*link;
	t_list	*best;
	int		nb_way;

	nb_way = tab->nb_way;
	link = tab->link;
	best = NULL;
	while (link)
	{
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

t_list	*shortest_way_inverse(t_map *map)
{
	t_list	*next;
	t_list	*best;

	best = map->tab;
	while (best->info_salle != 2)
		best = best->next;
	map->way_inverse = ft_lstnew(best->content, 100);
	next = map->way_inverse;
	while (best && best->info_salle != 1)
	{
		if (best->info_salle == 2)
			best->position = 999999;
		best = best_way(best, best->position);
		if (best == NULL)
			return (NULL);
		next->next = ft_lstnew(best->content, 100);
		next = next->next;
	}
	return (map->way_inverse);
}

t_list	*reverse_way(t_map *map, t_list *way, t_list *next, t_list *sauv)
{
	char	**tab;
	int		i;

	if (!(tab = malloc(sizeof(char *) * 10000)))
		return (NULL);
	i = 0;
	while (map->way_inverse)
	{
		sauv = map->way_inverse;
		tab[i] = ft_strdup(map->way_inverse->content);
		free(map->way_inverse->content);
		map->way_inverse = map->way_inverse->next;
		free(sauv);
		i++;
	}
	way = ft_lstnew(tab[--i], 1000);
	next = way;
	while (i-- > 0)
	{
		next->next = ft_lstnew(tab[i], 1000);
		next = next->next;
	}
	free_tab(tab);
	free(tab);
	return (way);
}

t_list	*shortest_way(t_map *map)
{
	t_list	*way_inverse;
	t_list	*way;

	map->way_inverse = NULL;
	way_inverse = shortest_way_inverse(map);
	if (way_inverse == NULL)
		return (NULL);
	way = NULL;
	way = reverse_way(map, way, NULL, NULL);
	return (way);
}
