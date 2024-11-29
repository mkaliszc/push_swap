/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 06:41:49 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/29 02:29:45 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	case_three(t_stack **stack)
{
	int	fst;
	int	scd;
	int	trd;

	fst = (*stack)->value;
	scd = (*stack)->next->value;
	trd = (*stack)->previous->value;
	if ((fst < scd) && (scd > trd) && (fst < trd))
	{
		reverse_rotate_a(stack);
		swap_a(stack);
	}
	else if ((fst < scd) && (scd > trd) && (fst > trd))
		reverse_rotate_a(stack);
	else if ((fst > scd) && (scd < trd) && (fst > trd))
		rotate_a(stack);
	else if ((fst > scd) && (scd > trd))
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else
		swap_a(stack);
}
