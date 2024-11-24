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

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <ctype.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

/* push swap function's */

typedef struct s_stack
{
	int				value;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

typedef struct s_cost
{
	int	nbr_op_a;
	int	nbr_op_b;
	int	total;
	int	best;
}					t_cost;


typedef struct s_chunk
{
	int	**values;
	int	mid_start;
	int	mid_end;
	int	nbr_of_chunks;
	int	*chunks_sizes;
}			t_chunk;

void	ft_free_all(char **args, t_chunk *chunk, t_stack **s_a, t_stack **s_b);

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

// tab
char	**ft_split(char const *s, char c);
void	ft_free_tab(char **tab, size_t j);
char	*ft_strdup(const char *str);

// printf + pustr
int		ft_printf(const char *str, ...);
int		ft_putchar_m(int c);
int		ft_putstr_m(char *str);
int		ft_putptr(void *ptr);
int		ft_putint(int nbr);
int		ft_putint_unsigned(int nbr);
int		ft_puthexa_upper(unsigned long nb, int n);
int		ft_puthexa(unsigned long nb, int n);
int		ft_toupper(int c);

void	ft_putstr_fd(char *s, int fd);

// parsing
int		checker_arg(char **args, int nbr_of_args);
int		ft_atoi(const char *str);
int		ft_isspace(int c);
int		ft_isdigit(int arg);
int		is_sorted(t_stack **stack, int nbr_of_args);
int		*ft_init_array(char **args, int nbr_of_args);

// stack related
t_stack	*init_stack(char **args, int nbr_of_args, t_stack **stack_a);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
int		ft_stack_length(t_stack *stack);

// sort related
void	case_three(t_stack **stack);
t_chunk	*ft_create_chunk(int *array, int args_nbr);
void	ft_chunk_sort(t_stack **stack_a, t_stack **stack_b, t_chunk *tab);
void	ft_turk_sort(t_stack **stack_a, t_stack **stack_b, t_cost *cost);
void	push_swap(char **args, int size, t_stack **stack_a, t_stack **stack_b);

// utiles

size_t	ft_strlen(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int		ft_sqrt(int nb);
char	*ft_strchr(const char *str, int c);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

#endif