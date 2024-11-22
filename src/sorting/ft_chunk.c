/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:11:19 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/22 06:17:51 by mkaliszc         ###   ########.fr       */
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

	i = -1;
	size = args_nbr / ft_sqrt(args_nbr);
	values = malloc(sizeof(int *) * chunks->nbr_of_chunks);
	if (values == NULL)
		return (NULL);
	while (++i < chunks->nbr_of_chunks)
	{
		values[i] = ft_fill_values(array, size, i * size);
		if (values[i] == NULL)
			return (ft_free_values(values, i, chunks), NULL);
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
	int		remain;

	remain = args_nbr % ft_sqrt(args_nbr);
	chunks = malloc(sizeof(t_chunk) * (ft_sqrt(args_nbr) + (remain > 0)));
	if (chunks == NULL)
		return (NULL);
	chunks->nbr_of_chunks = ft_sqrt(args_nbr + (remain > 0));
	chunks->mid_start = chunks->nbr_of_chunks / 2;
	chunks->mid_end = chunks->mid_start + 1;
	chunks->values = ft_init_values(array, args_nbr, chunks, remain);
	if (chunks->values == NULL)
		return (NULL);
	return (chunks);
}
