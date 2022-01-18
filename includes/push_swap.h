/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:57:44 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/18 13:44:08 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				order;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		size;
}				t_stacks;

typedef enum s_bool
{
	false = 0,
	true = 1
}				t_bool;

/* SEPARATE */

char			**ft_argv_separate(int argc, char **argv);
int				ft_countword(char **split_argv);

/* STACKS INITIALIZATION */

t_stacks		*ft_create_stacks(int argc, char **argv, int *result);
t_stack			*ft_create_stack(int value);

/* VALIDATION */

t_bool			ft_validate_data(int argc, char **argv);
int				*ft_sort_str(int argc, char **argv);
t_bool			ft_check_only_spaces(char *str);

/* UTILS */

int				ft_strcmp(char *s1, char *s2);
long int		ft_long_atoi(const char *str);
t_bool			ft_is_number(char *num);

/* STACK UTILS */

int				ft_get_stack_size(t_stack *stack);
t_stack			*ft_top_stack(t_stack *stack);
void			ft_pop_back(t_stack **stack);
void			ft_push_back(t_stack *stack, int data);

/* OPERATIONS */

void			ft_sa(t_stack **stack, t_bool writeable);
void			ft_sb(t_stack **stack, t_bool writeable);
void			ft_ss(t_stack **a, t_stack **b);

void			ft_pa(t_stack **a, t_stack **b);
void			ft_pb(t_stack **a, t_stack **b);

void			ft_ra(t_stack **a, t_bool writeable);
void			ft_rb(t_stack **b, t_bool writeable);
void			ft_rr(t_stack **a, t_stack **b);

void			ft_rra(t_stack **a, t_bool writeable);
void			ft_rrb(t_stack **b, t_bool writeable);
void			ft_rrr(t_stack **a, t_stack **b);

/* SORTING ALGORITHMS */

void			ft_sort_small_stack(t_stacks *stacks);
void			ft_sort_big_stack(int argc, t_stacks *stacks);
void			ft_insertion_sort(t_stacks *stacks);

/* FREE ALL */

void			ft_free_stacks(t_stacks **stacks);
void			ft_free_args(int argc, char **argv);

#endif