/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:57:14 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/22 06:14:33 by mkaliszc         ###   ########.fr       */
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
	while (pos -> next != NULL)
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
	t_stack	*pos;
	int		i;
	int		num;

	i = 0;
	pos = *stack_a;
	while (i < nbr_of_args)
	{
		num = ft_atoi(args[i]);
		node = ft_new_node(num);
		if (!node)
			return (NULL); // fonction free lst
		ft_lstadd_back(stack_a, node);
		if (i == 1)
			pos = node;
		i++;
	}
	pos->previous = node;
	node->next = pos;
	return (pos);
}
