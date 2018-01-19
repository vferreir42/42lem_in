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

void put_connexion_in_tab(t_list *tab, char **connexion)
{
	int i;
	t_list *sauv;

	sauv = tab;
	i = 0;
	while (connexion[i])
	{
		while (ft_strcmp(tab->content, ft_strchr_before(connexion[i], '-')) != 0)
			tab = tab->next;
		tab->co = ft_strdup(ft_strchr(connexion[i], '-') + 1);
		tab = sauv;
		while (ft_strcmp(tab->content, ft_strchr(connexion[i], '-') + 1) != 0)
			tab =tab->next;
		tab->co = ft_strdup(ft_strchr_before(connexion[i], '-'));
		i++;
	}
}

void extract_information(t_map *map, t_list *read)
{
	char **connexion;
	t_list *tab;
	t_list *next;
	int i;

	tab = ft_lstnew("0", 16);
	tab->coord_x = NULL;
	tab->coord_y = NULL;
	next = tab;

	i = 0;
	connexion = malloc(sizeof(char *) * 100);
	while (read)
	{
		if (ft_strcmp(read->content, "##start") == 0)
		{
			read = read->next;
			next->next = ft_lstnew(ft_strchr_before(read->content, ' '), ft_strlen(read->content) * 8);
			next = next->next;
			next->coord_x = ft_strchr_before(ft_strchr(read->content, ' ') + 1, ' ');
			next->coord_y = ft_strrchr(read->content, ' ');
			next->info_salle = 1;
			next->co = NULL;
		}
		else if (ft_strcmp(read->content, "##end") == 0)
		{
			read = read->next;
			next->next = ft_lstnew(ft_strchr_before(read->content, ' '), ft_strlen(read->content) * 8);
			next = next->next;
			next->coord_x = ft_strchr_before(ft_strchr(read->content, ' ') + 1, ' ');
			next->coord_y = ft_strrchr(read->content, ' ');
			next->info_salle = 2;
			next->co = NULL;
		}
		else if (ft_strchr(read->content, '-') != NULL)
		{
			connexion[i] = ft_strdup(read->content);
			i++;
		}
		else
		{
			next->next = ft_lstnew(ft_strchr_before(read->content, ' '), ft_strlen(read->content) * 8);
			next = next->next;
			next->coord_x = ft_strchr_before(ft_strchr(read->content, ' ') + 1, ' ');
			next->coord_y = ft_strrchr(read->content, ' ');
			next->info_salle = 0;
			next->co = NULL;
		}
		read = read->next;
	}
	connexion[i] = NULL;

	i = 0;
	while (connexion[i])
	{
		printf("connexion : %s\n", connexion[i]);
		i++;
	}


	tab = tab->next;
	put_connexion_in_tab(tab, connexion);

	printf("\n");
	while (tab)
	{
		printf("Nom : %8s || Coord x : %3s || coord_y : %3s || info salle %d", tab->content, tab->coord_x, tab->coord_y, tab->info_salle);
		printf("|| Connexion %8s", tab->co);
		printf("\n");

		tab = tab->next;
	}

}

void put_read_in_list(t_map *map)
{
	t_list *read;
	t_list *next;
	char *line;

	get_next_line(0, &line);
	read = ft_lstnew(line, ft_strlen(line) * 8);
	next = read;
	while (get_next_line(0, &line) > 0)
	{
		next->next = ft_lstnew(line, ft_strlen(line) * 8);
		next = next->next;
	}
	map->nb_ant = ft_atoi(read->content);
	read = read->next;
	extract_information(map, read);
}

int main(void)
{
	t_map map;

	put_read_in_list(&map);
	return (0);
}
