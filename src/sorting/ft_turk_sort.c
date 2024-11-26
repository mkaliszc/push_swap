/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 00:48:20 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/26 22:15:51 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* pour le turk sort on va prendre un element de la stack_b, trouver l'espace qui lui correspond a l'aide des index 
(chercher l'index grand le plus proche et l'index petit le plus proche), puis tout remettre en ordre avec l'index 0 en head*/

t_stack	*find_gap(t_stack **stack, t_stack *element)
{
	t_stack	*gap;
	t_stack	*tmp;
	int		full;

	tmp = *stack;
	full = 0;
 	while (full < ft_stack_length(*stack))
	{
		tmp = tmp->next;
		if (tmp->index < element->index)
			gap = tmp->next;
		full++;
	}
	return (gap);
}

int	nbr_of_ra(t_stack **stack, t_stack *gap)
{
	t_stack	*pos;
	int		count_r;
	int		count_rr;

	count_r = 0;
	count_rr = 0;
	pos = *stack;
	while (pos != gap)
	{
		pos = pos->previous;
		count_r++;
	}
/* 	pos = *stack;
	while (pos != gap)
	{
		pos = pos->next;
		count_rr++;
	}
	if (count_rr < count_r)
	{
		returnn (count_rr)
	} */
	return(count_r);
}

int	nbr_of_rb(t_stack **stack, t_stack *element)
{
	t_stack	*pos;
	int		count_r;
	int		count_rr;

	count_r = 0;
	count_rr = 0;
	pos = *stack;
	while (pos != element)
	{
		pos = pos->previous;
		count_r++;
	}
/* 	pos = *stack;
	while (pos != eleement)
	{
		pos = pos->next;
		count_rr++;
	}
	if (count_rr < count_r)
	{
		returnn (count_rr)
	} */
	return(count_r);
}

void	rotate_and_push(t_stack **stack_a, t_stack **stack_b, t_stack *element)
{
  	while (*stack_a != element->target_pos && *stack_b != element)
		rotate_r(stack_a, stack_b);
	while (*stack_a != element->target_pos)
		rotate_a(stack_a);
	while (*stack_b != element)
		rotate_b(stack_b);
	push_a(stack_a, stack_b);
}

void	ft_turk_sort(t_stack **stack_a, t_stack **stack_b, t_cost *cost)
{
	t_stack	*best_element;
	t_stack	*element;
	int		full;

	while (*stack_b)
	{
		element = *stack_b;
		full = 0;
		cost->best = INT_MAX;
		while (full < ft_stack_length(*stack_b))
		{
			element->target_pos = find_gap(stack_a, element);
			cost->nbr_op_a = nbr_of_ra(stack_a, element->target_pos);
			cost->nbr_op_b = nbr_of_rb(stack_b, element);
			cost->total = cost->nbr_op_a + cost->nbr_op_b;
			if (cost->total < cost->best)
			{
				best_element = element;
				cost->best = cost->total;
			}
			element = element->next;
			full++;
		}
		//ft_printf("value : %d --> target : %d\n", best_element->value, best_element->target_pos->value);
		rotate_and_push(stack_a, stack_b, best_element);
	}
}
/*Compter le nombre de rotations qu'il faut faire dans A et dans B (chercher une methode avec les reverse et rr ?)
puis ajouter l'addition dans le total_cost
si le total est inferieur au best mettre a jour le best element et le best
puis avancer dans la stack*/