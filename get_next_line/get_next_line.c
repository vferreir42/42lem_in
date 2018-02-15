/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 19:37:46 by vferreir          #+#    #+#             */
/*   Updated: 2017/12/12 14:36:57 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int			restexist(char **line, char **rest)
{
	char *temp;

	if (*rest != NULL)
	{
		if (ft_strchr(*rest, '\n') != NULL)
		{
			*line = ft_strdup(*rest);
			ft_bzero(ft_strchr(*line, '\n'), ft_strlen(ft_strchr(*line, '\n')));
			temp = ft_strdup(*rest + ft_strlen(*line) + 1);
			free(*rest);
			*rest = temp;
			return (LINEREAD);
		}
		*line = ft_strdup(*rest);
		free(*rest);
		*rest = NULL;
	}
	return (RIGHT);
}

static int			readline(char **line, char **rest, int fd)
{
	int						nb;
	char					*temp;
	char					buf[BUFF_SIZE + 1];

	while ((nb = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[nb] = '\0';
		*rest = ft_strjoindel(*rest, buf);
		if (ft_strchr(*rest, '\n') != NULL)
		{
			*line = ft_strjoindel(*line, *rest);
			ft_bzero(ft_strchr(*line, '\n'), ft_strlen(ft_strchr(*line, '\n')));
			temp = ft_strdup(ft_strchr(*rest, '\n') + 1);
			ft_strdel(rest);
			*rest = temp;
			return (LINEREAD);
		}
	}
	if (nb == -1)
		return (-1);
	return (RIGHT);
}

int					get_next_line(int fd, char **line)
{
	static char			*rest;
	int					nb;

	if (fd < 0 || line == NULL)
		return (-1);
	*line = NULL;
	if (rest != NULL)
		if ((nb = restexist(line, &rest)) != RIGHT)
			return (nb);
	if ((nb = readline(line, &rest, fd)) != RIGHT)
		return (nb);
	if (rest || (*line && *line[0] > 0))
	{
		if (rest)
		{
			*line = ft_strjoindel(*line, rest);
			ft_bzero(rest, ft_strlen(rest));
		}
		return (LINEREAD);
	}
	return (END);
}
