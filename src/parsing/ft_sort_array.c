/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:01:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/03 21:44:33 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_cut(int *tab, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	i = start - 1;
	j = start;
	pivot = tab[end];
	while (j < end)
	{
		if (tab[j] < pivot)
		{
			i++;
			ft_swap(&tab[i], &tab[j]);
		}
		j++;
	}
	ft_swap(&tab[i + 1], &tab[end]);
	return (i + 1);
}

void	ft_quick_sort(int *tab, int start, int end)
{
	int	pivot;

	if (start < end)
	{
		pivot = ft_cut(tab, start, end);
		ft_quick_sort(tab, start, pivot - 1);
		ft_quick_sort(tab, pivot + 1, end);
	}
}

int	*ft_init_array(char **args, int nbr_of_args)
{
	int	*array;
	int	i;

	i = 0;
	array = malloc(sizeof(int) * nbr_of_args);
	if (array == NULL)
		return (NULL);
	while (i < nbr_of_args)
	{
		array[i] = ft_atoi(args[i]);
		i++;
	}
	ft_quick_sort(array, 0, nbr_of_args - 1);
	return (array);
}
