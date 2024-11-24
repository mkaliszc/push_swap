/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 21:32:11 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/23 22:08:46 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*pos;
	t_stack	*tmp;

	pos = *stack;
	tmp = NULL;
	if (!stack || !*stack)
		return ;
	(*stack)->previous->next = NULL;
	while (pos != NULL)
	{
		tmp = pos->next;
		free(pos);
		pos = tmp;
	}
}

void	ft_free_chunks(t_chunk *chunks)
{
	int	i;

	i = 0;
	while (i < chunks->nbr_of_chunks)
	{
		free(chunks->values[i]);
		i++;
	}
	free(chunks->values);
	free(chunks);
}

void	ft_free_all(char **args, t_chunk *chunk, t_stack **s_a, t_stack **s_b)
{
	int	size;

	size = 0;
	while (args[size] != NULL)
		size++;
	ft_free_tab(args, size);
	ft_free_chunks(chunk);
	ft_free_stack(s_a);
	ft_free_stack(s_b);
}