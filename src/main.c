/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:10:45 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/11/12 03:37:47 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**args;
	
	if (argc == 2)
		args = ft_split(argv[1], ' '); // free
	else
		args = argv;
 	if (checker_arg(args, argc) != 0)
		return (1);
	init_stack(argv, argc, &a);
	return (0);
}
