/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:32:34 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/17 00:31:38 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap(t_stack **head)
{
	t_stack	*first;
	t_stack	*second;

	if (!head || !*head || !(*head)->next)
		return ;
	first = *head;
	second = first->next;
	if(second->next)
		second->next->previous = first;
	if(first->previous)
		first->previous->next = second;
	first->next = second->next;
	second->next = first;
	second->previous = first->previous;
	first->previous = second;
}

void	swap_a(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	swap(stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	swap(stack_b);
	ft_printf("sb\n");
}

void	swap_s(t_stack **stack_a, t_stack **stack_b)
{
	if ((!stack_b || !*stack_b || !(*stack_b)->next) &&
	(!stack_a || !*stack_a || !(*stack_a)->next))
		return ;
	swap(&stack_a);
	swap(&stack_b);
	ft_printf("ss\n");
}
