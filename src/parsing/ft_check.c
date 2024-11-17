/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 02:35:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/17 20:54:58 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		if ((nbr * sign > 2147483647 || nbr * sign < -2147483648))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid(char *arg)
{
	int	j;

	j = 0;
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

int	compare_numbers(char *str1, char *str2)
{
	long	num1;
	long	num2;

	num1 = ft_atoi(str1);
	num2 = ft_atoi(str2);
	return (num1 == num2);
}

int	ft_check(char **args, int nbr_of_args)
{
	int		i;
	int		j;

	i = 0;
	while (i < nbr_of_args)
	{
		j = 1;
		if (is_valid(args[i]) == 0 || check_overflows(args[i]) == 0)
			return (ft_putstr_fd("Error\n", 2), 1);
		while (j < i)
		{
			if (compare_numbers(args[j], args[i]))
				return (ft_putstr_fd("Error\n", 2), 1);
			j++;
		}
		i++;
	}
	return (0);
}

int	checker_arg(char **args, int nbr_of_args)
{
	int		check;

	if (nbr_of_args < 2)
		return (1);
	if (nbr_of_args == 2)
	{
		check = ft_check(args, nbr_of_args);
		return (check);
	}
	else
	{
		check = ft_check(args, nbr_of_args);
		return (check);
	}
}
