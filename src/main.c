/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:10:45 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/13 02:21:46 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
		args = ft_split(argv[1], ' '); // free
	else
		args = argv;
	if (checker_arg(args, argc) != 0)
		return (1);
	init_stack(argv, argc, &stack_a);
	if (is_sorted(&stack_a, argc))
		return (0);
	return (0);
}
