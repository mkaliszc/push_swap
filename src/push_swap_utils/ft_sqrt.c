/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 23:58:23 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/20 03:26:23 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int	return_value;

	return_value = 1;
	while (return_value * return_value < nb)
		return_value++;
	if (return_value * return_value == nb)
		return (return_value);
	else
		return (return_value - 1);
}
