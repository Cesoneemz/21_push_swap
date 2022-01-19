/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:18:03 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/20 02:04:49 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int	ft_get_min_elem_in_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		min;

	tmp = stack;
	min = INT_MAX;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}

static void	ft_push_all_to_b(t_stacks *stacks)
{
	int		min;
	t_stack	*top;
	t_stack	*tmp;

	top = ft_top_stack(stacks->a);
	tmp = stacks->a;
	while (tmp)
	{
		min = ft_get_min_elem_in_stack(tmp);
		ft_put_number_on_top(stacks, min);
		ft_pb(&stacks->a, &stacks->b);
		tmp = stacks->a;
	}
}

static void	ft_push_all_to_a(t_stacks *stacks)
{
	int	size;

	size = stacks->size;
	while (size--)
		ft_pa(&stacks->a, &stacks->b);
}

void	ft_insertion_sort(t_stacks *stacks)
{
	size_t	chunks;

	chunks = stacks->size / 10;
	ft_push_all_to_b(stacks);
//	ft_push_all_to_a(stacks);
}
