/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:10:45 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/18 16:37:24 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**handle_args(int argc, char **argv, int *size)
{
	char	**args;
	int		i;

	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (NULL);
		*size = 0;
		while (args[*size])
			(*size)++;
	}
	else
	{
		*size = argc - 1;
		args = malloc(sizeof(char *) * (*size + 1));
		if (!args)
			return (NULL);
		i = -1;
		while (++i < *size)
			args[i] = ft_strdup(argv[i + 1]);
		args[i] = NULL;
	}
	return (args);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		size;
	int		*array;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	args = handle_args(argc, argv, &size);
	if (args == NULL || !*args)
		return (free(args), ft_putstr_fd("Error\n", 2), 1);
	else if (checker_arg(args, size) != 0)
		return (ft_free_tab(args, size), 1);
	array = ft_init_array(args, size);
	init_stack(args, size, &stack_a);
	ft_free_tab(args, size);
	if (is_sorted(&stack_a, size) == 0)
		return (ft_free_stack(&stack_a), free(array), 0);
	push_swap(array, size, &stack_a, &stack_b);
	return (0);
}
