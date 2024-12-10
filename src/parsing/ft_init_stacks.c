/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:57:14 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/10 20:39:13 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*pos;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	pos = *lst;
	while (pos -> next != *lst && pos->next)
		pos = pos -> next;
	pos -> next = new;
	new -> previous = pos;
}

t_stack	*ft_new_node(int value)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node -> value = value;
	node -> next = NULL;
	node -> previous = NULL;
	return (node);
}

t_stack	*init_stack(char **args, int nbr_args, t_stack **stack_a)
{
	t_stack	*node;
	t_stack	*first;
	t_stack	*last;
	int		i;

	i = 0;
	first = NULL;
	last = NULL;
	while (i < nbr_args)
	{
		node = ft_new_node(ft_atoi(args[i]));
		if (!node)
			return (NULL);
		ft_stack_add_back(stack_a, node);
		if (!first)
			first = node;
		last = node;
		i++;
	}
	last->next = first;
	first->previous = last;
	*stack_a = first;
	return (first);
}
