/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:49:39 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/29 03:38:43 by mkaliszc         ###   ########.fr       */
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

void	push_swap(int *array, int size, t_stack **stack_a, t_stack **stack_b)
{
	t_chunk	*chunks;
	t_cost	*cost;

	chunks = ft_create_chunk(array, size);
	if (chunks == NULL)
		return ;
	ft_chunk_sort(chunks, stack_a, stack_b);       
 	if(ft_stack_length(*stack_a) == 3 && is_sorted(stack_a, ft_stack_length(*stack_a)) != 0)
		case_three(stack_a);
	cost = malloc(sizeof(t_cost));
 	if (cost == NULL)
		return ;
	ft_turk_sort(stack_a, stack_b, cost);
 	while ((*stack_a)->index != 0)
		rotate_a (stack_a);
	//ft_free_all(args, chunks, stack_a, stack_b);
}
