/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_the_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 20:47:24 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/21 20:47:25 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int size_of_way(t_list *way)
{
	int i;
	t_list *next;

	i = -1;
	next = way;
	while (next)
	{
		next = next->next;
		i++;
	}
	return (i);
}

void all_way(t_map *map)
{
	t_list *way;
	t_list *all_way;
	t_list *next;

	all_way = NULL;
	while (1)
	{
		way = shortest_way(map);
		if (way == NULL)
			return ;
		map->way = way;
		if (all_way == NULL)
		{
			all_way = ft_lstnew(way->content, 10000);
			all_way->l_content = way;
			all_way->size_way = size_of_way(way);
			next = all_way;
		}
		else
		{
			next->next = ft_lstnew(way, 10000);
			next = next->next;
			next->l_content = way;
			next->size_way = size_of_way(way);
		}
		map->all_the_way = all_way;
	}
}
