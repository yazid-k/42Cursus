/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekadiri <ekadiri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:31:40 by ekadiri           #+#    #+#             */
/*   Updated: 2023/01/24 20:11:34 by ekadiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*stack;
	int	len;
	int	max_size;
}				t_stack;

//LIBFT
int		ft_printf(const char *s, ...);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(char const *str, char const *to_find, size_t len);
char	*get_next_line(int fd);
int		ft_strncmp(char const *s1, char const *s2, size_t n);

//PUSH_SWAP
	//Parsing
int		str_isnumber(char *str);
int		check_args(char **av);
int		check_duplicates(char **av);

	//Utils
t_stack	init_stack(char **av, int empty);
void	print_stack(t_stack s);
int		min_index(t_stack s);
int		max_index(t_stack s);
void	put_on_top(t_stack s, int index, char c);
int		is_sorted(t_stack s);
int		min(int a, int b);
int		max(int a, int b);
int		cost(t_stack s, int index);
int		t_cost(t_stack s_a, int a, t_stack s_b, int b);
int		index_to_insert(t_stack s, int n);
int		*min_cost_indexes(t_stack a, t_stack b);
int		get_index(t_stack s, int n);

	//Instructions
void	swap(t_stack s, char c);
void	rotate(t_stack s, char c);
void	reverse_rotate(t_stack s, char c);
void	push(t_stack *out, t_stack *in, char c);
void	ss(t_stack stack1, t_stack stack2);
void	rr(t_stack stack1, t_stack stack2, int i);
void	rrr(t_stack stack1, t_stack stack2, int i);

	//Solve
void	solve3(t_stack s);
void	insert_sort(t_stack a, t_stack b);
void	sort(t_stack a, t_stack b);

#endif
