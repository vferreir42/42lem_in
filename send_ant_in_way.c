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

void test_tab(t_map map, t_list *way, int *tab, int sauv_i, int name)
{
	int i;

	i = 0;
//	printf("name : %d\n", name);
	while (++i < sauv_i)
	{
//		printf("tab : %d\n", tab[i]);
		if (tab[i] > 0)
		{
			map.way->content = ft_strjoin(map.way->content, "L");
			map.way->content = ft_strjoin(map.way->content, ft_itoa(name));
			map.way->content = ft_strjoin(map.way->content, "-");
			map.way->content = ft_strjoin(map.way->content, way->content);
			map.way->content = ft_strjoin(map.way->content, " ");
			printf("L%d-%s\n", name, way->content);
			name--;
		}
		way = way->next;
	}
	map.way->content = ft_strjoin(map.way->content, "\n");
	printf("\n");
}

int create_tab(t_list *way, int *tab, int nb_ant)
{
	int i;

	tab[0] = nb_ant;
	i = 1;
	while (way)
	{
		tab[i] = 0;
		way = way->next;
		i++;
	}
	return (i);
}

void display(t_map map, t_list *way, int nb_ant, int name)
{
	int tab[nb_ant];
	int i;
	int sauv_i;

	sauv_i = create_tab(way, tab, nb_ant);
	while (tab[sauv_i - 1] != nb_ant)
	{
		i = sauv_i;
		while (--i > 0)
		{
			if (tab[i - 1] > 0 && i != sauv_i)
			{
				tab[i] += 1;
				tab[i - 1] -= 1;
			}
		}
		test_tab(map, way, tab, sauv_i, name + 1);
		if (name + 1 < nb_ant + map.name_ant)
			name++;
	}
}

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


	t_list *sauv;
	map.way = ft_lstnew("Tour", 5);
	sauv = map.way;

	printf("%s\n", map.way->content);

	map.name_ant = 0;
	map.all_the_way->l_content = map.all_the_way->l_content->next;
	display(map, map.all_the_way->l_content, 5, 0);

	printf("%s\n", map.way->content);


	/*
	i = 0;
	while (size_way[i] && size_way[i] > 0)
	{
		printf("Nb ant envoye %d\n", size_way[i]);
		map.all_the_way = map.all_the_way->next;
		i++;
	}
	printf("\ntotal : %d || nb cycle : %d\n", total, nb_cycle);
	*/
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
	printf("\n");

	fonction(map, size_way);




	/*


	map.way = map.all_the_way->l_content;
	display(map.way, map.nb_ant);
	*/
}
