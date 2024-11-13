/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 01:27:41 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/13 02:19:41 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sorted(t_stack **stack, int nbr_of_args)
{
	t_stack	*pos;
	int		i;

	i = 1;
	pos = *stack;
	while (i < nbr_of_args)
	{
		if (pos->value < pos->next->value)
		{
			i++;
			pos = pos->next;
		}
		else
			return (1);
	}
	return (0);
}
