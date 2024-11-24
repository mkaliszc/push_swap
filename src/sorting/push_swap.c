/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:49:39 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/24 02:31:40 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_stack(t_stack **stack)
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
}

void	push_swap(char **args, int size, t_stack **stack_a, t_stack **stack_b)
{
	t_chunk	*chunks;
	t_cost	*cost;
	int		*array;

	ft_print_stack(stack_a);
	array = ft_init_array(args, size);
	chunks = ft_create_chunk(array, size);
	//ft_printf("Before chunk_sort: stack_a length=%d\n", ft_stack_length(*stack_a));
	ft_chunk_sort(stack_a, stack_b, chunks);
	//ft_printf("After chunk_sort: stack_a length=%d, stack_b length=%d\n", ft_stack_length(*stack_a), ft_stack_length(*stack_b));
	if(ft_stack_length(*stack_a) == 3)
		case_three(stack_a);
	cost = malloc(sizeof(t_cost));
 	if (cost == NULL)
		return ;
	//ft_printf("test3\n");
	ft_turk_sort(stack_a, stack_b, cost);
	//ft_printf("test4\n");
	ft_free_all(args, chunks, stack_a, stack_b);
}
