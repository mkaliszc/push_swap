/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 09:36:50 by mkaliszc          #+#    #+#             */
/*   Updated: 2024/10/03 09:36:50 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../src/octolib/include/libft.h"

/* push swap function's */

typedef struct s_stack
{
	int				value;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

typedef struct s_cost
{
	int	total;
	int	best;
}					t_cost;

typedef struct s_chunk
{
	int	*values;
	int	start;
	int	end;
	int	chunk_size;
	int	middle;
	int	cst_set;
	int	total_size;
}			t_chunk;

void	ft_free_all(int *array, t_chunk *chunk, t_stack **s_a);
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

// sort related
void	case_three(t_stack **stack);
t_chunk	*ft_create_chunk(int *array, int size);
void	ft_chunk_sort(t_chunk *chunk, t_stack **stack_a, t_stack **stack_b);
void	ft_turk_sort(t_stack **stack_a, t_stack **stack_b, t_cost *cost);
void	push_swap(int *array, int size, t_stack **stack_a, t_stack **stack_b);

// utiles

int		get_pos_element(t_stack *stack, int node);
int		get_pos_to_place(t_stack *stack, int element);
int		get_best_move(t_stack *stack_a, t_stack *stack_b, t_cost *cost);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		count_move(t_stack *stack_a, t_stack *stack_b, int elem);
size_t	ft_strlen(const char *s);

#endif