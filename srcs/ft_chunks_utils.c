/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:16:03 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/20 02:07:27 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static int	ft_get_max_elem_in_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		max;

	tmp = stack;
	max = INT_MIN;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

size_t	ft_get_chunks(t_stacks *stacks)
{
	size_t	res;

	res = stacks->size / 10;
	return (res);
}

void	ft_put_number_on_top(t_stacks *stacks, int n)
{
	int		top_data;
	t_stack	*tmp;

	top_data = stacks->size;
	tmp = stacks->a;
	while (top_data >= 0 && tmp->data != n)
	{
		tmp = tmp->next;
		top_data--;
	}
	if (top_data < 0)
		return ;
	else if (top_data < stacks->size / 2)
	{
		while (top_data--)
			ft_rra(&stacks->a, true);
	}
	else
	{
		top_data = stacks->size - top_data;
		while (top_data--)
			ft_ra(&stacks->a, true);
	}
}

int	closest_above(t_stacks *stacks, int n)
{
	int	k;
	int	i;

	if (stacks->size < 0 || n > ft_get_max_elem_in_stack(stacks->a))
		return (n);
	i = 0;
	k = ft_get_max_elem_in_stack(stacks->a);
	while (stacks->a)
	{
		if (stacks->a->data > n && stacks->a->data < k)
			k = a->array[i];
		stacks->a = stacks->a->next;
	}
	return (k);
}

void	ft_put_in_position(t_stacks *stacks)
{
	int		top;
	int		to_move;

	top = ft_top_stack(stacks->b)->data;
	to_move = closest_above(stacks, top);
	if (to_move == top && stacks->size)
		to_move = ft_get_min_elem_in_stack(stacks->a);
	ft_put_number_on_top(stacks->a, to_move);
	ft_pa(&stacks->a, &stacks->b);
}
