/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 16:51:57 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/19 16:57:42 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	put_connexion_in_tab(t_list *tab, char **connexion)
{
	int		i;
	t_list	*sauv;
	t_list	*next;

	sauv = tab;
	i = 0;
	while (connexion[i])
	{
		tab = sauv;
		while (ft_strcmp(tab->content, ft_strchr_before(connexion[i], '-')) != 0)
			tab = tab->next;
		if (tab->co == NULL)
		{
			tab->co = ft_lstnew(ft_strchr(connexion[i], '-') + 1, 50);
			tab->conext = tab->co;
		}
		else
		{
			tab->conext->next = ft_lstnew(ft_strchr(connexion[i], '-') + 1, 50);
			tab->conext = tab->conext->next;
		}
		tab = sauv;
		while (ft_strcmp(tab->content, ft_strchr(connexion[i], '-') + 1) != 0)
			tab = tab->next;
		if (tab->co == NULL)
		{
			tab->co = ft_lstnew(ft_strchr_before(connexion[i], '-'), 50);
			tab->conext = tab->co;
		}
		else
		{
			tab->conext->next = ft_lstnew(ft_strchr_before(connexion[i], '-'), 50);
			tab->conext = tab->conext->next;
		}
		i++;
	}
}

t_list 	*reduce_extract_information(t_map *map, t_list *read, t_list *next)
{
	next->next = ft_lstnew(ft_strchr_before(read->content, ' '), ft_strlen(read->content) * 8);
	next = next->next;
	next->coord_x = ft_strchr_before(ft_strchr(read->content, ' ') + 1, ' ');
	next->coord_y = ft_strrchr(read->content, ' ');
	next->info_salle = 0;
	next->co = NULL;
	next->gris = 0;
	next->nb_way = 0;
	next->position = 10000;
	return (next);
}

void	extract_information(t_map *map, t_list *read)
{
	char	**connexion;
	t_list	*tab;
	t_list	*next;
	int		i;

	tab = ft_lstnew("0", 16);
	next = tab;
	i = 0;
	connexion = malloc(sizeof(char *) * 1000);
	while (read)
	{
		if (ft_strcmp(read->content, "##start") == 0)
		{
			read = read->next;
			next = reduce_extract_information(map, read, next);
			next->info_salle = 1;
		}
		else if (ft_strcmp(read->content, "##end") == 0)
		{
			read = read->next;
			next = reduce_extract_information(map, read, next);
			next->info_salle = 2;
		}
		else if (ft_strchr(read->content, '-') != NULL)
		{
			connexion[i] = ft_strdup(read->content);
			i++;
		}
		else
			next = reduce_extract_information(map, read, next);
		read = read->next;
	}
	connexion[i] = NULL;
	tab = tab->next;
	put_connexion_in_tab(tab, connexion);
	map->tab = tab;
}

void	put_read_in_list(t_map *map)
{
	t_list	*read;
	t_list	*next;
	char	*line;

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
