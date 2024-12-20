/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:49:39 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/03 21:48:26 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(int *array, int size, t_stack **a, t_stack **b)
{
	t_chunk	*chunks;
	t_cost	*cost;

	chunks = ft_create_chunk(array, size - 1);
	if (chunks == NULL)
		return ;
	ft_chunk_sort(chunks, a, b);
	if (ft_stack_length(*a) == 3)
		case_three(a);
	cost = malloc(sizeof(t_cost));
	if (cost == NULL)
		return ;
	ft_turk_sort(a, b, cost);
	while ((*a)->value != get_min(*a))
	{
		if (get_pos_element(*a, get_min(*a)) <= ft_stack_length(*a) / 2)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
	free(cost);
	ft_free_all(array, chunks, a);
}
