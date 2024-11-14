/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 02:32:34 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/14 03:03:40 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap(t_stack *head)
{
	t_stack	*node;

	node = head->next;
	node->previous = head->previous;
	head->next = node->next;
	node->next = head;
	head->previous = node;
	head->next->previous = head;
}

void	swap_a(t_stack **stack_a)
{
	swap(&stack_a);
	ft_printf("sa\n");
}

void	swap_b(t_stack **stack_b)
{
	swap(&stack_b);
	ft_printf("sb\n");
}

void	swap_s(t_stack **stack_a, t_stack **stack_b)
{
	swap(&stack_a);
	swap(&stack_b);
	ft_printf("ss\n");
}
