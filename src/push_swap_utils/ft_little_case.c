/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 06:41:49 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/03 21:52:05 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && first < third)
		swap_a(stack);
	else if (first > second && second > third)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (first > second && second < third && first > third)
		rotate_a(stack);
	else if (first < second && second > third && first < third)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (first < second && second > third && first > third)
		reverse_rotate_a(stack);
}

void	case_two(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = first->next;
	if (first->value > second->value)
		swap_a(stack);
}
