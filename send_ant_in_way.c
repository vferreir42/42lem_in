/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ant_in_way.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:10:17 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/27 15:18:33 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	suite(t_map map, int *send_ant, int nb_cycle)
{
	t_list *next;
	int		i;

	map.print = ft_lstnew("Tour 0 : ", 8);
	next = map.print;


	i = 0;
	while (++i < nb_cycle + 1)
	{
		next->next = ft_lstnew("Tour ", 6);
		next = next->next;
		next->content = ft_strjoin(next->content, ft_itoa(i));
		next->content = ft_strjoin(next->content, " :");
	}

	next = map.print;
	i = 0;
	map.name_ant = 0;
	while (send_ant[i] && send_ant[i] > 0)
	{
		map.all_the_way->l_content = map.all_the_way->l_content->next;
		display_way(&map, map.all_the_way->l_content, send_ant[i], map.name_ant);
		map.name_ant += send_ant[i];
		map.print = next;
		map.all_the_way = map.all_the_way->next;
		i++;
	}

	next = map.print;
	while (next)
	{
		ft_printf("%s\n", next->content);
		next = next->next;
	}
}

void	fonction(t_map map, int *size_way, int *send_ant)
{
	int	i;
	int	total;
	int	nb_cycle;

	total = map.nb_ant;
	i = -1;
	while (size_way[++i])
		total += (size_way[i] - 1);
	nb_cycle = total / i;
	i = -1;
	total = 0;
	while (size_way[++i] && total != map.nb_ant)
	{
		send_ant[i] = (nb_cycle + 1 - size_way[i]);
		if (send_ant[i] > 0)
			total += send_ant[i];
	}
	send_ant[i] = '\0';
	i = -1;
	while (total != map.nb_ant && send_ant[++i] && ++total)
		send_ant[i] += 1;
	suite(map, send_ant, nb_cycle);
}

void	send_ant_in_way(t_map map)
{
	t_list	*all_way;
	int		size_way[10000];
	int		send_ant[10000];
	int		i;

	all_way = map.all_the_way;
	i = 0;
	while (all_way)
	{
		size_way[i] = all_way->size_way;
		send_ant[i] = 0;
		all_way = all_way->next;
		i++;
	}
	send_ant[i] = '\0';
	size_way[i] = '\0';
	fonction(map, size_way, send_ant);
}
