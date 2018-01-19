/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vferreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:36:49 by vferreir          #+#    #+#             */
/*   Updated: 2017/11/16 19:28:41 by vferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new != NULL && *alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
	else if (new != NULL && *alst == NULL)
	{
		*alst = new;
	}
}
