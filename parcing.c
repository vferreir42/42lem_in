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

void  parcing_name_salle(t_map *map, t_list *info)
{
  t_list *begin;

  begin = map->tab->next;
//  printf("\nnext %s\n", info->content);

  while (begin->next)
  {
  //  printf("%s\n", begin->content);
    if (ft_strcmp(begin->content, info->content) == 0)
    {
      printf("ERROR\n");
      exit (0);
    }
    if (info->info_salle == 1 && begin->info_salle == 1)
    {
      printf("ERROR\n");
      exit (0);
    }
    if (info->info_salle == 2 && begin->info_salle == 2)
    {
      printf("ERROR\n");
      exit (0);
    }
    begin = begin->next;
  }
}
