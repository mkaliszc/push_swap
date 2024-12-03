/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 03:14:27 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/03 15:02:54 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	rotate(t_stack	**stack)
{
	if (!stack || !*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	rotate_a(t_stack	**stack_a)
{
	if (!stack_a || !*stack_a)
		return ;
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rotate_b(t_stack	**stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rotate_r(t_stack	**stack_a, t_stack	**stack_b)
{
	if (!stack_a || !*stack_a || !stack_b || !*stack_b)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
