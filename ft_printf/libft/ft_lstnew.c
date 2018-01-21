/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:34:53 by vferreir          #+#    #+#             */
/*   Updated: 2017/11/16 19:08:47 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;

	if (!(ptr = malloc(sizeof(t_list))))
		return (0);
	if (!(ptr->content = malloc(content_size)))
		return (0);
	if (content != NULL)
	{
		ptr->content = ft_memcpy(ptr->content, content, content_size);
		ptr->content_size = content_size;
	}
	else
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	ptr->next = NULL;
	return (ptr);
}
