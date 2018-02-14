/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_connexion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 18:22:45 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/14 18:22:46 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int verif_other_exist(t_map *map, char *line)
{
  t_list *next;

  next = map->tab;
  while (next && ft_strcmp(next->content, line) != 0)
    next = next->next;
  if (!next)
    return (WRONG);
  else
    return (1);
}

t_list *extract_connexion_parsing(t_map *map, char **tab, int value_1, int value_2)
{
  t_list *next;
  int i;

  i = -1;
  while (tab[++i])
    ;
  if (i != 2)
    return (NULL);
  next = map->tab;
  while (next && ft_strcmp(next->content, tab[value_1]) != 0)
    next = next->next;
  if (next == NULL)
    return (NULL);
  if (verif_other_exist(map, tab[value_2]) == WRONG)
    return (NULL);
  return (next);
}

int extract_connexion(t_map *map, char *line)
{
  t_list *next;
  t_list *nxt;
  char **tab;

  tab = ft_strsplit(line, '-');
  next = extract_connexion_parsing(map, tab, 0, 1);
  if (next == NULL)
    return (WRONG);
  if (next->co == NULL)
    next->co = ft_lstnew(tab[1], ft_strlen(tab[0]));
  else
  {
    nxt = next->co;
    while (nxt->next)
      nxt = nxt->next;
    nxt->next = ft_lstnew(tab[1], ft_strlen(tab[0]));
  }
  next = extract_connexion_parsing(map, tab, 1, 0);
  if (next == NULL)
    return (WRONG);
  if (next->co == NULL)
    next->co = ft_lstnew(tab[0], ft_strlen(tab[0]));
  else
  {
    nxt = next->co;
    while (nxt->next)
      nxt = nxt->next;
    nxt->next = ft_lstnew(tab[0], ft_strlen(tab[0]));
  }
  return (1);
}

int gestion_connexion(t_map *map, char *line)
{
  if (extract_connexion(map, line) == WRONG)
    return (WRONG);
  free(line);
  while (get_next_line(0, &line) > 0)
  {
    if (extract_connexion(map, line) == 0)
      return (WRONG);
    free(line);
  }
  return (1);
}
