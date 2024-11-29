/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:48:20 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/29 04:19:01 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	tmp = stack->next;
	min = stack->value;
	while (tmp != stack)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	tmp = stack->next;
	max = stack->value;
	while (tmp != stack)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	get_pos_element(t_stack *stack, int node)
{
	t_stack		*tmp;
	int			i;

	i = 0;
	tmp = stack->next;
	while (tmp->next != stack)
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
		return (get_pos_element(stack, get_min(stack)) - 1);
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

int	count_move(t_stack *stack_a, t_stack *stack_b, int elem)
{
	int	count;
	int	index;

	count = 1;
	index = get_pos_element(stack_b, elem);
	if (index > 1 && index > (ft_stack_length(stack_b) / 2))
		count += ft_stack_length(stack_b) - index - 1;
	else if (index > 1 && index <= (ft_stack_length(stack_b) / 2))
		count += index - 1;
	index = get_pos_to_place(stack_a, elem);
	if (index > 1 && index > (ft_stack_length(stack_a) / 2))
		count += ft_stack_length(stack_a) - index - 1;
	else if (index > 1 && index <= (ft_stack_length(stack_a) / 2))
		count += index - 1;
	return (count);
}

int	 get_best_move(t_stack *stack_a, t_stack *stack_b, t_cost *cost)
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

int	opti_rotate(t_stack **a, t_stack **b, int pos_a, int pos_b)
{
	int	count;
	
	count = 0;
	if (pos_a <= ft_stack_length(*a) / 2 && pos_b <= ft_stack_length(*b) / 2)
	{
		while (count < pos_a && count < pos_b)
		{
			rotate_r(a, b);
			count++;
		}
	}
	else if (pos_a > ft_stack_length(*a) / 2 && pos_b > ft_stack_length(*b) / 2)
	{
		while (count < (ft_stack_length(*a) - pos_a)
			&& count < (ft_stack_length(*b) - pos_b))
		{
			reverse_rotate_r(a, b);
			count++;
		}
	}
	return (count);
}

static t_stack	*r_stack_a(t_stack *stack_a, int target_pos, int nbr_of_r)
{
	int	len;

	len = ft_stack_length(stack_a);
	if (target_pos <= len / 2)
	{
		while (nbr_of_r < target_pos)
		{
			rotate_a(&stack_a);
			nbr_of_r++;
		}
	}
	else
	{
		while (nbr_of_r < (len - target_pos))
		{
			reverse_rotate_a(&stack_a);
			nbr_of_r++;
		}
	}
	return (stack_a);
}

void	rotate_and_push(t_stack **stack_a, t_stack **stack_b, int element)
{
	int		get_pos_a;
	int		get_pos_b;
	int		nbr_of_rotate;
	
	get_pos_a = get_pos_to_place(*stack_a, element);
	get_pos_b = get_pos_element(*stack_b, element);
	nbr_of_rotate = opti_rotate(stack_a, stack_b, get_pos_a, get_pos_b);
	while ((*stack_b)->value != element)
	{
		if (get_pos_b <= ft_stack_length(*stack_b) / 2)
			rotate_b(stack_b);
		else
			reverse_rotate_b(stack_b);
	}
	*stack_a = r_stack_a(*stack_a, get_pos_a, nbr_of_rotate);
	push_a(stack_a, stack_b);
}

void	ft_turk_sort(t_stack **stack_a, t_stack **stack_b, t_cost *cost)
{
	int		best_element;
	
	while (*stack_b)
	{
		best_element = get_best_move(*stack_a, *stack_b, cost);
		rotate_and_push(stack_a, stack_b, best_element);
	}
}

