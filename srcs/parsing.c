/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 13:25:05 by vferreir          #+#    #+#             */
/*   Updated: 2018/02/13 13:25:06 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void quit(t_map *map)
{
  t_list *sauv;

  write (1, "Error\n", 6);
  while (map->tab)
  {
    sauv = map->tab;
    free(map->tab->content);
    map->tab = map->tab->next;
    free(sauv);
  }
  exit (0);
}

void parsing(t_map *map)
{
  t_list *list;

  if (map->nb_ant <= 0)
    quit(map);
  if (map->nb_start != 1 || map->nb_end != 1 || map->nb_total != 3)
    quit(map);
}
