/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:56:42 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/19 13:56:44 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void free_all(t_map *map)
{
	t_list *sauv;
	t_list *sauv_link;

	while (map->tab)
	{
		sauv = map->tab;
		free(map->tab->content);
		free(map->tab->co);
		while (map->tab->link)
		{
			sauv_link = map->tab->link;
			free(map->tab->link->content);
			map->tab->link = map->tab->link->next;
			free(sauv_link);
		}
		map->tab = map->tab->next;
		free(sauv);
	}
}

int main(void)
{
	t_map map;

	read_info(&map);
//	printf("READ OK\n");
	parsing(&map);
//	printf("PARSING OK\n");
	/*
	while (map.tab)
	{
		printf("Name : %s ||", map.tab->content);
		while (map.tab->co)
		{
			printf(" %s ||", map.tab->co->content);
			map.tab->co = map.tab->co->next;
		}
		printf("\n");
		map.tab = map.tab->next;
	}
	return 0;
	*/
	create_graph(map);
//	printf("CREATE GRAPH OK\n");
	add_position(map);
//	printf("ADD POSITION OK\n");
	add_nbway(map);
//	printf("ADD Nb WAY OK\n");
	all_way(&map);
//	printf("FIND ALL WAY OK\n");
//	display_list(map);
	if (map.all_the_way == NULL)
	{
		printf("Error\n");
		return (0);
	}
//	printf("NO ERROR\n");
	send_ant_in_way(map);

//	free_all(&map);

	return (0);
}
