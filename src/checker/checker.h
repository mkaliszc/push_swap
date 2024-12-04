/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:41:22 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/12/04 18:03:24 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../octolib/include/libft.h"

/* push swap function's */

typedef struct s_stack
{
	int				value;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

void	ft_free_stack(t_stack **stack);
void	ft_free_tab(char **tab, size_t j);

// rules

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_s(t_stack **stack_a, t_stack **stack_b);

void	push_b(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);

void	rotate_a(t_stack	**stack_a);
void	rotate_b(t_stack	**stack_b);
void	rotate_r(t_stack	**stack_a, t_stack	**stack_b);

void	reverse_rotate_a(t_stack	**stack_a);
void	reverse_rotate_b(t_stack	**stack_b);
void	reverse_rotate_r(t_stack	**stack_a, t_stack	**stack_b);

// parsing
int		checker_arg(char **args, int nbr_of_args);
int		is_sorted(t_stack **stack, int nbr_of_args);
int		*ft_init_array(char **args, int nbr_of_args);

// stack related
t_stack	*init_stack(char **args, int nbr_args, t_stack **stack_a);
void	ft_stack_add_front(t_stack **lst, t_stack *new);
int		ft_stack_length(t_stack *stack);

#endif