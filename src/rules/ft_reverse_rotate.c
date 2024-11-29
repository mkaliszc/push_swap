/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 04:14:59 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/29 03:39:17 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reverse_rotate(t_stack	**stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->previous;
}

void	reverse_rotate_a(t_stack	**stack_a)
{
	if (!stack_a || !*stack_a)
		return ;
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack	**stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	reverse_rotate_r(t_stack	**stack_a, t_stack	**stack_b)
{
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
