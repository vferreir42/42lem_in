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
			ft_printf("L%d-%s\n", way->name_ant, way->content);
		way = way->next;
	}
//	ft_printf("\n");
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

void display_chemin(t_map map)
{
	t_list *all_way;
	t_list *way;

	all_way = map.all_the_way;
	while (all_way)
	{
		printf("SIZE WAY = %d\n", all_way->size_way);
		way = all_way->content;
		while (way)
		{
			printf(" %-2s-->", way->content);
			way = way->next;
		}
		printf("\n");
		all_way = all_way->next;
	}
}

void display_list(t_map map)
{
	t_list *tab;
	t_list *next;

	ft_printf("\n");
	tab = map.tab;
	while (tab)
	{
		ft_printf("\033[33mNom : %3s\033[0m || %d", tab->content, tab->info_salle);
		ft_printf(" || Pos : %3d || Nb_way : %3d || Gris %d", tab->position, tab->nb_way, tab->gris);
	//	printf(" || X : %s || Y : %s", tab->coord_x, tab->coord_y);
		if (tab->co)
		{
			next = tab->co;
			ft_printf("\033[32m");
			while (next)
			{
				ft_printf(" || Co %3s", next->content);
				next = next->next;
			}
			ft_printf("\033[0m");
		}
		ft_printf("\n");

		tab = tab->next;
	}
	ft_printf("\n");
	display_chemin(map);

}
