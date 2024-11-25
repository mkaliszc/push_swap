/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:57:14 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/24 19:49:49 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_stack **lst, t_stack *new)
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

t_stack	*init_stack(char **args, int nbr_of_args, t_stack **stack_a)
{
	t_stack	*node;
	t_stack	*first;
	t_stack	*last;
	int		i;

	i = 0;
	first = NULL;
	last = NULL;
	while (i < nbr_of_args)
	{
		node = ft_new_node(ft_atoi(args[i]));
		if (!node)
			return (NULL); // fonction free lst
		ft_lstadd_back(stack_a, node);
		if (!first)
		{
			first = node;
			*stack_a = first;
		}
		last = node;
		i++;
	}
	if (first && last)
	{
		last->next = first;
		first->previous = last;
	}
	return (first);
}
