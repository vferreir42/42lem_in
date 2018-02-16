/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_the_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 20:47:24 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/16 14:33:46 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		size_of_way(t_list *way)
{
	int		i;
	t_list	*next;

	i = -1;
	next = way;
	while (next)
	{
		next = next->next;
		i++;
	}
	return (i);
}

void	all_way(t_map *map)
{
	t_list *way;
	t_list *next;

	map->all_the_way = NULL;
	way = NULL;
	while (1)
	{
		way = shortest_way(map);
		if (way == NULL)
			return ;
		if (map->all_the_way == NULL)
		{
			map->all_the_way = ft_lstnew(way->content, ft_strlen(way->content));
			map->all_the_way->l_content = way;
			map->all_the_way->size_way = size_of_way(way);
			next = map->all_the_way;
		}
		else
		{
			next->next = ft_lstnew(way, ft_strlen(way->content));
			next = next->next;
			next->l_content = way;
			next->size_way = size_of_way(way);
		}
	}
}
