/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:57:44 by wlanette          #+#    #+#             */
/*   Updated: 2021/12/22 00:27:09 by wlanette         ###   ########.fr       */
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

/* STACKS INITIALIZATION */

t_stacks		*ft_create_stacks(int argc, char **argv, int *result);
t_stack			*ft_create_stack(int value);

/* VALIDATION */

t_bool			ft_validate_data(int argc, char **argv);
int				*ft_sort_str(int argc, char **argv);

/* UTILS */

int				ft_strcmp(char *s1, char *s2);
long long int	ft_long_atoi(const char *str);

/* STACK UTILS */

int				ft_get_stack_size(t_stack *stack);
t_stack			*ft_top_stack(t_stack *stack);
void			ft_pop_back(t_stack **stack);
void			ft_push_back(t_stack *stack, int data);

#endif