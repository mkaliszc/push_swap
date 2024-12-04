/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:19:52 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/04 18:17:52 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	do_op(t_stack **stack_a, t_stack **stack_b, char *op)
{
	if (ft_strcmp("sa\n", op))
		swap_a(stack_a);
	else if (ft_strcmp("sb\n", op))
		swap_b(stack_b);
	else if (ft_strcmp("ss\n", op))
		swap_s(stack_a, stack_b);
	else if (ft_strcmp("pa\n", op))
		push_a(stack_a, stack_b);
	else if (ft_strcmp("pb\n", op))
		push_b(stack_a, stack_b);
	else if (ft_strcmp("ra\n", op))
		rotate_a(stack_a);
	else if (ft_strcmp("rb\n", op))
		rotate_b(stack_b);
	else if (ft_strcmp("rr\n", op))
		rotate_r(stack_a, stack_b);
	else if (ft_strcmp("rra\n", op))
		reverse_rotate_a(stack_a);
	else if (ft_strcmp("rrb\n", op))
		reverse_rotate_b(stack_b);
	else if (ft_strcmp("rrr\n", op))
		reverse_rotate_r(stack_a, stack_b);
	else
		return(0);
	return (1);
}

void	check_operations(t_stack **stack_a, t_stack **stack_b)
{
	char	*operation;
	int		test;
	
	while (1)
	{
		operation = get_next_line(0);
		if (!operation)
			break ;
		test = do_op(stack_a, stack_b, operation);
		if (test == 0)
		{
			free(operation);
			ft_free_stack(stack_a);
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		free(operation);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	args = handle_args(argc, argv, &size);
	if (!args)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (checker_arg(args, size) != 0)
		return (ft_free_tab(args, size), 1);
	init_stack(args, size, &stack_a);
	ft_free_tab(args, size);
	if (is_sorted(&stack_a, size) == 0)
		return (ft_free_stack(&stack_a), ft_printf("OK\n"), 0);
	check_operations(&stack_a, &stack_b);
	if (is_sorted(&stack_a, size) == 0)
		return (ft_free_stack(&stack_a), ft_printf("OK\n"), 0);
	else 
		return (ft_free_stack(&stack_a), ft_printf("KO\n", 0));
	return (0);
}
