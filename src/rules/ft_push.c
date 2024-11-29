/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 00:07:38 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/29 03:39:05 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (!stack_b || !*stack_b)
		return ;
	node = *stack_b;
	if (node->next == node)
		*stack_b = NULL;
	else
	{
		node->next->previous = node->previous;
		node->previous->next = node->next;
		*stack_b = node->next;
	}
	if (!*stack_a)
	{
		node->next = node;
		node->previous = node;
	}
	else
		ft_lstadd_front(stack_a, node);
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	if (!stack_a || !*stack_a)
		return ;
	node = *stack_a;
	if (node->next == node)
		*stack_a = NULL;
	else
	{
		node->next->previous = node->previous;
		node->previous->next = node->next;
		*stack_a = node->next;
	}
	node->next = node;
	node->previous = node;
	if (!*stack_b)
		*stack_b = node;
	else
		ft_lstadd_front(stack_b, node);
	ft_printf("pb\n");
}
