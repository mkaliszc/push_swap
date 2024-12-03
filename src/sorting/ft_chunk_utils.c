/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 16:27:02 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/03 16:27:25 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wich_cst(int size)
{
	if (size <= 200)
		return (4);
	else
		return (8);
}

t_chunk	*ft_create_chunk(int *array, int size)
{
	t_chunk	*chunk;

	chunk = malloc(sizeof(t_chunk));
	if (chunk == NULL)
		return (NULL);
	chunk->values = array;
	chunk->middle = (size / 2);
	chunk->cst_set = ft_wich_cst(size);
	chunk->chunk_size = size / chunk->cst_set;
	chunk->start = chunk->middle - chunk->chunk_size;
	chunk->end = chunk->middle + chunk->chunk_size;
	chunk->total_size = size;
	return (chunk);
}