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

# define WRONG 0

# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>

typedef struct	s_map
{
	t_list *tab;
	t_list *way_inverse;
	t_list *all_the_way;
	t_list *way;
	t_list *print;
	t_list *read;

	int type_salle;
	int name_ant;
	int nb_ant;
	int nb_start;
	int nb_end;
	int nb_total;
}				t_map;

int				ft_printf(const char *format, ...);

void	read_info(t_map *map);
int extract_name(t_map *map, char *line);
int gestion_connexion(t_map *map, char *line);
void 	free_tab(char **tab);

void  parsing(t_map *map);

void display_chemin(t_map map);
void display_list(t_map map);

t_list	*shortest_way(t_map *map);
void add_position(t_map map);
void 	add_nbway(t_map map);
void all_way(t_map *map);
void create_graph(t_map map);

void send_ant_in_way(t_map map);
void display_way(t_map *map, t_list *way, int nb_ant, int name);

#endif
