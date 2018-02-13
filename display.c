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

void display_chemin(t_map map)
{
	t_list *all_the_way;
	t_list *way;

	all_the_way = map.all_the_way;
	while (all_the_way)
	{
		printf("Size of way : %d\n", all_the_way->size_way);
		way = all_the_way->l_content;
		while (way)
		{
			printf("%s --> ", way->content);
			way = way->next;
		}
	printf("\n");
	all_the_way = all_the_way->next;
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
		ft_printf(" || Pos : %5d || Nb_way : %3d || Gris %d", tab->position, tab->nb_way, tab->gris);
	//	printf(" || X : %s || Y : %s", tab->coord_x, tab->coord_y);
		if (tab->co)
		{
			next = tab->link;
			ft_printf("\033[32m");
			while (next)
			{
				ft_printf(" || Co %3s", next->l_content->content);
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
