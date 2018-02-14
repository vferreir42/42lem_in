/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:12:45 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/14 18:19:58 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	set_variable_name(t_map *map, t_list *next, int type_salle)
{
	next->info_salle = type_salle;
	if (type_salle == 1)
		next->nb_way = 1;
	map->nb_total += type_salle;
	next->co = NULL;
	next->gris = 0;
	next->nb_way = 0;
	next->position = -1;
}

int		extract_name_parsing(t_map *map, char **tab)
{
	t_list			*begin;
	int				i;

	i = -1;
	while (tab[++i])
		;
	if (i != 3)
		return (WRONG);
	begin = map->tab;
	while (begin)
	{
		if (ft_strcmp(begin->content, tab[0]) == 0)
			return (WRONG);
		begin = begin->next;
	}
	return (1);
}

int		extract_name(t_map *map, char *line)
{
	char			**tab;
	static t_list	*next;

	tab = ft_strsplit(line, ' ');
	if (extract_name_parsing(map, tab) == WRONG)
		return (WRONG);
	if (map->tab)
	{
		next->next = ft_lstnew(tab[0], ft_strlen(tab[0]) * 8);
		next = next->next;
	}
	else
	{
		map->tab = ft_lstnew(tab[0], ft_strlen(tab[0]) * 8);
		next = map->tab;
	}
	set_variable_name(map, next, map->type_salle);
	map->type_salle = 0;
	return (1);
}
