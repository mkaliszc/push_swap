/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:27:33 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/25 00:06:43 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* void	ft_print_stack(t_stack **stack)
{
	t_stack *current;

	
	if (!stack || !*stack)
	{
		ft_printf("debug\n");
		return ;
	}
	current = *stack;
	do
	{
		ft_printf("value : %d --> ", current->value);
		current = current->next;
	} while (current != *stack);
} */

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

/* int	value_in_chunk(t_stack *stack, t_chunk *tab)
{
	t_stack	*pos;
	int		count;

    if (!stack || !tab || !tab->values)
		return (0);

	count = 0;
	pos = stack;
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
} */

int	value_in_chunk(t_stack *stack, t_chunk *tab)
{
	t_stack	*pos;
	int		count;

    if (!stack || !tab || !tab->values)
		return (0);

	count = 0;
	pos = stack;
	while (count < ft_stack_length(stack))
	{
        if (tab->mid_start >= 0 && tab->mid_start < tab->nbr_of_chunks &&
            in_chunk(tab->values[tab->mid_start], pos->value, tab->chunks_sizes[tab->mid_start]))
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
		while (value_in_chunk(*stack_a, tab) == 1 && full < ft_stack_length(*stack_a) && ft_stack_length(*stack_a) > 3)
		{
			if (in_chunk(tab->values[tab->mid_start], (*stack_a)->value, tab->chunks_sizes[tab->mid_start]))
			{
				push_b(stack_a, stack_b);
				full = 0;
			}
			else
			{
				rotate_a(stack_a);
				full++;
				if (*stack_a == start_pos || full >= ft_stack_length(*stack_a))
					break;
			}
		}
		tab->mid_start++;
	}
}

/* void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b, t_chunk *tab)
{
	t_stack	*start_pos;
	int	full;

	while (ft_stack_length(*stack_a) > 3)
	{
		start_pos = *stack_a;
		full = 0;
		while (value_in_chunk(*stack_a, tab) == 1 && full < ft_stack_length(*stack_a) && ft_stack_length(*stack_a) > 3)
		{
			if (in_chunk(tab->values[tab->mid_start], (*stack_a)->value, tab->chunks_sizes[tab->mid_start]))
			{
				push_b(stack_a, stack_b);
				reverse_rotate_b(stack_b);
				full = 0;
			}
			else if (in_chunk(tab->values[tab->mid_end], (*stack_a)->value, tab->chunks_sizes[tab->mid_end]))
			{
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
		}
		if (tab->mid_start > 0)
			tab->mid_start -= 1;
		if (tab->mid_end < tab->nbr_of_chunks - 2)
			tab->mid_end += 1;
	}
} */
