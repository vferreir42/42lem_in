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

char *ft_strchr_before(char *str, char c)
{
	char *new;
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(new = malloc(sizeof(char) * i + 1)))
		return (0);
	new[i] = '\0';
	while (i-- > 0)
		new[i] = str[i];
	return (new);
}

int next_salle_is_gris(t_map map, char *name)
{
	t_list *tab;


	return (0);
}

void next_salle(t_map map, char *name, int position)
{
	t_list *tab;
	t_list *sauv;

	tab = map.tab;
	while (ft_strcmp(tab->content, name) != 0)
		tab = tab->next;
	sauv = tab->co;
	if (tab->position > position)
		tab->position = position;
	tab->gris = 1;
	printf("Salle %s, position %d\n", tab->content, tab->position);
	while (sauv)
	{
		if (sauv->info_salle != 1 && next_salle_is_gris(map, sauv->content) == 1)
		{
		//	printf("sauvcontent %s\n", sauv->content);
			next_salle(map, sauv->content, position);
		}
		sauv = sauv->next;
	}
}

void algo(t_map map)
{
	t_list *sauv;
	t_list *tab;

	tab = map.tab;
	sauv = map.tab;

	while (tab->info_salle != 1)
		tab = tab->next;
//	while (tab->co)
//	{
		next_salle(map, tab->co->content, 1);
//		tab->co->next;
//	}

	//printf("%s\n", tab->content);
}


int main(void)
{
	t_map map;

	put_read_in_list(&map);
	printf("\n");
	algo(map);
	return (0);
}
