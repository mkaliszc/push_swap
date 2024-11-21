/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:49:39 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/21 02:14:10 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_push_swap(char **args, int size, t_stack **stack_a, t_stack **stack_b)
{
	t_chunk	*chunks;
	int		*array;

	array = ft_init_array(args, size);
	chunks = ft_create_chunk(array, size);
	ft_chunk_sort(stack_a, stack_b, chunks);
	// Turk sort
}
