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

int gestion_comment(t_map *map, char *line)
{
  if (ft_strcmp(line, "##start") == 0)
  {
    map->type_salle = 1;
    map->nb_start++;
    if (map->nb_start != 1)
      return (WRONG);
  }
  else if (ft_strcmp(line, "##end") == 0)
  {
    map->type_salle = 2;
    map->nb_end++;
    if (map->nb_end != 1)
      return (WRONG);
  }
  else if (map->type_salle != 0)
    return (WRONG);
  return (1);
}

void set_variable_read(t_map *map)
{
  map->type_salle = 0;
  map->nb_start = 0;
  map->nb_end = 0;
  map->nb_total = 0;
  map->nb_ant = -1;
  map->tab = NULL;
}

void	read_info(t_map *map)
{
  char *line;

  set_variable_read(map);
  while (get_next_line(0, &line) > 0)
  {
    if (partie_nb_ant(line) == 1)
      if (map->nb_ant == -1)
        map->nb_ant = ft_atoi(line);
      else
        return ;
    else if (ft_strncmp(line, "#", 1) == 0)
    {
      if (gestion_comment(map, line) == WRONG)
        return ;
    }
    else if (ft_strchr(line, '-') == NULL)
    {
      if (extract_name(map, line) == WRONG)
        return ;
    }
    else
      break ;
    free(line);
  }
  if (gestion_connexion(map, line) == WRONG)
    return ;
}
