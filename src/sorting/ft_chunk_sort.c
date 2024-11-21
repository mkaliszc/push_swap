/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:27:33 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/21 02:15:22 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_chunk(int *chunk, int nb)
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

void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b, t_chunk *chunks)
{
	t_stack	*head_a;

	head_a = *stack_a;
	while (head_a && chunks->mid_end <= chunks->nbr_of_chunks
		&& chunks->mid_start >= 0)
	{
		if (is_in_chunk(chunks->values[chunks->mid_start], head_a->value))
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		else if (is_in_chunk(chunks->values[chunks->mid_end], head_a->value))
		{
			push_b(stack_a, stack_b);
		}
		else
			rotate_a(stack_a);
		chunks->mid_start -= 1;
		chunks->mid_end += 1;
		head_a = *stack_a;
	}
}
