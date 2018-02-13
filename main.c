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
//	printf("READ OK\n");
	parsing(map);
//	printf("PARSING OK\n");
	create_graph(map);
//	printf("CREATE GRAPH OK\n");
	add_position(map);
//	printf("ADD POSITION OK\n");
	add_nbway(map);
//	printf("ADD Nb WAY OK\n");
	all_way(&map);
//	printf("FIND ALL WAY OK\n");
//	display_list(map);
//	printf("\n");

	if (map.all_the_way == NULL)
	{
		printf("Error\n");
		return (0);
	}

	send_ant_in_way(map);
	return (0);
}
