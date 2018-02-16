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

int main(void)
{
	t_map map;

	read_info(&map);
	parsing(&map);
	create_graph(map);
	add_position(map);
	add_nbway(map);
	all_way(&map);
	if (map.all_the_way == NULL)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	send_ant_in_way(map);
	return (0);
}
