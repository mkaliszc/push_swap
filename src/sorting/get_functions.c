/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:47:44 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/03 21:46:32 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack->next;
	min = stack->value;
	while (tmp != stack)
	{
		if (tmp->value <= min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	if (!stack)
		return (0);
	tmp = stack->next;
	max = stack->value;
	while (tmp != stack)
	{
		if (tmp->value >= max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_pos_element(t_stack *stack, int node)
{
	t_stack		*tmp;
	int			i;

	if (!stack)
		return (0);
	if (stack->value == node)
		return (0);
	i = 1;
	tmp = stack->next;
	while (tmp != stack)
	{
		if (tmp->value == node)
			return (i);
		tmp = tmp->next;
		++i;
	}
	return (i);
}

int	get_pos_to_place(t_stack *stack, int element)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	if (element > get_max(stack) || element < get_min(stack))
		return (get_pos_element(stack, get_min(stack)));
	tmp = stack;
	while (i < ft_stack_length(stack))
	{
		if (tmp->previous->value < element && element < tmp->value)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	get_best_move(t_stack *stack_a, t_stack *stack_b, t_cost *cost)
{
	int		best_move_elem;
	t_stack	*tmp;

	best_move_elem = stack_b->value;
	cost->best = count_move(stack_a, stack_b, best_move_elem);
	tmp = stack_b->next;
	while (tmp != stack_b)
	{
		cost->total = count_move(stack_a, stack_b, tmp->value);
		if (cost->total < cost->best)
		{
			cost->best = cost->total;
			best_move_elem = tmp->value;
		}
		tmp = tmp->next;
	}
	return (best_move_elem);
}
