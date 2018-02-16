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

int	main(void)
{
	t_map map;

	map.gnl = NULL;
	read_info(&map, NULL);
	parsing(&map);
	graph(map, NULL, NULL, map.tab);
	add_position(map);
	add_nbway(map);
	all_way(&map);
	if (map.all_the_way == NULL)
	{
		write(1, "ERROR\n", 6);
		return (0);
	}
	write(1, map.gnl, ft_strlen(map.gnl));
	write(1, "\n", 1);
	send_ant_in_way(map);
	return (0);
}
