/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 17:19:52 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/05 18:04:59 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* void print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *current_a;
    t_stack *current_b;
    int first_a = 1;
    int first_b = 1;
    printf("\n=== Stack State ===\n");
    // Print Stack A
    printf("Stack A: ");
    if (stack_a)
    {
        current_a = stack_a;
        do {
            if (!first_a)
                printf(" -> ");
            printf("%d", current_a->value);
            first_a = 0;
            current_a = current_a->next;
        } while (current_a != stack_a);
    }
    else
        printf("(empty)");
    printf("\n");
    printf("Stack B: ");
    if (stack_b)
    {
        current_b = stack_b;
        do {
            if (!first_b)
                printf(" -> ");
            printf("%d", current_b->value);
            first_b = 0;
            current_b = current_b->next;
        } while (current_b != stack_b);
    }
    else
        printf("(empty)");
    printf("\n================\n\n");
} */

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
	if (!ft_strncmp("sa\n", op, 3))
		swap_a(stack_a);
	else if (!ft_strncmp("sb\n", op, 3))
		swap_b(stack_b);
	else if (!ft_strncmp("ss\n", op, 3))
		swap_s(stack_a, stack_b);
	else if (!ft_strncmp("pb\n", op, 3))
		push_b(stack_a, stack_b);
	else if (!ft_strncmp("pa\n", op, 3))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp("rra\n", op, 4))
		reverse_rotate_a(stack_a);
	else if (!ft_strncmp("rrb\n", op, 4))
		reverse_rotate_b(stack_b);
	else if (!ft_strncmp("rrr\n", op, 4))
		reverse_rotate_r(stack_a, stack_b);
	else if (!ft_strncmp("ra\n", op, 3))
		rotate_a(stack_a);
	else if (!ft_strncmp("rb\n", op, 3))
		rotate_b(stack_b);
	else if (!ft_strncmp("rr\n", op, 3))
		rotate_r(stack_a, stack_b);
	else
		return (0);
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
