/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:32:34 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/05 16:11:36 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;
	int		tmp;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	tmp = first->value;
	first->value = second->value;
	second->value = tmp;
}

void	swap_a(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	swap(stack_a);
}

void	swap_b(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	swap(stack_b);
}

void	swap_s(t_stack **stack_a, t_stack **stack_b)
{
	if ((!stack_b || !*stack_b || !(*stack_b)->next)
		&& (!stack_a || !*stack_a || !(*stack_a)->next))
		return ;
	swap(stack_a);
	swap(stack_b);
}
