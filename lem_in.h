/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:57:16 by vferreir          #+#    #+#             */
/*   Updated: 2018/01/19 13:57:17 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct	s_map
{
	t_list *tab;
	t_list *all_the_way;
	t_list *way;
	int nb_ant;
}				t_map;

int				ft_printf(const char *format, ...);

void put_connexion_in_tab(t_list *tab, char **connexion);
void extract_information(t_map *map, t_list *read);
void put_read_in_list(t_map *map);
char *ft_strchr_before(char *str, char c);

void display(t_list *way, int nb_ant);
void display_chemin(t_map map);
void display_list(t_map map);

t_list	*shortest_way(t_map *map);
void add_position(t_map map);
void 	add_nbway(t_map map);
void all_way(t_map *map);
void create_graph(t_map map);

void send_ant_in_way(t_map map);

#endif
