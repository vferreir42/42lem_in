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

//	map = malloc(sizeof(t_map));

	put_read_in_list(&map);
	create_graph(map);
	add_position(map);
	add_nbway(map);
	all_way(&map);

	display_list(map);
	printf("\n");

	send_ant_in_way(map);

	return (0);
}
