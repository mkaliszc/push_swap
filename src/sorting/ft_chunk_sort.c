/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:27:33 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/22 06:18:12 by mkaliszc         ###   ########.fr       */
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

void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b, t_chunk *tab)
{
	t_stack	*head_a;

	head_a = *stack_a;
	while (ft_stack_length(stack_a) > 3)
	{
		if (in_chunk(tab->values[tab->mid_start], head_a->value))
		{
			push_b(stack_a, stack_b);
			if (!in_chunk(tab->values[tab->mid_start], head_a->next->value) &&
			!in_chunk(tab->values[tab->mid_end], head_a->next->value))
				rotate_r(stack_a, stack_b);
			else
				rotate_b(stack_b);
		}
		else if (in_chunk(tab->values[tab->mid_end], head_a->value))
		{
			push_b(stack_a, stack_b);
		}
		else
			rotate_a(stack_a);
		tab->mid_start -= 1;
		tab->mid_end += 1;
		head_a = *stack_a;
	}
}
