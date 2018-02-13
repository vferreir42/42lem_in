/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:46:52 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/13 15:46:54 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int    partie_nb_ant(char *line)
{
  int i;

  i = 0;
  while (line[i])
  {
    if (ft_isdigit(line[i]) == 0)
      return (0);
    i++;
  }
  return (1);
}

int extract_name(t_map *map, char *line, int type_salle)
{
  int i;
  char **tab;
  static t_list *next;
  t_list *begin;

  tab = ft_strsplit(line, ' ');

  // parsing 3 colonnes
  i = -1;
  while (tab[++i])
    ;
  if (i != 3)
    return (WRONG);

  // parsing pas de salle du meme nom existante deja
  begin = map->tab;
  while (begin)
  {
    if (ft_strcmp(begin->content, tab[0]) == 0)
      return (WRONG);
    begin = begin->next;
  }

  // ajout de l'information
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
  next->info_salle = type_salle;
  if (type_salle == 1)
    next->nb_way = 1;
  next->co = NULL;
  next->gris = 0;
  next->nb_way = 0;
  next->position = 99999;
  return (1);
}

int extract_connexion(t_map *map, char *line)
{
  t_list *next;
  t_list *nxt;
  int i;
  char **tab;

  tab = ft_strsplit(line, '-');
  i = -1;
  while (tab[++i])
    ;
  if (i != 2)
    return (WRONG);
  next = map->tab;
  while (next && ft_strcmp(next->content, tab[0]) != 0)
    next = next->next;
  if (next == NULL)
    return (WRONG);
  if (next->co == NULL)
    next->co = ft_lstnew(tab[1], ft_strlen(next->content) * 8);
  else
  {
    nxt = next->co;
    while (nxt->next)
      nxt = nxt->next;
    nxt->next = ft_lstnew(tab[1], ft_strlen(next->content) * 8);
  }

  // Pareil mais en inversant num dans tab
  next = map->tab;
  while (next && ft_strcmp(next->content, tab[1]) != 0)
    next = next->next;
  if (next == NULL)
    return (WRONG);
  if (next->co == NULL)
    next->co = ft_lstnew(tab[0], ft_strlen(next->content) * 8);
  else
  {
    nxt = next->co;
    while (nxt->next)
      nxt = nxt->next;
    nxt->next = ft_lstnew(tab[0], ft_strlen(next->content) * 8);
  }
  return (1);
}

void	read_info(t_map *map)
{
  char *line;
  int type_salle;

  map->nb_start = 0;
  map->nb_end = 0;
  map->nb_ant = -1;
  map->tab = NULL;
  type_salle = 0;
  while (get_next_line(0, &line) > 0)
  {
    // Check if is number nb_ant
    if (partie_nb_ant(line) == 1)
    {
      if (map->nb_ant == -1)
        map->nb_ant = ft_atoi(line);
      else
      {
        printf("Stop dans nb fourmi\n");
        return ;
      }
    }
    //comment
    else if (ft_strncmp(line, "##", 2) == 0)
    {
      if (ft_strcmp(line, "##start") == 0)
      {
        type_salle = 1;
        map->nb_start++;
        if (map->nb_start != 1)
        {
          printf("Stop start\n");
          return ;
        }
      }
      if (ft_strcmp(line, "##end") == 0)
      {
        type_salle = 2;
        map->nb_end++;
        if (map->nb_end != 1)
        {
          printf("Stop end\n");
          return ;
        }
      }
    }
    // Extract name salle
    else if (ft_strchr(line, '-') == NULL)
    {
      if (extract_name(map, line, type_salle) == WRONG)
      {
        printf("Stop dans salle\n");
        return ;
      }
      type_salle = 0;
    }
    else
    {
      if (extract_connexion(map, line) == WRONG)
      {
        printf("Stop dans connexion\n");
        return ;
      }
      break ;
    }
  }
  // Extract connexion
  while (get_next_line(0, &line) > 0)
  {
    if (extract_connexion(map, line) == 0)
    {
      printf("Stop dans connexion\n");
      return ;
    }
  }
}
