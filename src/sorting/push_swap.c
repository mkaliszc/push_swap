/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:49:39 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/23 06:53:29 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_push_swap(char **args, int size, t_stack **stack_a, t_stack **stack_b)
{
	t_chunk	*chunks;
	t_cost	*cost;
	int		*array;

	array = ft_init_array(args, size);
	chunks = ft_create_chunk(array, size);
	ft_chunk_sort(stack_a, stack_b, chunks);
	if(ft_stack_length(stack_a) <= 3)
		case_three(stack_a);
	cost = malloc(sizeof(t_cost));
	if (cost == NULL)
		return ;
	ft_turk_sort(stack_a, stack_b, cost);
}
