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

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isalpha(int arg);
int		ft_isalnum(int arg);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_lstsize(t_list *lst);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_toupper(int c);

size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *str);
char	*ft_itoa(int n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*get_next_line(int fd);

void	ft_bzero(void *s, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);

t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* push swap function's */

typedef struct s_stack
{
	int				value;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

// rules

void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_s(t_stack **stack_a, t_stack **stack_b);

void	push_b(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);

void	rotate_a(t_stack	**stack_a);
void	rotate_b(t_stack	**stack_b);
void   	rotate_r(t_stack	**stack_a, t_stack	**stack_b);

void	reverse_rotate_a(t_stack	**stack_a);
void	reverse_rotate_b(t_stack	**stack_b);
void   	reverserotate_r(t_stack	**stack_a, t_stack	**stack_b);

// tab
char	**ft_split(char const *s, char c);
void	ft_free_tab(char **tab, size_t j);

// printf + pustr
int		ft_printf(const char *str, ...);
int		ft_putchar_m(int c);
int		ft_putstr_m(char *str);
int		ft_putptr(void *ptr);
int		ft_putint(int nbr);
int		ft_putint_unsigned(int nbr);
int		ft_puthexa_upper(unsigned long nb, int n);
int		ft_puthexa(unsigned long nb, int n);

void	ft_putstr_fd(char *s, int fd);

// parsing
int		checker_arg(char **args, int nbr_of_args);
int		ft_atoi(const char *str);
int		ft_isspace(int c);
int		ft_isdigit(int arg);
int		is_sorted(t_stack **stack, int nbr_of_args);

// stack related
t_stack	*init_stack(char **args, int nbr_of_args, t_stack **stack_a);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

#endif