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

void display(t_map map)
{
	t_list *tab;
	t_list *next;

	tab = map.tab;
	printf("\n");
	while (tab)
	{
		printf("\033[33mNom : %5s\033[0m || Salle %d", tab->content, tab->info_salle);
	//	printf(" || X : %s || Y : %s", tab->coord_x, tab->coord_y);
		if (tab->co)
		{
			next = tab->co;
			printf("\033[32m");
			while (next)
			{
				printf(" || Connexion %4s", next->content);
				next = next->next;
			}
			printf("\033[0m");
		}
		printf("\n");

		tab = tab->next;
	}
}
