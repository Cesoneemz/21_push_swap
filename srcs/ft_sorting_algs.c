/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting_algs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlanette <wlanette@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:38:00 by wlanette          #+#    #+#             */
/*   Updated: 2022/01/11 16:03:11 by wlanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort_2_elem(t_stacks *stacks)
{
	t_stack	*top;

	top = ft_top_stack(stacks->a);
	if (top->order > top->prev->order)
		ft_sa(&stacks->a);
}

static void	ft_sort_3_elem(t_stacks *stacks)
{
	while (stacks->a->order < stacks->a->next->order)
		ft_rra(&stacks->a);
	ft_sort_2_elem(stacks);
}

static void	ft_sort_4_or_5_elem(t_stacks *stacks)
{
	int		stack_size;
	int		median;
	t_stack	*top;

	median = stacks->size / 2;
	stack_size = stacks->size;
	while (stack_size > 3)
	{
		top = ft_top_stack(stacks->a);
		if (top->order > median)
			ft_ra(&stacks->a);
		else
		{
			ft_pb(&stacks->a, &stacks->b);
			stack_size--;
		}
	}
	ft_sort_3_elem(stacks);
	while (stacks->b)
		ft_pa(&stacks->a, &stacks->b);
	ft_sort_2_elem(stacks);
}

void	ft_sort_small_stack(t_stacks *stacks)
{
	if (stacks->size == 2)
		ft_sort_2_elem(stacks);
	else if (stacks->size == 3)
		ft_sort_3_elem(stacks);
	else if (stacks->size == 4 || stacks->size == 5)
		ft_sort_4_or_5_elem(stacks);
}

void	ft_sort_big_stack(int argc, t_stacks *stacks)
{
	int	stack_size;
	int	top_order;
	int	max_bits;
	int	k;
	int	j;

	stack_size = argc;
	max_bits = 0;
	k = -1;
	while ((stack_size >> max_bits) != 0)
		++max_bits;
	while (++k < max_bits)
	{
		j = 0;
		while (++j < stack_size)
		{
			top_order = ft_top_stack(stacks->a)->order;
			if (((top_order >> k) & 1) == 1)
				ft_ra(&stacks->a);
			else
				ft_pb(&stacks->a, &stacks->b);
		}
		while (stacks->b)
			ft_pa(&stacks->a, &stacks->b);
	}
}
