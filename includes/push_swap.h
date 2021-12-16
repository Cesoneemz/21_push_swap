/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:57:44 by wlanette          #+#    #+#             */
/*   Updated: 2021/12/16 18:05:37 by wlanette         ###   ########.fr       */
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

/* VALIDATION */

t_bool			ft_validate_data(int argc, char **argv);

/* UTILS */

int				ft_strcmp(char *s1, char *s2);
long long int	ft_long_atoi(const char *str);

#endif