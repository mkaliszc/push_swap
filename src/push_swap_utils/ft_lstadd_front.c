/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:06:39 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/01 21:45:53 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!*lst)
	{
		new->next = new;
		new->previous = new;
		*lst = new;
		return ;
	}
	new->previous = (*lst)->previous;
	(*lst)->previous->next = new;
	(*lst)->previous = new;
	new->next = *lst;
	*lst = new;
}
