/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 18:30:13 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/27 15:33:55 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <wchar.h>
# include <locale.h>

typedef struct	s_map
{
	char		*temp;
	char		zero;
	int			argvnext;
	int			count;
	int			i;
	int			strisnul;
	int			attributespace;
	int			attributplus;
	int			attributplusok;
	int			precision;
	int			displayespacewithprecision;
	int			gestionlongeur;
	int			attributmoins;
	int			attributhash;
	int			longeur;
	int			precisionoux;
	int			precisionzero;
	int			champ;
	int			precisionzeroput;
}				t_map;

void			conversion_specifier(void *argv, char *line, t_map *map);
void			conversion_wchar(wchar_t argv, t_map *map, int t);
void			conversion_char(char argv, t_map *map, char c);
void			conversion_modulo(t_map *map);
void			conversion_str(char *str, t_map *map);
void			conversion_wstr(wchar_t *str, t_map *map);
void			conversion_int(long long argv, t_map *map);
void			conversion_long(long long argv, t_map *map);
void			conversion_unsigned_int(unsigned int argv, t_map *map, char c);
void			conversion_unsign_long(unsigned long argv, t_map *map, char c);
void			conversion_pointer(unsigned long argv, t_map *map);
void			flag_characters(void *argv, char *line, t_map *map);
void			flag_sign_negative(void *argv, char *line, t_map *map);
void			flag_sign_positive(int argv, t_map *map, char *line);
int				flag_hash(t_map *map, char c, int yes);
void			fonction_counting_positive(t_map *map, int i, int t);
void			fonction_counting_negative(t_map *map, int i, int t);
void			counting_field(void *argv, char *line, t_map *map);
void			counting_precision(char *line, t_map *map);
void			length_modifier(void *argv, char *line, t_map *map);
void			fonction_flag_pos(char *str, t_map *map, long argv, char c);
void			fonction_flag_neg(char *str, t_map *map, long argv, char c);
int				ft_printf(const char *format, ...);

#endif
