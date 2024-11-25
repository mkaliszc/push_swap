/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:18:11 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/25 20:07:09 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct s_chunk
{
	int	*values;
	int	start;
	int	end;
	int	chunks_size;
	int	middle;
	int	cst_set;
}			t_chunk; */
int	ft_wich_cst(int	size)
{
	if (size <= 10)
		return (5);
	else if (size <= 150)
		return (8);
	else
		return (18);
}

t_chunk	*ft_create_chunk(int *array, int size)
{
	t_chunk	*chunk;

	chunk = malloc(sizeof(t_chunk));
	if (chunk == NULL)
		return (NULL);
	chunk->values = array;
	chunk->middle = size / 2;
	chunk->cst_set = ft_wich_cst(size);
	chunk->chunk_size = size / chunk->cst_set;
	chunk->start = chunk->values[chunk->middle - chunk->chunk_size];
	chunk->end = chunk->values[chunk->middle + chunk->chunk_size];
	return (chunk);
}