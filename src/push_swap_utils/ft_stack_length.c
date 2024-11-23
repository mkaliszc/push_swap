/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 06:06:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/23 19:33:58 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stack_length(t_stack *stack)
{
	t_stack	*pos;
	int		count;

	if (!stack)
		return (0);
	pos = stack;
	count = 0;
	while (pos->next != stack)
	{
		count++;
		pos = pos->next;
	}
	return (count);
}