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

void quit(void)
{
  write (1, "Error\n", 6);
  exit (0);
}

void parsing(t_map map)
{
  t_list *list;

  if (map.nb_ant <= 0)
    quit();
  if (map.nb_start != 1 || map.nb_end != 1 || map.nb_total != 3)
    quit();
}
