/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 05:43:17 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/25 00:32:10 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_gap(t_stack *head_a, int value)
{
	t_stack	*current;
	int		pos;
	int		gap_pos;

	if (!head_a)
		return(0);
	current = head_a;
	pos = 0;
	gap_pos = 0;
	while (pos < ft_stack_length(head_a))
	{
		if (current->value < value && current->next->value > value)
			gap_pos = pos + 1;
		current = current->next;
		pos++;
	}
	return (gap_pos);
}

int	get_rotate_cost(t_stack **stack, int target_gap)
{
	int	length;

	length = ft_stack_length(*stack);
	if (target_gap <= length / 2)
		return (target_gap);
	return (length - target_gap);
}

int	element_rotate_cost(t_stack **stack, t_stack *element)
{
	t_stack	*head;
	int	i;
	int	length;

	i = 0;
	head = *stack;
	length = ft_stack_length(*stack);
	while (head != element)
	{
		head = head->next;
		i++;
	}
	if (i <= length / 2)
		return (i);
	return (length - i);
}

void	rotate_and_push(t_stack **stack_a, t_stack **stack_b, t_stack *best)
{
	int	target_gap;
	t_stack	*target;
	int	i;

	i = 0;
	target = *stack_a;
	target_gap = find_gap(*stack_a, best->value);
	while (i < target_gap)
	{
		target = target->next;
		i++;
	}
	while (*stack_a != target || *stack_b != best)
	{
		if (*stack_a != target)
			rotate_a(stack_a);
		if (*stack_b != best)
			rotate_b(stack_b);
	}
	push_a(stack_a, stack_b);
}

void	ft_turk_sort(t_stack **stack_a, t_stack **stack_b, t_cost *cost)
{
	t_stack	*best_nbr;
	int		target;
	t_stack	*pos_b;
	
	while (ft_stack_length(*stack_b) > 0)
	{
		pos_b = *stack_b;
		cost->best = INT_MAX;
		best_nbr = NULL;
		while (pos_b != (*stack_b)->previous)
		{
			target = find_gap(*stack_a, pos_b->value);
			cost->nbr_op_a = get_rotate_cost(stack_a, target);
			cost->nbr_op_b = element_rotate_cost(stack_b, pos_b);
			cost->total = cost->nbr_op_a + cost->nbr_op_b;
			if(cost->total < cost->best)
			{
				cost->best = cost->total;
				best_nbr = pos_b;
			}
			pos_b = pos_b->next;
		}
		if (best_nbr)
			rotate_and_push(stack_a, stack_b, best_nbr);
		else
			break;
	}
}


