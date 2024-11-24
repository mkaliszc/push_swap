/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:11:19 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/24 00:07:17 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_values(int **values, int nbr_of_chunks, t_chunk *chunk)
{
	while (0 < nbr_of_chunks)
	{
		free(values[nbr_of_chunks]);
		nbr_of_chunks--;
	}
	free(values);
	free(chunk);
}

int	*ft_fill_values(int *array, int size, int index)
{
	int	*chunk;
	int	i;

	chunk = malloc(sizeof(int) * size);
	if (chunk == NULL)
		return (free(chunk), NULL);
	i = 0;
	while (i < size)
	{
		chunk[i] = array[index + i];
		i++;
	}
	return (chunk);
}

int	**ft_init_values(int *array, int args_nbr, t_chunk *chunks, int remain)
{
	int	**values;
	int	size;
	int	i;

	i = 0;
	size = args_nbr / ft_sqrt(args_nbr);
	values = malloc(sizeof(int *) * chunks->nbr_of_chunks);
	if (values == NULL)
		return (NULL);
	while (i < chunks->nbr_of_chunks)
	{
		values[i] = ft_fill_values(array, size, i * size);
		if (values[i] == NULL)
			return (ft_free_values(values, i, chunks), NULL);
		i++;
	}
	if (remain)
	{
		values[i] = ft_fill_values(array, remain, i * size);
		if (values[i] == NULL)
			return (ft_free_values(values, i, chunks), NULL);
	}
	return (values);
}

t_chunk	*ft_create_chunk(int *array, int args_nbr)
{
	t_chunk	*chunks;
	int		size;
	int		remain;
	int		i;

	i = -1;
	size = args_nbr / ft_sqrt(args_nbr);
	remain = args_nbr % ft_sqrt(args_nbr);
	chunks = malloc(sizeof(t_chunk));
	if (chunks == NULL)
		return (NULL);
	chunks->nbr_of_chunks = ft_sqrt(args_nbr + (remain > 0));
	chunks->mid_start = chunks->nbr_of_chunks / 2;
	chunks->mid_end = chunks->mid_start;
	chunks->chunks_sizes = malloc(sizeof(int) * chunks->nbr_of_chunks);
	if (!chunks->chunks_sizes)
		return (NULL);
	while (++i < chunks->nbr_of_chunks - 1)
		chunks->chunks_sizes[i] = size;
	if (remain)
		chunks->chunks_sizes[chunks->nbr_of_chunks - 1] = remain;
	else
		chunks->chunks_sizes[chunks->nbr_of_chunks - 1] = size;
	chunks->values = ft_init_values(array, args_nbr, chunks, remain);
	if (chunks->values == NULL)
		return (NULL);
	return (chunks);
}
