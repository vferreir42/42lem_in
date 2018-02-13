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

char *ft_strchr_before(char *str, char c)
{
	char *new;
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!(new = malloc(sizeof(char) * i + 1)))
		return (0);
	new[i] = '\0';
	while (i-- > 0)
		new[i] = str[i];
	return (new);
}

int main(void)
{
	t_map map;


	read_info(&map);
	printf("READ OK\n");
	create_graph(map);
	printf("CREATE GRAPH OK\n");
	add_position(map);
	printf("ADD POSITION OK\n");
	add_nbway(map);
	printf("ADD NB WAY OK\n");
	all_way(&map);
	printf("FIND ALL WAY OK\n");
	display_list(map);
	printf("\n");


	if (map.all_the_way == NULL)
	{
		printf("Error\n");
		return (0);
	}

	send_ant_in_way(map);
	return (0);
}
