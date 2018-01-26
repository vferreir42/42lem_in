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

void test_tab(t_map *map, t_list *way, int *tab, int sauv_i, int name)
{
	int i;

	i = 0;
	//printf("name : %d\n", name);
	while (++i < sauv_i)
	{
//		printf("tab : %d\n", tab[i]);
		if (tab[i] > 0)
		{
			map->way->content = ft_strjoin(map->way->content, " L");
			map->way->content = ft_strjoin(map->way->content, ft_itoa(name));
			map->way->content = ft_strjoin(map->way->content, "-");
			map->way->content = ft_strjoin(map->way->content, way->content);
	//		printf("L%d-%s\n", name, way->content);
			name--;
		}
		way = way->next;
	}
//	map->way->content = ft_strjoin(map->way->content, "\n");
//	printf("\n");
	map->way = map->way->next;
}

void display(t_map *map, t_list *way, int nb_ant, int name)
{
	int tab[1000];
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
		if (name + 1 < nb_ant + map->name_ant)
			name++;
	}
}

int fonction(t_map map, int *size_way)
{
	t_list *sauv;
	int i;
	int total;
	int nb_cycle;
	int name;


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


	map.way = ft_lstnew("Tour 0 : ", 8);
	sauv = map.way;
	i = 0;
	while (++i < nb_cycle + 1)
	{
		map.way->next = ft_lstnew("Tour ", 6);
		map.way = map.way->next;
		map.way->content = ft_strjoin(map.way->content, ft_itoa(i));
		map.way->content = ft_strjoin(map.way->content, " :");
	}
	map.way = sauv;

	i = 0;
	map.name_ant = 0;
	while (size_way[i] && size_way[i] > 0)
	{
		map.all_the_way->l_content = map.all_the_way->l_content->next;
		display(&map, map.all_the_way->l_content, size_way[i], map.name_ant);
		map.name_ant += size_way[i];
		map.way = sauv;
		map.all_the_way = map.all_the_way->next;
		i++;
	}


	map.way = sauv;
	while (map.way)
	{
		ft_printf("%s\n", map.way->content);
		map.way = map.way->next;
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
	fonction(map, size_way);
}
