/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 02:35:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/08 03:44:38 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/libft.h"

int	check_overflows(char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		if ((sign == 1 && nbr > INT_MAX)
		|| (sign == -1 && nbr < INT_MIN))
			return(0);
		i++;
	}
	
}

int	is_valid(char *arg)
{
	int	j;

	j = 0;
	while (ft_isspace(arg[j]) == 1)
		j++;
	if (!arg[j])
		return (0);
	if (arg[j] == '+' || arg[j] == '-')
		j++;
	while (arg[j] != '\0')
	{
		if (ft_isdigit(arg[j]) == 0)
			return (0);
		j++;
	}
	return (1);
}

int	checker_arg(char **args, int nbr_of_args)
{
	int	i;

	i = 1;
	if (args == NULL)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (nbr_of_args < 2)
		return (ft_putstr_fd("Error\n", 2), 1);
	while (i < nbr_of_args)
	{
		if (is_valid(args[i]) == 0 || check_oveflows(args[i]) == 0)
			return (ft_putstr_fd("Error\n", 2), 1);
		i++;
	}
	return (0);
}
