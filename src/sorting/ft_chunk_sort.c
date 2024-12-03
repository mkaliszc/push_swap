/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:18:11 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/03 16:28:45 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	value_in_chunk(t_chunk *chunk, t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int		j;

	j = 0;
	if (!*stack)
		return (0);
	tmp = *stack;
	while (j < chunk->total_size)
	{
		i = chunk->start;
		while (i < chunk->end)
		{
			if (tmp->value == chunk->values[i])
				return (1);
			i++;
		}
		tmp = tmp->next;
		j++;
	}
	return (0);
}

int	wich_move(t_chunk *chunk, t_stack *element)
{
	int	i;

	i = chunk->start;
	while (i <= chunk->end)
	{
		if (chunk->values[i] == element->value)
		{
			if (i < chunk->middle)
				return (-1);
			else if (i >= chunk->middle)
				return (1);
		}
		i++;
	}
	return (0);
}

void	update_chunk(t_chunk *chunk, t_stack **stack)
{
	if (value_in_chunk(chunk, stack) == 0)
	{
		if (chunk->start - chunk->chunk_size < 0)
			chunk->start -= chunk->start;
		else
			chunk->start -= chunk->chunk_size;
		if (chunk->end + chunk->chunk_size > chunk->total_size)
			chunk->end = chunk->total_size - 1;
		else
			chunk->end += chunk->chunk_size;
	}
}

void	ft_chunk_sort(t_chunk *chunk, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*element;
	int		test;

	if (!chunk || !stack_a || !*stack_a)
		return ;
	while (ft_stack_length(*stack_a) > 3)
	{
		element = *stack_a;
		test = wich_move(chunk, element);
		if (test == 1)
			push_b(stack_a, stack_b);
		else if (test == -1)
		{
			push_b(stack_a, stack_b);
			rotate_b(stack_b);
		}
		else
			rotate_a(stack_a);
		update_chunk(chunk, stack_a);
	}
}
