/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 00:11:19 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/20 04:01:54 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_fill_tab(int *array, int size, int index, int args_nbr, int nbr_of_chunks)
{
	
}

int	**ft_init_chunks(int *array, int nbr_of_args)
{
	int	**chunks;
	int	chunks_size;
	int	nbr_of_chunks;
	int	remainder;
	int	i;

	nbr_of_chunks = ft_sqrt(nbr_of_args);
	remainder = nbr_of_args % nbr_of_chunks;
	chunks_size = nbr_of_args / nbr_of_chunks;
	if (remainder == 0)
	{
		chunks = malloc(sizeof(int *) * nbr_of_chunks);
		if (chunks == NULL)
			return (NULL);
	}
	else
	{
		chunks = malloc(sizeof(int *) * (nbr_of_chunks + 1));
		if (chunks == NULL)
			return (NULL);
	}
	i = -1;
	while (++i < nbr_of_chunks + remainder)
		chunks[i] = ft_fill_tab(array, chunks_size, i);
	if (remainder != 0)
		chunks[i] = ft_fill_tab(array, chunks_size, i, nbr_of_args, nbr_of_chunks);
}

// voir header pour finish plus optimisation