/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:18:11 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/27 16:15:55 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wich_cst(int	size)
{
	if (size <= 10)
		return (5);
	else if (size <= 150)
		return (8);
	else
		return (18);
}

t_chunk	*ft_create_chunk(int *array, int size)
{
	t_chunk	*chunk;

	chunk = malloc(sizeof(t_chunk));
	if (chunk == NULL)
		return (NULL);
	chunk->values = array;
	chunk->middle = size / 2;
	chunk->cst_set = ft_wich_cst(size);
	chunk->chunk_size = size / chunk->cst_set;
	chunk->start = chunk->values[chunk->middle - chunk->chunk_size];
	chunk->end = chunk->values[chunk->middle + chunk->chunk_size];
	chunk->total_size = size;
	return (chunk);
}

int	value_in_chunk(t_chunk *chunk, t_stack **stack)
{
	t_stack	*tmp;
	int		i;
	int		j;

	j = 0;
	tmp = *stack;
	while (j < chunk->total_size)
	{
		i = chunk->start;
		while (i <= chunk->end)
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

void	ft_chunk_sort(t_chunk *chunk, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*element;
	int		test;

	if (!chunk || !stack_a || !*stack_a)
		return ;
	while (ft_stack_length(*stack_a) > 3)
	{
		while (value_in_chunk(chunk, stack_a) == 1)
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
		}
		chunk->start -= chunk->chunk_size;
		chunk->end += chunk->chunk_size;
	}
}
