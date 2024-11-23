/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:27:33 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/23 20:26:48 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_chunk(int *chunk, int nb)
{
	int	i;

	i = 0;
	while (chunk[i])
	{
		if (chunk[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

int	value_in_chunk(t_stack *stack, t_chunk *tab)
{
	t_stack	*pos;
	int		count;

	count = 0;
	pos = stack;
	while (count < ft_stack_length(stack) - 1)
	{
	    if (in_chunk(tab->values[tab->mid_start], pos->value) ||
        in_chunk(tab->values[tab->mid_end], pos->value))
            return (1);
        pos = pos->next;
        count++;
	}
	return (0);
}

void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b, t_chunk *tab)
{
	ft_printf("here\n");
	while (ft_stack_length(*stack_a) > 3)
	{
		while (value_in_chunk(*stack_a, tab) != 0)
		{
			if (in_chunk(tab->values[tab->mid_start], (*stack_a)->value))
			{
				push_b(stack_a, stack_b);
/* 				if (!in_chunk(tab->values[tab->mid_start], (*stack_a)->next->value) &&
				!in_chunk(tab->values[tab->mid_end], (*stack_a)->next->value))
					rotate_r(stack_a, stack_b);
				else */
				rotate_b(stack_b);
			}
			else if (in_chunk(tab->values[tab->mid_end], (*stack_a)->value))
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
		}
		ft_printf("test\n");
		tab->mid_start -= 1;
		tab->mid_end += 1;	
	}
}
