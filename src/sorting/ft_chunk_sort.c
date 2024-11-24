/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:27:33 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/24 02:31:56 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	in_chunk(int *chunk, int nb, int chunk_size)
{
	int	i;

	i = 0;
	while (i < chunk_size)
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

    if (!stack || !tab || !tab->values)
		return (0);

	count = 0;
	pos = stack;
	ft_printf("Checking values in chunks - mid_start: %d, mid_end: %d\n", tab->mid_start, tab->mid_end);
	while (count < ft_stack_length(stack))
	{
        if (tab->mid_start >= 0 && tab->mid_start < tab->nbr_of_chunks &&
            in_chunk(tab->values[tab->mid_start], pos->value, tab->chunks_sizes[tab->mid_start]))
            return (1);
        if (tab->mid_end >= 0 && tab->mid_end < tab->nbr_of_chunks &&
            in_chunk(tab->values[tab->mid_end], pos->value, tab->chunks_sizes[tab->mid_end]))
            return (1);
		pos = pos->next;
		count++;
	}
	return (0);
}

void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b, t_chunk *tab)
{
	t_stack	*start_pos;
	int	full;

	while (ft_stack_length(*stack_a) > 3)
	{
		start_pos = *stack_a;
		full = 0;
		//ft_printf("Current stack_a length: %d\n", ft_stack_length(*stack_a));
        //ft_printf("mid_start: %d, mid_end: %d\n", tab->mid_start, tab->mid_end);
		while (value_in_chunk(*stack_a, tab) == 1 && full < ft_stack_length(*stack_a))
		{
			if (in_chunk(tab->values[tab->mid_start], (*stack_a)->value, tab->chunks_sizes[tab->mid_start]))
			{
				//ft_printf("Pushing to B (mid_start): %d\n", (*stack_a)->value);
				push_b(stack_a, stack_b);
				reverse_rotate_b(stack_b);
				full = 0;
			}
			else if (in_chunk(tab->values[tab->mid_end], (*stack_a)->value, tab->chunks_sizes[tab->mid_end]))
			{
				//ft_printf("Pushing to B (mid_end): %d\n", (*stack_a)->value);
				push_b(stack_a, stack_b);
				full = 0;
			}
			else
			{
				reverse_rotate_a(stack_a);
				full++;
				if (*stack_a == start_pos || full >= ft_stack_length(*stack_a))
					break;

			}
			//ft_printf("After operation - stack_a: %d, stack_b: %d\n", ft_stack_length(*stack_a), ft_stack_length(*stack_b));
		}
		if (tab->mid_start > 0)
			tab->mid_start -= 1;
		if (tab->mid_end < tab->nbr_of_chunks - 1)
			tab->mid_end += 1;
	}
	//ft_printf("%d\n", ft_stack_length(*stack_b));
}

// stack_a decrease till length = 0 and stack_b stay at 0