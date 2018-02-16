/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_connexion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:22:45 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/16 18:06:19 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		verif_other_exist(t_map *map, char *line)
{
	t_list	*next;

	next = map->tab;
	while (next && ft_strcmp(next->content, line) != 0)
		next = next->next;
	if (!next)
		return (WRONG);
	else
		return (1);
}

t_list	*extract_connexion_parsing(t_map *map, char **tab, int v1, int v2)
{
	t_list	*next;
	int		i;

	i = -1;
	while (tab[++i])
		;
	if (i != 2)
		return (NULL);
	next = map->tab;
	while (next && ft_strcmp(next->content, tab[v1]) != 0)
		next = next->next;
	if (next == NULL)
		return (NULL);
	if (verif_other_exist(map, tab[v2]) == WRONG)
		return (NULL);
	return (next);
}

int		extract_connexion(t_map *map, char *line, int v0, int v1)
{
	t_list	*next;
	t_list	*nxt;
	char	**tab;

	tab = ft_strsplit(line, '-');
	while (v0 < 2)
	{
		next = extract_connexion_parsing(map, tab, v0, v1);
		if (next == NULL)
			return (WRONG);
		if (next->co == NULL)
			next->co = ft_lstnew(tab[v1], ft_strlen(tab[v1]) * 10);
		else
		{
			nxt = next->co;
			while (nxt->next)
				nxt = nxt->next;
			nxt->next = ft_lstnew(tab[v1], ft_strlen(tab[v1]) * 10);
		}
		v0++;
		v1 = 0;
	}
	free_tab(tab);
	free(tab);
	return (1);
}

int		gestion_connexion(t_map *map, char *line)
{
	if (extract_connexion(map, line, 0, 1) == WRONG)
		return (WRONG);
	free(line);
	while (get_next_line(0, &line) > 0)
	{
		map->gnl = ft_strjoindel(map->gnl, line);
		map->gnl = ft_strjoindel(map->gnl, "\n");
		if (extract_connexion(map, line, 0, 1) == 0)
			return (WRONG);
		free(line);
	}
	free(line);
	return (1);
}
