/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:32:11 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/03 21:51:58 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*pos;
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	pos = *stack;
	tmp = NULL;
	(*stack)->previous->next = NULL;
	while (pos != NULL)
	{
		tmp = pos->next;
		free(pos);
		pos = tmp;
	}
}

void	ft_free_array(int *array)
{
	free(array);
}

void	ft_free_chunk(t_chunk *chunk)
{
	free(chunk);
}

void	ft_free_all(int *array, t_chunk *chunk, t_stack **s_a)
{
	ft_free_array(array);
	ft_free_chunk(chunk);
	ft_free_stack(s_a);
}
