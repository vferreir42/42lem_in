/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ant_in_way.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 17:10:17 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/25 17:10:19 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


int fonction(t_map map, int *size_way)
{
	int i;
	int total;
	int nb_cycle;

	total = map.nb_ant;
	i = -1;
	while (size_way[++i])
		total += (size_way[i] - 1);
	nb_cycle = total / i;
	i = -1;
	total = 0;
	while (size_way[++i])
	{
		size_way[i] = (nb_cycle + 1 - size_way[i]);
		total += size_way[i];
	}
	i = -1;
	while (total != map.nb_ant && size_way[++i] && ++total)
		size_way[i] += 1;

	i = 0;
	while (size_way[i] && size_way[i] > 0)
	{
		printf("\n");
		map.all_the_way = map.all_the_way->next;
		i++;
	}


	printf("total : %d || nb cycle : %d\n", total, nb_cycle);

	i = 0;
	while (size_way[i])
	{
		printf("Size : %d\n", size_way[i]);
		i++;
	}

	return (0);
}

void send_ant_in_way(t_map map)
{
	t_list *all_way;
	int size_way[100];
	int i;

	all_way = map.all_the_way;
	i = 0;
	while (all_way)
	{
		size_way[i] = all_way->size_way;
		all_way = all_way->next;
		i++;
	}
	size_way[i] ='\0';

	i = 0;
	while (size_way[i])
	{
		printf("Size : %d\n", size_way[i]);
		i++;
	}

//	fonction(map, size_way);




	/*


	map.way = map.all_the_way->l_content;
	display(map.way, map.nb_ant);
	*/
}
