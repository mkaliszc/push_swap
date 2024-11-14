/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:10:45 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/13 23:47:08 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	size = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' '); // free
		while (args[size] != NULL)
			size++;
	}
	else
	{
		args = argv;
		size = argc - 1;
	}
	if (checker_arg(args, size) != 0)
		return (1);
	init_stack(args, size, &stack_a);
	if (is_sorted(&stack_a, size) == 0)
		return (ft_printf("Sorted"), 0);
	return (0);
}
