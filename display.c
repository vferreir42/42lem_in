/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:08:59 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/19 17:09:00 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void display_progression(t_map map)
{
	t_list *way;

	way = map.way->next;
	while (way)
	{
		if (way->nb_ant > 0)
			way->name_ant++;
		if (way->nb_ant > 0 && way->name_ant > 0)
			printf("L%d-%s\n", way->name_ant, way->content);
		way = way->next;
	}
}

void display(t_map map)
{
	t_list *way;
	int give;

	way = map.way;
	way->nb_ant = map.nb_ant;
	while (1)
	{
		way = map.way;
		give = 0;
		while (way)
		{
			if (way->nb_ant - give > 0 && way->next)
			{
				way->nb_ant--;
				give = 1;
				way->next->nb_ant++;
			}
			else
				give = 0;
			if (way->nb_ant == map.nb_ant)
				break ;
			way = way->next;
		}
		display_progression(map);
		if (way && way->nb_ant == map.nb_ant)
			break ;
	}
}

void display_list(t_map map)
{
	t_list *tab;
	t_list *next;

	tab = map.tab;
	while (tab)
	{
		printf("\033[33mNom : %5s\033[0m || Salle %d", tab->content, tab->info_salle);
		printf(" || Pos : %6d || Gris %d", tab->position, tab->gris);
	//	printf(" || X : %s || Y : %s", tab->coord_x, tab->coord_y);
		if (tab->co)
		{
			next = tab->co;
			printf("\033[32m");
			while (next)
			{
				printf(" || Co %4s", next->content);
				next = next->next;
			}
			printf("\033[0m");
		}
		printf("\n");

		tab = tab->next;
	}
	printf("\n");
	while (map.way)
	{
		printf("%s-->", map.way->content);
		map.way = map.way->next;
	}
}
